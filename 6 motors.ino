#include <Servo.h> 


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


// Define stepper motor connections and steps per revolution:
#define dirPin_1 2
#define stepPin_1 3
#define dirPin_2 4
#define stepPin_2 5
#define dirPin_3 6
#define stepPin_3 7
#define stepsPerRevolution 200
#define delay_stepper 2000

int counter_1 = 0;
int counter_2 = 99;
int counter_3 = 199;
int adder_1 = 1;
int adder_2 = 1;
int adder_3 = 1;

void setup() {

  Serial.begin(9600);          //  setup serial

  // Declare pins as output:
  pinMode(stepPin_1, OUTPUT);
  pinMode(dirPin_1, OUTPUT);
  pinMode(stepPin_2, OUTPUT);
  pinMode(dirPin_2, OUTPUT);
  pinMode(stepPin_3, OUTPUT);
  pinMode(dirPin_3, OUTPUT);


  myservo1.attach(8);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo5.attach(12);  // attaches the servo on pin 9 to the servo object
  myservo6.attach(13);  // attaches the servo on pin 9 to the servo object
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

  pinMode(inputpin1,INPUT_PULLUP);
  pinMode(inputpin2,INPUT_PULLUP);
  pinMode(inputpin3,INPUT_PULLUP);
  pinMode(inputpin4,INPUT_PULLUP);
  pinMode(inputpin5,INPUT_PULLUP);
  pinMode(inputpin6,INPUT_PULLUP);

  digitalWrite(dirPin_1, HIGH);
  digitalWrite(dirPin_2, HIGH);
  digitalWrite(dirPin_3, HIGH);

  // Stepper 2 goes to a initial position
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin_2, HIGH);
    delayMicroseconds(delay_stepper);
    digitalWrite(stepPin_2, LOW);
    delayMicroseconds(delay_stepper);
  }

  // Stepper 3 goes to a initial position
  for (int i = 0; i < stepsPerRevolution*2; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin_3, HIGH);
    delayMicroseconds(delay_stepper);
    digitalWrite(stepPin_3, LOW);
    delayMicroseconds(delay_stepper);
  }

  
  Serial.println("Servo Button");
}

void loop() {

  counter_1 += adder_1;
  counter_2 += adder_2;
  counter_3 += adder_3; 


  if (counter_1 == 200){
    digitalWrite(dirPin_1, LOW);
    adder_1 *= -1;
  } else if (counter_1 == 0){
    digitalWrite(dirPin_1, HIGH);
    adder_1 *= -1;
  }

  if (counter_2 == 200){
    digitalWrite(dirPin_2, LOW);
    adder_2 *= -1;
  } else if (counter_2 == 0){
    digitalWrite(dirPin_2, HIGH);
    adder_2 *= -1;
  }

  if (counter_3 == 200){
    digitalWrite(dirPin_3, LOW);
    adder_3 *= -1;
  } else if (counter_3 == 0){
    digitalWrite(dirPin_3, HIGH);
    adder_3 *= -1;
  }


  digitalWrite(stepPin_1, HIGH);
  digitalWrite(stepPin_2, HIGH);
  digitalWrite(stepPin_3, HIGH);
  delayMicroseconds(delay_stepper);
  digitalWrite(stepPin_1, LOW);
  digitalWrite(stepPin_2, LOW);
  digitalWrite(stepPin_3, LOW);
  delayMicroseconds(delay_stepper);


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
