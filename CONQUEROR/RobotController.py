# Importaciones estándar 
import sys
import glob  

# Importaciones de terceros
import serial
import pyduinocli


class ArduinoSketchManager:
    """Maneja la creación y escritura del código de Arduino."""

    def __init__(
            self, sketch_path='commands/commands.ino'):
        """Inicializa el gestor de sketch de Arduino.

        Args:
            sketch_path (str): Ruta del archivo de sketch. Por defecto es 'commands/commands.ino'.
        """
        self.sketch_path=sketch_path
        self.sketch_content=[]
        self._initialize_sketch()

    def _initialize_sketch(
            self):
        """Crea la estructura inicial del sketch de Arduino."""
        self.sketch_content=[
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

    def _write_sketch(
            self):
        """Guarda el código del sketch en un archivo."""
        with open(self.sketch_path, 'w') as file:
            file.write("\n".join(self.sketch_content))

    def _append_to_sketch(
            self, lines):
        """Agrega líneas de código al sketch y guarda el archivo.

        Args:
            lines (list): Lista de líneas de código a agregar.
        """
        self.sketch_content.extend(lines)
        self._write_sketch()

    def add_movement(
            self, command, duration, power):
        """Agrega un bloque de movimiento al código.

        Args:
            command (str): Comando de movimiento (ej. "MOVE_FORWARD").
            duration (int): Duración del movimiento en pasos.
            power (int): Potencia del motor (0-255).
        """
        movement_code=[
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

    def finalize_sketch(
            self):
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

    def __init__(
            self):
        """Inicializa el controlador del robot."""
        self.sketch_manager = ArduinoSketchManager()

    def move_forward(
            self, duration=2, power=128):
        """Ordena al robot moverse hacia adelante.

        Args:
            duration (int): Duración del movimiento en segundos.
            power (int): Potencia del motor (0-255).
        """
        self.sketch_manager.add_movement("MOVE_BACK", duration, power)

    def move_backward(
            self, duration=2, power=128):
        """Ordena al robot moverse hacia atrás.

        Args:
            duration (int): Duración del movimiento en segundos.
            power (int): Potencia del motor (0-255).
        """
        self.sketch_manager.add_movement("MOVE_FORWARD", duration, power)

    def turn_left(
            self, duration=0.5, power=100):
        """Ordena al robot girar a la izquierda.

        Args:
            duration (float): Duración del giro en segundos.
            power (int): Potencia del motor (0-255).
        """
        self.stop()
        self.sketch_manager.add_movement("TURN_LEFT", duration, power)

    def turn_right(
            self, duration=0.5, power=90):
        """Ordena al robot girar a la derecha.

        Args:
            duration (float): Duración del giro en segundos.
            power (int): Potencia del motor (0-255).
        """
        self.stop()
        self.sketch_manager.add_movement("TURN_RIGHT", duration, power)

    def stop(
            self, duration=1, power=50):
        """Ordena al robot detenerse.

        Args:
            duration (int): Duración de la parada en segundos.
            power (int): Potencia del motor (0-255).
        """
        self.sketch_manager.add_movement("FULL_STOP", duration, power)

    def upload_sketch(
            self):
        """Compila y sube el código al Arduino."""
        arduino = pyduinocli.Arduino("arduino-cli")
        port = self._detect_serial_port()
        print(f"Puerto detectado: {port}")

        arduino.compile(fqbn="arduino:avr:uno", sketch=self.sketch_manager.sketch_path)
        arduino.upload(fqbn="arduino:avr:uno", sketch=self.sketch_manager.sketch_path, port=port)

    def _detect_serial_port(
            self):
        """Detecta automáticamente un puerto serial disponible.

        Returns:
            str: Puerto serial detectado.

        Raises:
            RuntimeError: Si no se detectan puertos seriales válidos.
        """
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
            except (OSError, serial.SerialException) as e:
                continue
        raise RuntimeError("No se detectaron puertos seriales válidos.")