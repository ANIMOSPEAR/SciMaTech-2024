#include <Servo.h>

// Define pin numbers for the buttons
const int buttonPin1 = 4; 
const int buttonPin2 = 5; 

// Variables to store button states
int buttonState1 = 0;
int buttonState2 = 0;

// Motor control pins
const int in3 = 9;
const int in4 = 10;
const int enb = 11;

// Motor speed variable
int motorSpeed = 0;
bool decreaseSpeed = false;

// Servo pins
const int servoPin = 12;

// Servo objects
Servo servo;

void setup() {
  // Set button pins as input
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  // Set motor pins as output
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
  
  // Attach servos to their pins
  servo.attach(servoPin);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);

  // Initialize motor stopped
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enb, 0);

  // Set servos to initial position
  servo.write(0);
}

void loop() {
  // Read the state of the buttons
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // If button1 is pressed, start motor at full speed
  if (buttonState1 == HIGH) {
    motorSpeed = 255;  // Full speed
    decreaseSpeed = false;  // Stop decreasing speed
  }

  // If button2 is pressed, start decreasing speed (toggle button)
  if (buttonState2 == HIGH && !decreaseSpeed) {
    decreaseSpeed = true;
  }

  // Continuously decrease speed if the flag is set
  if (decreaseSpeed) {
    motorSpeed -= 5;  // Decrease speed in small steps
    if (motorSpeed < 0) {
      motorSpeed = 0;  // Ensure speed doesn't go below 0
      decreaseSpeed = false;  // Stop decreasing when speed reaches 0
    }
  }

  // Motor control
  if (motorSpeed > 0) {
    digitalWrite(in3, HIGH);  // Forward direction
    digitalWrite(in4, LOW);   // Ensure reverse is off
    analogWrite(enb, motorSpeed);  // Set motor speed
  } else {
    digitalWrite(in3, LOW);   // Stop motor
    digitalWrite(in4, LOW);   // Ensure reverse is off
    analogWrite(enb, 0);      // Turn off motor
  }

  // Servo Control
  if (buttonState2 == HIGH) {
    servo.write(90);  // Move Servo 1 to 0 degrees
  }
  if (motorSpeed == 0) {
    servo.write(0);  // Move Servo 1 to 180 degrees
  }

  // Debugging output
  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);

  delay(100);  // Small delay to avoid too fast execution
}
