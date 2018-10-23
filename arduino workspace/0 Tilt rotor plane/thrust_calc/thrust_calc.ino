#include <Servo.h>
int motorpin=9;
int minthrot=1000;
int maxthrot=2000;
int throtreq=1000;
int throt=1000;
int i ;
Servo motor ;
void setup() {
  Serial.begin(9600);
  motor.attach(motorpin);
  Serial.println("Serial started");
  motor.writeMicroseconds(throt);
  Serial.println("throttle set at minimum ");
  
  

}

void loop() {
  if(Serial.available()){
    throtreq=Serial.parseInt();
  }
  if(throtreq<2000&&throtreq>=1000){
    if(throtreq>throt){
      for(;throt<throtreq;throt++){
        motor.writeMicroseconds(throt);
        delay(20);
      }
      Serial.print("throt increased to :\t");
      Serial.println(throt);
    }
    else if (throtreq<throt){
      for(;throt>throtreq;throt--){
        motor.writeMicroseconds(throt);
        delay(5);
      }
      Serial.print("throt decreased to :\t");
      Serial.println(throt);
    }
    //else if (throtreq==throt)Serial.println("Already set");
  }
  else {
    throt=1000;
    motor.writeMicroseconds(throt);
    Serial.println("motor stopped , throt set to 1000");
  }

}
