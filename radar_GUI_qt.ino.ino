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
  readSerialCommand(); // Read command from serial
  outputDistance();
  delay(50);
}

// Function to read servo angle command from serial
void readSerialCommand() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    int angle = command.toInt();
    if (angle >= 0 && angle <= 180) {
      myservo.write(angle);
      servoSetting = angle;
    }
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
