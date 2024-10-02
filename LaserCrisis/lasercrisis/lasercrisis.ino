#include <Servo.h>

// Create servo objects
Servo servo_x1;  
Servo servo_x2;
Servo servo_y1;
Servo servo_y2;

// Photoresistor pins
const int sensor_x1 = A0;
const int sensor_x2 = A1;
const int sensor_y1 = A2;
const int sensor_y2 = A3;

// Threshold for light intensity
const int threshold = 500;

void setup() {
  // Attach the servos to their respective pins
  servo_x1.attach(9); 
  servo_x2.attach(10);
  servo_y1.attach(11);
  servo_y2.attach(12);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the light intensity from each photoresistor
  int light_x1 = analogRead(sensor_x1);
  int light_x2 = analogRead(sensor_x2);
  int light_y1 = analogRead(sensor_y1);
  int light_y2 = analogRead(sensor_y2);

  // Print the sensor values (for debugging)
  Serial.print("Light X1: "); Serial.print(light_x1);
  Serial.print(" | Light X2: "); Serial.print(light_x2);
  Serial.print(" | Light Y1: "); Serial.print(light_y1);
  Serial.print(" | Light Y2: "); Serial.println(light_y2);

  if (light_x1 > threshold) {
    servo_x1.write(180);
  } else {
    servo_x1.write(0);    
  }

  if (light_x2 > threshold) {
    servo_x2.write(180);
  } else {
    servo_x2.write(0);
  }

  if (light_y1 > threshold) {
    servo_y1.write(90);
  } else {
    servo_y1.write(45);
  }

  if (light_y2 > threshold) {
    servo_y2.write(135);
  } else {
    servo_y2.write(90); 
  }

}
