#include <Servo.h>

const int buttonPin = 2;
const int servoPin = 9;
int buttonState = 0;
Servo myServo;


void setup() {
  pinMode(buttonPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}


void loop() {
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH) {
    myServo.write(180);
  } else {
    myServo.write(0);
  }
}
