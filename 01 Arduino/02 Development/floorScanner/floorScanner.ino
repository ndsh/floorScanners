/*
    · · · · · · · · · · · · · · · · · · · · ·

    floorScanner.ino
    https://github.com/ndsh/floorScanners

    Copyright (c) 2016 - 2021

    · · · · · · · · · · · · · · · · · · · · ·
*/

/*
#define SCORE 0 //Score in play
#define FULLREV 230400 //9:1 25600
#define PULSE_INTERVAL 50 //In milliseconds
#define TOTALPODS 7 //Total number of PODs in play

*/

#define DEBUG true

#define SENSOR_PIN A0
#define MOTOR_DIR_PIN 3
#define MOTOR_STEP_PIN 4
#define LED_PIN 5
#define ONBOARD_LED_PIN 13

#include "src/StateMachine.h"


StateMachine* stateMachine;

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void setup() {
  pinMode(ONBOARD_LED_PIN, OUTPUT);
  digitalWrite(ONBOARD_LED_PIN, HIGH);
  delay(1000);
      
  stateMachine = new StateMachine(SENSOR_PIN, LED_PIN);
}

void loop() {
  stateMachine->update();
}