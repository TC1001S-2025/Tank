#ifndef MOVEMENT_LOGIC_H
#define MOVEMENT_LOGIC_H

#include "MotorControl.h"

// Definición de comandos de movimiento
enum Movement {
    MOVE_FORWARD,   // Avanzar
    MOVE_BACK,      // Retroceder
    TURN_LEFT,      // Girar a la izquierda
    TURN_RIGHT,     // Girar a la derecha
    FULL_STOP       // Detenerse
};

// Clase para gestionar la lógica de movimiento
class MovementLogic {
public:
    void execute(Movement command, uint8_t speed);  // Ejecuta un comando de movimiento
};

#endif