#include <Servo.h>

const int buttonPin = 2;
const int servoPin = 9;

int buttonState = 0;
float servoSmoothed = 0;
float servoPrev = 0;

Servo myServo;


void setup() {
  pinMode(buttonPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    MoveServoTo(180);                    
  } else {
    MoveServoTo(0);
  }
}

// Smoothly move the servo to the target position
void MoveServoTo(int targetPosition) {
  while (abs(servoSmoothed - targetPosition) > 0.1) {
    servoSmoothed = (targetPosition * 0.15) + (servoPrev * 0.85);
    servoPrev = servoSmoothed;

    myServo.write(int(servoSmoothed));

    Serial.print("Target: ");
    Serial.print(targetPosition);
    Serial.print(" , Smoothed: ");
    Serial.println(servoSmoothed);

    delay(10);  // Delay for smooth movement
  }
}
