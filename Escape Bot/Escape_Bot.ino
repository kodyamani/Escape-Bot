#include <Servo.h>

int redLED = A0;
const int photoResistor = A1;
const int threshold = 311;

Servo servoLeft;                 
Servo servoRight;   

int sensorReading = 0;

int leftWhisker = 5 ;
int rightWhisker = 7 ;

void pause() {

  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1472);
}

void forward() {

  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
}

void backwards() {

  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
}

void rightturn() {

  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
}

void leftturn() {

  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
}

void setup() {
  servoLeft.attach(13);                     
  servoRight.attach(12); 
  
  pinMode(redLED,OUTPUT);

  pinMode(leftWhisker, INPUT);
  pinMode(rightWhisker, INPUT);

  Serial.begin(9600);

  pinMode(leftWhisker, INPUT);
  pinMode(rightWhisker, INPUT);

}

void loop() {
    
  sensorReading = analogRead(photoResistor);
    
  int lwValue = digitalRead(leftWhisker); 
  int rwValue = digitalRead(rightWhisker);
  
  if(sensorReading <= 311) {
  digitalWrite(redLED,HIGH);
  delay(500);
  digitalWrite(redLED,LOW);
  delay(500);
  digitalWrite(redLED,HIGH);
  delay(500);
  backwards();
  delay(1000);
  rightturn();
  delay(1000);
  }
  
  if(lwValue == 0 && rwValue == 0) {
  pause();
  delay(1000);
  backwards();
  delay(1000);
  rightturn();
  delay(1000);
} else if(lwValue == 0) {
  rightturn();
  delay(1000);
} else if(rwValue == 0) {
  leftturn();
  delay(1000);
} else {
  forward();
  delay(1000);
}

}

