#include <Servo.h>  // Include the Servo library

// Define the analog pin connected to the photoresistor
const int pr1 = A0;
const int pr2 = A1;
const int pr3 = A2;
const int pr4 = A3;
const int lightThreshold = 800;  // Threshold to detect "light"

// Create servo objects for two servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Attach the servos
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);

  // Start both servos rotating continuously in one direction
  servo1.write(180); 
  servo2.write(180); 
  servo3.write(180); 
  servo4.write(180); 
}

void loop() {
  // Read the analog value from the photoresistor
  int pr1Value = analogRead(pr1);
  int pr2Value = analogRead(pr2);
  int pr3Value = analogRead(pr3);
  int pr4Value = analogRead(pr4);

  // Output the raw value to the Serial Monitor
  Serial.print(pr1Value);
  Serial.print(" ");
  Serial.print(pr2Value);
  Serial.print(" ");
  Serial.print(pr3Value);
  Serial.print(" ");
  Serial.println(pr4Value);

  if (pr1Value > lightThreshold) {
    servo1.write(90);
  } else {
    servo1.write(180);
  }

  if (pr2Value > lightThreshold) {
    servo2.write(90);
  } else {
    servo2.write(180);
  }

  if (pr3Value > lightThreshold) {
    servo3.write(90);
  } else {
    servo3.write(180);
  }

  if (pr4Value > lightThreshold) {
    servo4.write(90);
  } else {
    servo4.write(180);
  }

}