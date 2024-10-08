#include <Servo.h>  // Include the Servo library

// Define the analog pins connected to the photoresistors
const int pr1 = A0;
const int pr2 = A1;
const int pr3 = A2;
const int pr4 = A3;
const int lightThreshold = 800;  // Threshold to detect "light"

// Create servo objects for four servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Variables for timing and state control for each target
bool targetHit1 = false, targetHit2 = false, targetHit3 = false, targetHit4 = false;
unsigned long hitTime1 = 0, hitTime2 = 0, hitTime3 = 0, hitTime4 = 0;
const unsigned long downTime = 5000;  // Target stays down for 5 seconds

void setup() {
  Serial.begin(9600);  // Start the serial communication

  // Attach the servos
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);

  // Start all targets up (0 degrees)
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

void loop() {
  // Read the analog values from the photoresistors
  int pr1Value = analogRead(pr1);
  int pr2Value = analogRead(pr2);
  int pr3Value = analogRead(pr3);
  int pr4Value = analogRead(pr4);

  // Output the raw values to the Serial Monitor
  Serial.print(pr1Value); Serial.print(" ");
  Serial.print(pr2Value); Serial.print(" ");
  Serial.print(pr3Value); Serial.print(" ");
  Serial.println(pr4Value);

  // Handle target 1
  if (pr1Value > lightThreshold && !targetHit1) {
    servo1.write(180);  // Move target down
    hitTime1 = millis();  // Record the time target 1 was hit
    targetHit1 = true;  // Mark that target 1 was hit
  }
  if (targetHit1 && (millis() - hitTime1 >= downTime)) {
    servo1.write(0);  // Move target back up after 5 seconds
    targetHit1 = false;  // Reset hit status
  }

  // Handle target 2
  if (pr2Value > lightThreshold && !targetHit2) {
    servo2.write(180);  // Move target down
    hitTime2 = millis();  // Record the time target 2 was hit
    targetHit2 = true;  // Mark that target 2 was hit
  }
  if (targetHit2 && (millis() - hitTime2 >= downTime)) {
    servo2.write(0);  // Move target back up after 5 seconds
    targetHit2 = false;  // Reset hit status
  }

  // Handle target 3
  if (pr3Value > lightThreshold && !targetHit3) {
    servo3.write(180);  // Move target down
    hitTime3 = millis();  // Record the time target 3 was hit
    targetHit3 = true;  // Mark that target 3 was hit
  }
  if (targetHit3 && (millis() - hitTime3 >= downTime)) {
    servo3.write(0);  // Move target back up after 5 seconds
    targetHit3 = false;  // Reset hit status
  }

  // Handle target 4
  if (pr4Value > lightThreshold && !targetHit4) {
    servo4.write(180);  // Move target down
    hitTime4 = millis();  // Record the time target 4 was hit
    targetHit4 = true;  // Mark that target 4 was hit
  }
  if (targetHit4 && (millis() - hitTime4 >= downTime)) {
    servo4.write(0);  // Move target back up after 5 seconds
    targetHit4 = false;  // Reset hit status
  }
}
