# Conqueror Robot Tank

## Descripción

Conqueror Robot Tank es un vehículo autónomo/controlado que tiene diferentes funciones y puede moverse
a distintas direcciones. Está compuesto por motores de oruga, sensores y un microcontrolador para realizar
diversas tareas como avanzar, retroceder, girar etc.

## Componentes y hardware

- Chasis: Robot Tank con orugas
- Microcontrolador : Rasperry Pi 4 / Arduino / ESP32
- Motores: Motores DC con Driver de control

  - Sensores:
    - Sensor Ultrasonico HC - SR04 (utilizado para la detección de objetos).
    - Sensor infrarrojo (utilizado para el siguimiento de la línea).

- Comunicación : Via WiFi / App Elegoo / Control
- Fuente de energía : Batería recargable (Lipo 11.1 V)

## Dependencias

Para ejecutar este proyecto, necesitas instalar las siguientes dependencias:

- **pyduinocli**: Para compilar y cargar el código en el Arduino.
- **pyserial**: Para detectar el puerto serial al que está conectado el Arduino.

Puedes instalar estas dependencias usando pip:

```bash
pip install pyduinocli pyserial
```

### `RobotController.py`

Este archivo contiene la clase `RobotController`, que maneja los movimientos del robot y la carga del código en el Arduino. También contiene la clase `ArduinoSketchManager`, que se encarga de generar el código de Arduino.

## Métodos de las Clases

### Clase `RobotController`

| Método          | Parámetros                | Descripción                                                                  |
| --------------- | ------------------------- | ---------------------------------------------------------------------------- |
| `move_forward`  | `duration=3`, `power=128` | Mueve el robot hacia adelante durante un tiempo con una potencia específica. |
| `move_backward` | `duration=3`, `power=128` | Mueve el robot hacia atrás durante un tiempo con una potencia específica.    |
| `turn_left`     | `duration=2`, `power=100` | Gira el robot a la izquierda durante un tiempo con una potencia específica.  |
| `turn_right`    | `duration=2`, `power=100` | Gira el robot a la derecha durante un tiempo con una potencia específica.    |
| `stop`          | `duration=2`, `power=50`  | Detiene el robot durante un tiempo con una potencia específica.              |
| `upload_sketch` | Ninguno                   | Compila y carga el código en el Arduino.                                     |

- Puedes cambiar los valores de los parámetros de la clase RobotController si así lo deseas.

### Clase `ArduinoSketchManager`

| Método            | Parámetros                     | Descripción                                                  |
| ----------------- | ------------------------------ | ------------------------------------------------------------ |
| `add_movement`    | `command`, `duration`, `power` | Agrega un bloque de movimiento al código de Arduino.         |
| `finalize_sketch` | Ninguno                        | Finaliza el código de Arduino agregando la función `loop()`. |

## Instalación

1. Clonar el repositorio: `git clone https://github.com/TC1001S-2025/Tank.git`. Este ya incluye las librerias del Conqueror Robot Tank.

2. Instalar las dependencias necesarias:

   - pip install pyduinocli
   - pip install pyserial

## Ejecución

1. Conecta tu Arduino al ordenador.
2. Ejecuta el archivo `demo1.py` para generar el código y cargarlo en el Arduino o puedes generar uno propio.

```bash
python demo1.py
```

## Notas

- Asegúrate de que el Arduino esté conectado y que el puerto serial esté correctamente configurado.
- El código generado se guarda en `commands/commands.ino`.
