#include <Servo.h>
Servo motor ;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  motor.attach(9);
  motor.writeMicroseconds(1000);
  digitalWrite(13,HIGH);
  delay(5000);
  digitalWrite(13,LOW);
  motor.writeMicroseconds(1070);
  
  delay(10000);
  motor.writeMicroseconds(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
