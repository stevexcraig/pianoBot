const int touchPinA = 32;//DRUM 1
const int touchPinB = 33;//FRONT DESK
const int touchPinC = 27;//LARGE BELL
const int touchPinD = 14;//BELL
const int touchPinE = 12;//SMALL BELL
const int touchPinF = 13;//DRUM 2
//const int touchPinG =  ;//WOOD THING


const int threshold = 30;
const int thresholdMin = 5;
//const int thresholdMinA = 15;

int touchValueA;//DRUM 1
int touchValueB;//FRONT DESK
int touchValueC;//LARGE BELL
int touchValueD;//BELL
int touchValueE;//SMALL BELL
int touchValueF;//DRUM 2
int touchValueG;//WOOD THING


int noid1 = 23;//DRUM 1
int noid2 = 22;//FRONT DESK
int noid3 = 0;//LARGE BELL
int noid4 = 16;//BELL
int noid5 = 5;//SMALL BELL
int noid6 = 17;//DRUM 2
//int noid7 = ;//WOOD THING

int noidonTime = 25;
int noidoffTime = 120;

//int del = 80;

#include <analogWrite.h>

const int motor1Pin = 18;  // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 19;  // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 21;  // H-bridge enable pin
int potPin = 4;
int motorSpeed = 0;

const int thresholdM = 1830;

void setup() {
  Serial.begin(115200);
  delay(500);


  pinMode (noid1, OUTPUT);
  pinMode (noid2, OUTPUT);
  pinMode (noid3, OUTPUT);
  pinMode (noid4, OUTPUT);
  pinMode (noid5, OUTPUT);
  pinMode (noid6, OUTPUT);
  //pinMode (noid7, OUTPUT);

  pinMode (touchPinA, INPUT);
  pinMode (touchPinB, INPUT);
  pinMode (touchPinC, INPUT);
  pinMode (touchPinD, INPUT);
  pinMode (touchPinE, INPUT);
  pinMode (touchPinF, INPUT);
  // pinMode (touchPinG, INPUT);

  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);

  Serial.begin(115200);

}



void loop() {

  touchValueA = touchRead(touchPinA);
  if ((touchValueA < threshold) && (touchValueA > thresholdMin)) {
    noidA();
    noidOffA();
    //delay(50);
  }
  touchValueB = touchRead(touchPinB);
  if ((touchValueB < threshold) && (touchValueB > thresholdMin)) {
    noidB();
    noidOffB();
    //delay(50);

  }
  touchValueC = touchRead(touchPinC);
  if ((touchValueC < threshold) && (touchValueC > thresholdMin)) {
    noidC();
    noidOffC();
    //delay(50);

  }
  touchValueD = touchRead(touchPinD);
  if ((touchValueD < threshold) && (touchValueD > thresholdMin)) {
    noidD();
    noidOffD();
    //delay(50);

  }
  touchValueE = touchRead(touchPinE);
  if ((touchValueE < threshold) && (touchValueE > thresholdMin)) {
    noidE();
    noidOffE();
    //delay(50);

  }
  //delay(del);

  touchValueF = touchRead(touchPinF);
  if ((touchValueF < threshold) && (touchValueF > thresholdMin)) {
    noidF();
    noidOffF();
    //delay(50);

  }
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


///////////////

void noidA() {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidonTime) {
    digitalWrite(noid1, HIGH);

    if (millis() - snapshotOfTime > noidonTime) break;
  }
}

void noidOffA () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidoffTime) {
    digitalWrite(noid1, LOW);

    if (millis() - snapshotOfTime > noidoffTime) break;
  }
}

void noidB () {

  unsigned long snapshotOfTimeB = 0;
  snapshotOfTimeB = millis();
  while (millis() < snapshotOfTimeB + noidonTime) {
    digitalWrite(noid2, HIGH);

    if (millis() - snapshotOfTimeB > noidonTime) break;
  }
}

void noidOffB () {

  unsigned long snapshotOfTimeB = 0;
  snapshotOfTimeB = millis();
  while (millis() < snapshotOfTimeB + noidoffTime) {
    digitalWrite(noid2, LOW);

    if (millis() - snapshotOfTimeB > noidoffTime) break;
  }
}

void noidC () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidonTime) {
    digitalWrite(noid3, HIGH);

    if (millis() - snapshotOfTime > noidonTime) break;
  }
}

void noidOffC () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidoffTime) {
    digitalWrite(noid3, LOW);

    if (millis() - snapshotOfTime > noidoffTime) break;
  }
}

void noidD () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidonTime) {
    digitalWrite(noid4, HIGH);

    if (millis() - snapshotOfTime > noidonTime) break;
  }
}

void noidOffD () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidoffTime) {
    digitalWrite(noid4, LOW);

    if (millis() - snapshotOfTime > noidoffTime) break;
  }
}
void noidE () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidonTime) {
    digitalWrite(noid5, HIGH);

    if (millis() - snapshotOfTime > noidonTime) break;
  }
}

void noidOffE () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidoffTime) {
    digitalWrite(noid5, LOW);

    if (millis() - snapshotOfTime > noidoffTime) break;
  }
}
void noidF () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidonTime) {
    digitalWrite(noid6, HIGH);

    if (millis() - snapshotOfTime > noidonTime) break;
  }
}

void noidOffF () {

  unsigned long snapshotOfTime = 0;
  snapshotOfTime = millis();
  while (millis() < snapshotOfTime + noidoffTime) {
    digitalWrite(noid6, LOW);

    if (millis() - snapshotOfTime > noidoffTime) break;
  }

}
