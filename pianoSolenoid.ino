const int touchPinA = 32;//DRUM 1
const int touchPinB = 33;//FRONT DESK
const int touchPinC = 27;//LARGE BELL
const int touchPinD = 14;//BELL
const int touchPinE = 12;//SMALL BELL
const int touchPinF = 13;//DRUM 2
//const int touchPinG =  ;//WOOD THING


const int threshold = 30;
const int thresholdMin = 5;
const int thresholdMinA = 15;

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

int noidonTime = 30;
int noidoffTime = 120;

int del = 80;

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
}

void loop() {

//  touchValueF = touchRead(touchPinF);
 //touchValueG = touchRead(touchPinG);
//  char buffer[40];
//  sprintf(buffer, "F %u, G = %u", touchValueF, touchValueG);
//  Serial.println(buffer);
//  //delay(500);
//
//  {
//    noidF ();
 //   noidG ();
//  }

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

  // touchValueG = touchRead(touchPinG);
  // if ((touchValueG < threshold) && (touchValueG > thresholdMin)) {
  //   noidG();
    
  //   //delay(50);

  // }
  
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

  


//void noidF () {
//
//  if (touchValueF < 20) {
//    digitalWrite(noid6, LOW);
//  } else {
//    digitalWrite(noid6, HIGH);
//  }
//}
//
// void noidG () {

//   if (touchValueG < 20) {
//     digitalWrite(noid7, LOW);
//   } else {
//     digitalWrite(noid7, HIGH);
//   }
// }
