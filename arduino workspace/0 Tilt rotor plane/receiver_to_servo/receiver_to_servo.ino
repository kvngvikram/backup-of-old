#include <Servo.h>
Servo myservo ;
int ch ;
void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(8, INPUT);
  myservo.attach(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ch = pulseIn(8 , HIGH , 25000);
  Serial.print("\t");
  Serial.print(ch);
  Serial.print("\t");
  ch=map(ch,1125,2110,0,180);
  Serial.println(ch);
  myservo.write(ch);
  
}
