#include <avr/wdt.h>
#include "MotorControl.h"
#include "MovementLogic.h"

MotorControl motorSystem;
MovementLogic movementManager;

void setup() {
    motorSystem.initialize();
    Serial.begin(9600);
    for(int step = 0; step < 3; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 3 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(TURN_LEFT, 100);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 100);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
}

void loop() {
    // Main control loop
}