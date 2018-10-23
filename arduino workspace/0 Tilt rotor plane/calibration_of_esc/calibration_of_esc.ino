/*
Coded by Marjan Olesch
Sketch from Insctructables.com
Open source - do what you want with this code!
*/
#include <Servo.h>


int value = 1000; // set values you need to zero

Servo leftESC, rightESC; //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time
Servo lservo,rservo ;
void setup() {

  leftESC.attach(9);// attached to pin 9 I just do this with 1 Servo
  rightESC.attach(10);
  Serial.begin(9600);    // start serial at 9600 baud
  lservo.attach(5);
  rservo.attach(6);
  lservo.write(90);
  rservo.write(90);
}

void loop() {

//First connect your ESC WITHOUT Arming. Then Open Serial and follo Instructions
 
  leftESC.writeMicroseconds(value);
  rightESC.writeMicroseconds(value);
 
  if(Serial.available()) 
    value = Serial.parseInt();    // Parse an Integer from Serial

}
