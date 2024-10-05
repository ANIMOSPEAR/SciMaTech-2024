#include <Servo.h>  // Include the Servo library

// Define the analog pin connected to the photoresistor
const int pr1 = A0;
const int lightThreshold = 800;  // Threshold to detect "light"

// Create servo objects for two servos
Servo servo1;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Attach the servos
  servo1.attach(9);

  // Start both servos rotating continuously in one direction
  servo1.write(180); 
}

void loop() {
  // Read the analog value from the photoresistor
  int pr1Value = analogRead(ldrPin);

  // Output the raw value to the Serial Monitor
  Serial.println(pr1Value);

  if (ldrValue > lightThreshold) {
    servo1.write(90);  // Stop position for continuous servos
  } else {
    servo1.write(180);  // Full speed for servo 1
  }
}