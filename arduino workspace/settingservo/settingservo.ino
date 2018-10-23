#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(5);
}

void loop() {
  if(Serial.available())myservo.write(Serial.parseInt());

}
