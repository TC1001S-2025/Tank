#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

class MotorControl {
public:
    void initialize();  // Inicializa los pines del motor
    void control(bool leftDir, uint8_t leftSpeed, bool rightDir, uint8_t rightSpeed, bool enable);  // Controla los motores

private:
    // Definición de pines
    const uint8_t LEFT_PWM = 5;    // Pin PWM para el motor izquierdo
    const uint8_t RIGHT_PWM = 6;   // Pin PWM para el motor derecho
    const uint8_t LEFT_DIR = 8;    // Pin de dirección para el motor izquierdo
    const uint8_t RIGHT_DIR = 7;   // Pin de dirección para el motor derecho
    const uint8_t STANDBY = 3;     // Pin de standby (activación/desactivación)

public:
    static const uint8_t MAX_SPEED = 255;  // Velocidad máxima (0-255)
    enum Direction { FORWARD, BACKWARD, STOP };  // Direcciones posibles
};

#endif