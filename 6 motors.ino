#include <Servo.h>

int inputpin1 =  13;
int inputpin2 =  8;
int inputpin3 =  2;
int inputpin4 =  1;
int inputpin5 =  7;
int inputpin6 =  12;

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo
Servo myservo6;  // create servo object to control a servo

int angle1 =0;    // initial angle  for servo
int angle2 =0;    // initial angle  for servo
int angle3 =0;    // initial angle  for servo
int angle4 =0;    // initial angle  for servo
int angle5 =0;    // initial angle  for servo
int angle6 =0;    // initial angle  for servo
int angleStep =10;
int Step1 = angleStep;
int Step2 = angleStep;
int Step3 = angleStep;
int Step4 = angleStep;
int Step5 = angleStep;
int Step6 = angleStep;

void setup() {
  // Servo button demo by Robojax.com
  Serial.begin(9600);          //  setup serial
  myservo1.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo5.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo6.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.write(angle1);
  myservo2.write(angle2);
  myservo3.write(angle3);
  myservo4.write(angle4);
  myservo5.write(angle5);
  myservo6.write(angle6);
  pinMode(inputpin1,INPUT_PULLUP);
  pinMode(inputpin2,INPUT_PULLUP);
  pinMode(inputpin3,INPUT_PULLUP);
  pinMode(inputpin4,INPUT_PULLUP);
  pinMode(inputpin5,INPUT_PULLUP);
  pinMode(inputpin6,INPUT_PULLUP);


  Serial.println("Servo Button");
}

void loop() {

  if (digitalRead(inputpin1) == LOW){
    if (angle1 < 180) {
      angle1 = angle1 + Step1;
      myservo1.write(angle1);
    } 
  }
  else {
    angle1 = 0;
    myservo1.write(angle1);
  }

  if (digitalRead(inputpin2) == LOW){
    if (angle2 < 180) {
      angle2 = angle2 + Step2;
      myservo2.write(angle2);
    } 
  }
  else {
    angle2 = 0;
    myservo2.write(angle2);
  }

  if (digitalRead(inputpin3) == LOW){
    if (angle3 < 180) {
      angle3 = angle3 + Step3;
      myservo3.write(angle3);
    } 
  }
  else {
    angle3 = 0;
    myservo3.write(angle3);
  }

  if (digitalRead(inputpin4) == LOW){
    if (angle4 < 180) {
      angle4 = angle4 + Step4;
      myservo4.write(angle4);
    } 
  }
  else {
    angle4 = 0;
    myservo4.write(angle4);
  }

  if (digitalRead(inputpin5) == LOW){
    if (angle5 < 180) {
      angle5 = angle5 + Step5;
      myservo5.write(angle5);
    } 
  }
  else {
    angle5 = 0;
    myservo5.write(angle5);
  }

  if (digitalRead(inputpin6) == LOW){
    if (angle6 < 180) {
      angle6 = angle6 + Step6;
      myservo6.write(angle6);
    } 
  }
  else {
    angle6 = 0;
    myservo6.write(angle6);
  }
    
}
