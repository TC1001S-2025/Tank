#include <avr/wdt.h>
#include "MotorControl.h"
#include "MovementLogic.h"

MotorControl motorSystem;
MovementLogic movementManager;

void setup() {
    motorSystem.initialize();
    Serial.begin(9600);
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 0.5; step++) {
        movementManager.execute(TURN_RIGHT, 90);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 0.5 - 1) {
            movementManager.execute(FULL_STOP, 90);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 0.5; step++) {
        movementManager.execute(TURN_RIGHT, 90);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 0.5 - 1) {
            movementManager.execute(FULL_STOP, 90);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 0.5; step++) {
        movementManager.execute(TURN_RIGHT, 90);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 0.5 - 1) {
            movementManager.execute(FULL_STOP, 90);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 0.5; step++) {
        movementManager.execute(TURN_RIGHT, 90);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 0.5 - 1) {
            movementManager.execute(FULL_STOP, 90);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 0.5; step++) {
        movementManager.execute(TURN_RIGHT, 90);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 0.5 - 1) {
            movementManager.execute(FULL_STOP, 90);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
    for(int step = 0; step < 0.5; step++) {
        movementManager.execute(TURN_RIGHT, 90);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 0.5 - 1) {
            movementManager.execute(FULL_STOP, 90);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 2; step++) {
        movementManager.execute(MOVE_BACK, 128);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 2 - 1) {
            movementManager.execute(FULL_STOP, 128);
        }
    }
    for(int step = 0; step < 1; step++) {
        movementManager.execute(FULL_STOP, 50);
        Serial.print("Step: "); Serial.println(step);
        delay(1000);
        if(step == 1 - 1) {
            movementManager.execute(FULL_STOP, 50);
        }
    }
}

void loop() {
    // Main control loop
}