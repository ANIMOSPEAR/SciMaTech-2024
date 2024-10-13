#include <Servo.h>

const int joystickXPin = A0;
const int joystickYPin = A1;
const int servo1Pin = 9;       
const int servo2Pin = 10;      

Servo servo1; 
Servo servo2; 


void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  Serial.begin(9600);
}

void loop() {
  // Read the joystick values
  int joystickXValue = analogRead(joystickXPin);
  int joystickYValue = analogRead(joystickYPin);

  int servo1Position = map(joystickXValue, 0, 1023, 0, 180);
  int servo2Position = map(joystickYValue, 0, 1023, 0, 180);

  servo1.write(servo1Position);
  servo2.write(servo2Position);

  Serial.print("X-axis: ");
  Serial.print(servo1Position);
  Serial.print(" , Y-axis: ");
  Serial.println(servo2Position);
}
