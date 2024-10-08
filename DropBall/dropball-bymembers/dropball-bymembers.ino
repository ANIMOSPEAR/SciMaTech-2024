#include <Servo.h>

Servo myservo;  
int pos = 0;
int buttonPin = 2;
int servoPin = 9;
void setup() {
  myservo.attach(servoPin);  
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);  
  if (buttonState == LOW) {  // if the button is pressed
    for (pos = 180; pos <= 0; pos += 1) {  // move servo from 0 to 180 degrees
      myservo.write(pos);  // tell servo to go to position
      Serial.print("Current position of servo: ");
      Serial.println(pos);
      delay(5);  // wait 15 milliseconds for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) {  // move servo back from 180 to 0 degrees
      myservo.write(pos);  // tell servo to go to position
      Serial.print("Current position of servo: ");
      Serial.println(pos);
      delay(5);  // wait 15 milliseconds for the servo to reach the position
    }
  }
}
