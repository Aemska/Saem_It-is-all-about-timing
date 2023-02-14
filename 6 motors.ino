#include <Servo.h> 

Servo pump1;
Servo pump2;
Servo pump3;
int counter1 = 0;
int counter2 = 60;
int counter3 = 120;
int adder1 = 1;
int adder2 = 1;
int adder3 = 1;
int step_time = 3;

int inputpin1 =  22;
int inputpin2 =  24;
int inputpin3 =  26;
int inputpin4 =  28;
int inputpin5 =  30;
int inputpin6 =  32;


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


void setup() 
{ 
  Serial.begin(9600);          //  setup serial
  myservo1.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(7);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(8);  // attaches the servo on pin 9 to the servo object
  myservo5.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo6.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo1.write(angle1);
  delay(100);
  myservo2.write(angle2);
  delay(100);
  myservo3.write(angle3);
  delay(100);
  myservo4.write(angle4);
  delay(100);
  myservo5.write(angle5);
  delay(100);
  myservo6.write(angle6);
  delay(100);
  
  pump1.attach(2);
  pump2.attach(3);
  pump3.attach(4);    
  pump1.write(0); 
  delay(1000);
  pump2.write(0);  
  delay(1000);
  pump3.write(0);  
  delay(1000);
  pump1.write(counter1);  
  delay(1000);
  pump2.write(counter2); 
  delay(1000);
  pump3.write(counter3);  
  delay(1000);
  
  pinMode(inputpin1,INPUT_PULLUP);
  pinMode(inputpin2,INPUT_PULLUP);
  pinMode(inputpin3,INPUT_PULLUP);
  pinMode(inputpin4,INPUT_PULLUP);
  pinMode(inputpin5,INPUT_PULLUP);
  pinMode(inputpin6,INPUT_PULLUP);

  
  Serial.println("Servo Button");
} 

void loop() {  
  counter1 += adder1;
  counter2 += adder2;
  counter3 += adder3;
  pump1.write(counter1);
  delay(step_time);  
  pump2.write(counter2); 
  delay(step_time);
  pump3.write(counter3); 
  delay(step_time);
  if (counter1 == 180){
    adder1 *= -1;
  } else if(counter1 == 0){
    adder1 *= -1;
  }
  if (counter2 == 180){
    adder2 *= -1;
  } else if(counter2 == 0){
    adder2 *= -1;
  }
  if (counter3 == 180){
    adder3 *= -1;
  } else if(counter3 == 0){
    adder3 *= -1;
  }

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
