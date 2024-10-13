// Pin definitions for Motor 1
const int motor1Pin1 = 8;  // Motor 1 Pin 1
const int motor1Pin2 = 9;  // Motor 1 Pin 2

// Pin definitions for Motor 2
const int motor2Pin1 = 10; // Motor 2 Pin 1
const int motor2Pin2 = 11; // Motor 2 Pin 2

// Timing intervals
const long spinTime = 5000;  // Spin for 5 seconds
const long stopTime = 1000;  // Stop for 1 second

// Variables to track timing
unsigned long previousMillis = 0;
bool isSpinning = true;

void setup() {
  // Initialize Motor 1 pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  // Initialize Motor 2 pins as output
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Start with motors spinning in one direction
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  // If motors are spinning and 5 seconds have passed, stop them
  if (isSpinning && currentMillis - previousMillis >= spinTime) {
    // Stop motors
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    // Set the timer for the stop period
    previousMillis = currentMillis;
    isSpinning = false;
  }

  // If motors are stopped and 1 second has passed, switch direction and spin again
  else if (!isSpinning && currentMillis - previousMillis >= stopTime) {
    // Switch motor directions
    int motor1Direction = digitalRead(motor1Pin1);
    int motor2Direction = digitalRead(motor2Pin1);

    // Toggle direction for Motor 1
    if (motor1Direction == HIGH) {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
    } else {
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
    }

    // Toggle direction for Motor 2
    if (motor2Direction == HIGH) {
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    } else {
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }

    // Set the timer for the next spin period
    previousMillis = currentMillis;
    isSpinning = true;
  }
}