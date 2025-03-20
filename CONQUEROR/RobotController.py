import sys
import glob
import serial
import pyduinocli

class ArduinoSketchManager:
    """Maneja la creación y escritura del código de Arduino."""
    
    def __init__(self, sketch_path='commands/commands.ino'):
        self.sketch_path = sketch_path
        self.sketch_content = []
        self._initialize_sketch()

    def _initialize_sketch(self):
        """Crea la estructura inicial del sketch de Arduino."""
        self.sketch_content = [
            '#include <avr/wdt.h>',
            '#include "MotorControl.h"',
            '#include "MovementLogic.h"',
            '',
            'MotorControl motorSystem;',
            'MovementLogic movementManager;',
            '',
            'void setup() {',
            '    motorSystem.initialize();',
            '    Serial.begin(9600);'
        ]
        self._write_sketch()

    def _write_sketch(self):
        """Guarda el código del sketch en un archivo."""
        with open(self.sketch_path, 'w') as file:
            file.write("\n".join(self.sketch_content))

    def _append_to_sketch(self, lines):
        """Agrega líneas de código al sketch y guarda el archivo."""
        self.sketch_content.extend(lines)
        self._write_sketch()

    def add_movement(self, command, duration, power):
        """Agrega un bloque de movimiento al código."""
        movement_code = [
            f'    for(int step = 0; step < {duration}; step++) {{',
            f'        movementManager.execute({command}, {power});',
            '        Serial.print("Step: "); Serial.println(step);',
            '        delay(1000);',
            f'        if(step == {duration} - 1) {{',
            f'            movementManager.execute(FULL_STOP, {power});',
            '        }',
            '    }'
        ]
        self._append_to_sketch(movement_code)

    def finalize_sketch(self):
        """Cierra la estructura del código agregando loop()."""
        self._append_to_sketch([
            '}',
            '',
            'void loop() {',
            '    // Main control loop',
            '}'
        ])


class RobotController:
    """Controla los movimientos del robot y la carga del código a Arduino."""

    def __init__(self):
        self.sketch_manager = ArduinoSketchManager()

    def move_forward(self, duration=2, power=128):
        """Ordena al robot moverse hacia adelante."""
        self.sketch_manager.add_movement("MOVE_BACK", duration, power)


    def move_backward(self, duration=2, power=128):
        """Ordena al robot moverse hacia atrás."""
        self.sketch_manager.add_movement("MOVE_FORWARD", duration, power)

    def turn_left(self, duration=0.5, power=100):
        self.stop()
        """Ordena al robot girar a la izquierda."""
        self.sketch_manager.add_movement("TURN_LEFT", duration, power)
        

    def turn_right(self, duration=0.5, power=90):
        self.stop()
        """Ordena al robot girar a la derecha."""
        self.sketch_manager.add_movement("TURN_RIGHT", duration, power)
        

    def stop(self, duration = 1, power = 50):
        """Ordena al robot detenerse."""
        self.sketch_manager.add_movement("FULL_STOP", duration, power)

    def upload_sketch(self):
        """Compila y sube el código al Arduino."""
        arduino = pyduinocli.Arduino("arduino-cli")
        port = self._detect_serial_port()
        print(f"Puerto detectado: {port}")
        
        arduino.compile(fqbn="arduino:avr:uno", sketch=self.sketch_manager.sketch_path)
        arduino.upload(fqbn="arduino:avr:uno", sketch=self.sketch_manager.sketch_path, port=port)

    def _detect_serial_port(self):
        """Detecta automáticamente un puerto serial disponible."""
        platform_ports = {
            'win': [f'COM{i}' for i in range(1, 257)],
            'linux': glob.glob('/dev/tty[A-Za-z]*'),
            'darwin': glob.glob('/dev/tty.usb*')
        }
        ports = platform_ports.get(sys.platform.split('.')[0], [])

        for port in ports:
            if "debug" in port or "console" in port:
                continue
            try:
                with serial.Serial(port) as conn:
                    if conn.is_open:
                        return port
            except (OSError, serial.SerialException):
                continue
        raise RuntimeError("No se detectaron puertos seriales válidos.")