#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038; // Adjust according to your motor
const int steps = 1000;

// Creates an instance of stepper class
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');

        if (command == "close") {
            myStepper.setSpeed(10); 
            myStepper.step(steps);
            Serial.println("Motor goes left.");
        } 
        else if (command == "open") {
            myStepper.setSpeed(10);
            myStepper.step(-steps);
            Serial.println("Motor goes right.");
            delay(2000);
            myStepper.setSpeed(10);
            myStepper.step(steps);
            Serial.println("Motor closes.");
        } 
        else {
            Serial.println("Invalid command. Type 'open'.");
        }
        delay(500); // Delay to stabilize the input
    }
}
