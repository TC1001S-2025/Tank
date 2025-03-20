#include "MotorControl.h"

void MotorControl::initialize() {
    pinMode(LEFT_PWM, OUTPUT);
    pinMode(RIGHT_PWM, OUTPUT);
    pinMode(LEFT_DIR, OUTPUT);
    pinMode(RIGHT_DIR, OUTPUT);
    pinMode(STANDBY, OUTPUT);
    digitalWrite(STANDBY, LOW); // Start in standby mode
}

void MotorControl::control(bool leftDir, uint8_t leftSpeed, bool rightDir, uint8_t rightSpeed, bool enable) {
    if (!enable) {
        digitalWrite(STANDBY, LOW);
        return;
    }

    digitalWrite(STANDBY, HIGH); // Activate system

    // Control left motor
    digitalWrite(LEFT_DIR, leftDir ? HIGH : LOW);
    analogWrite(LEFT_PWM, constrain(leftSpeed, 0, MAX_SPEED));

    // Control right motor
    digitalWrite(RIGHT_DIR, rightDir ? HIGH : LOW);
    analogWrite(RIGHT_PWM, constrain(rightSpeed, 0, MAX_SPEED));
}