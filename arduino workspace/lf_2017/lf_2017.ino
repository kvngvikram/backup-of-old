#include <AFMotor.h>

AF_DCMotor lmotor(3);
AF_DCMotor rmotor(4);
float lowf=215 , highf=1000 , lowb=255 , highb=995 , lowm=175 , highm=755 ;
float minf = 607 , minb = 625 , minm = 465 ; //minm should be max
float kf=100/(highf-minf) , kb=100/(highb-minb) , km=50/(lowm-minm) ; // km is positive
int fpin=A4 , bpin=A5 , mpin=A3 , speedledpin=A0 , batterypin=A2 , batteryledpin=A1 ;
float safe1=0 , safe2=30 ;
float fsense , bsense , msense;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  fsense = map(analogRead(fpin),lowf,highf,0,255);
  bsense = map(analogRead(bpin),lowb,highb,0,255);
  msense = map(analogRead(mpin),lowm,highm,0,255);
  float left     = delta(fsense , minf , kf , 2 );
  float right    = delta(bsense , minb , kb , 3 );
  float straight = delta(msense , minm , km , 1 );

  float rightwheel = -left + right + straight + safe1 + safe2 ;
  float leftwheel  = -right + left + straight - safe1 + safe2 ;

  if(rightwheel<0){
    rightwheel=-rightwheel;
    rmotor.run(BACKWARD);
  }
  else rmotor.run(FORWARD);
  if(leftwheel<0){
    leftwheel=-leftwheel;
    lmotor.run(BACKWARD);
  }
  else lmotor.run(FORWARD);
  if(leftwheel  >= 255) {
    leftwheel  = 255 ;
    digitalWrite(speedledpin,HIGH);
  }
  else digitalWrite(speedledpin,LOW);
  if(rightwheel >= 255) {
    rightwheel = 255 ;
    digitalWrite(speedledpin,HIGH);
  }
  else digitalWrite(speedledpin,LOW);
  
  Serial.print(leftwheel);
  Serial.print("  ");
  Serial.println(rightwheel);
  lmotor.setSpeed(int(leftwheel ));  
  rmotor.setSpeed(int(rightwheel));

  float battery=analogRead(batterypin);
  //if(battery<760)while(1)digitalWrite(batteryledpin,HIGH);
}

float delta(float sense , float mean , float k , int i){
  float delta = (sense - mean)*k;
  return(delta); 
}
