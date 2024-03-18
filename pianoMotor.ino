#include <analogWrite.h>

const int motor1Pin = 18;  // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 19;  // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 21;  // H-bridge enable pin
int potPin = 4;
int motorSpeed = 0;

const int threshold = 1830;

void setup() {

  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);

  Serial.begin(115200);

}

void loop() {

  int analogValue = analogRead(potPin);
  Serial.println(analogValue);


  // if the switch is high, motor will turn on one direction:
  if (analogValue >= 1840) {
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    motorSpeed = map(analogValue, 1840, 4095, 0, 255);
    analogWrite(enablePin, motorSpeed);
  }
  // if the switch is high, motor will turn on one direction:
  if (analogValue < 1835) {
    digitalWrite(motor1Pin, HIGH);  // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, LOW);   // set leg 2 of the H-bridge high
    motorSpeed = map(analogValue, 0, 1840, 255, 0);
    analogWrite(enablePin, motorSpeed);
  }
}
