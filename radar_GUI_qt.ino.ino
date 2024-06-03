#include <Servo.h>

// Servo
Servo myservo;

// HC-SR04 ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;
int servoSetting;

void setup() {
  // Serial
  Serial.begin(9600);
  
  // Servo
  myservo.attach(11);
  myservo.write(0); // Initialize servo at angle 0
  
  // HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  getDistance();
  moveServoAutomatically();
  outputDistance();
  delay(50);
}

// Function to move servo automatically based on distance
void moveServoAutomatically() {
  if (distance < 50) {  // If the object is within 50 cm
    servoSetting = map(distance, 0, 50, 0, 180);  // Map distance to servo angle
    myservo.write(servoSetting);
    delay(10); // Add a small delay to avoid data conflicts
  }
}

// Function to get distance from HC-SR04
void getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

// Function to output distance to Serial
void outputDistance() {
  Serial.print(servoSetting); // Send servo angle
  Serial.print(",");
  Serial.println(distance);   // Send distance
}
