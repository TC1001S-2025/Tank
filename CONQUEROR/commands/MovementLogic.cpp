#include "MovementLogic.h"
#include "MotorControl.h"

extern MotorControl motorSystem;

void MovementLogic::execute(Movement command, uint8_t speed) {
    switch (command) {
        case MOVE_FORWARD:
            motorSystem.control(MotorControl::FORWARD, speed, MotorControl::FORWARD, speed, true);
            break;
        case MOVE_BACK:
            motorSystem.control(MotorControl::BACKWARD, speed, MotorControl::BACKWARD, speed, true);
            break;
        case TURN_LEFT:
            motorSystem.control(MotorControl::FORWARD, speed, MotorControl::BACKWARD, speed, true);
            break;
        case TURN_RIGHT:
            motorSystem.control(MotorControl::BACKWARD, speed, MotorControl::FORWARD, speed, true);
            break;
        case FULL_STOP:
            motorSystem.control(MotorControl::STOP, 0, MotorControl::STOP, 0, true);
            break;
        default:
            // Comando no reconocido
            break;
    }
}