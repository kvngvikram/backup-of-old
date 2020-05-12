#include <NewPing.h>
NewPing sonar(A1,A2,200);
float alt = 0 ;

#include <Servo.h>
Servo lservo;
Servo rservo;
Servo lmot;
Servo rmot;
Servo elev;
Servo alrn;
  int th=1000 ; 


#include <I2Cdev.h>
#include <Wire.h>
#include <MPU6050_6Axis_MotionApps20.h>
MPU6050 mpu;
Quaternion q; 
VectorFloat gravity;  
float ypr[3]={0,0,0} , yawbefore=0;   
uint16_t packetSize ;
uint16_t fifoCount ; 
unsigned long timerstart = 0 , timerstop=1000 ;


#include <PinChangeInt.h>
volatile unsigned long lastpulsetime[6] ;
volatile unsigned long firstpulsetime[6];
volatile unsigned long ch[6];
////////////////////////////////////////////////////////////


void chfunc1(){
  unsigned long now = micros();
  if(!digitalRead(A0)){/////////////////////////yaw
    lastpulsetime[0] = now ;
    ch[0]=lastpulsetime[0]-firstpulsetime[0];
  }
  else{
    firstpulsetime[0] = now ;
  }
}
void chfunc2(){///////////////////////pitch
  unsigned long now = micros();
  if(!digitalRead(13)){
    lastpulsetime[1] = now ;
    ch[1]=lastpulsetime[1]-firstpulsetime[1];
  }
  else{
    firstpulsetime[1] = now ;
  }
}
void chfunc3(){//////////////////roll
  unsigned long now = micros();
  if(!digitalRead(12)){
    lastpulsetime[2] = now ;
    ch[2]=lastpulsetime[2]-firstpulsetime[2];
  }
  else{
    firstpulsetime[2] = now ;
  }
}
void chfunc4(){//////////////////////height 
  unsigned long now = micros();
  if(!digitalRead(4)){
    lastpulsetime[3] = now ;
    ch[3]=lastpulsetime[3]-firstpulsetime[3];
  }
  else{
    firstpulsetime[3] = now ;
  }
}
void chfunc5(){
  unsigned long now = micros();
  if(!digitalRead(8)){
    lastpulsetime[4] = now ;
    ch[4]=lastpulsetime[4]-firstpulsetime[4];
  }
  else{
    firstpulsetime[4] = now ;
  }
}
void chfunc6(){
  unsigned long now = micros();
  if(!digitalRead(7)){
    lastpulsetime[5] = now ;
    ch[5]=lastpulsetime[5]-firstpulsetime[5];
  }
  else{
    firstpulsetime[5] = now ;
  }
}



volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}


float e_old[4]={0,0,0,0} ; 
double E[4]={0,0,0,0}; 
float pid(float set_point , float current , float kp , float ki , float kd ,int i){
  float e , e_dot , outpid ; 
  e = set_point - current ;
  e_dot = e - e_old[i] ; 
  E[i]=E[i]+e ;
  if(E[i]>1000)E[i]=0; 
  outpid = kp*e + kd*e_dot + ki*E[i] ;
  e_old[i] = e ;
  return outpid ;
} 



////////////////////////////////////////////////////////////


void setup() {
  pinMode(A0 , INPUT_PULLUP );
  pinMode(13 , INPUT_PULLUP );
  pinMode(12 , INPUT_PULLUP );
  pinMode( 4 , INPUT_PULLUP );
  pinMode( 8 , INPUT_PULLUP );
  pinMode( 7 , INPUT_PULLUP );
  lservo.attach(3);
  rservo.attach(5);
  lmot.attach(6);
  rmot.attach(9);
  elev.attach(10);
  alrn.attach(11);
  lmot.writeMicroseconds(1000);
  rmot.writeMicroseconds(1000);
  lservo.write(90);
  rservo.write(90);
  Wire.begin();
  Serial.begin(115200);
  while(!Serial);
  while(!Serial.available());
  char c = Serial.read();
  mpu.initialize();
  while(!mpu.testConnection())Serial.println(F("mpu test failed"));
  uint8_t devStatus = mpu.dmpInitialize();
  mpu.setXAccelOffset(-580);
  mpu.setYAccelOffset(-1716);
  mpu.setZAccelOffset(1843);
  mpu.setXGyroOffset(68);
  mpu.setYGyroOffset(-1);
  mpu.setZGyroOffset(-9);
  while(devStatus)Serial.println(F("dmp initialising failed "));
  mpu.setDMPEnabled(true);
  attachPinChangeInterrupt( 2 , dmpDataReady , RISING );
  attachPinChangeInterrupt( A0,chfunc1 , CHANGE );
  attachPinChangeInterrupt( 13,chfunc2 , CHANGE );
  attachPinChangeInterrupt( 12,chfunc3 , CHANGE );
  attachPinChangeInterrupt( 4 ,chfunc4 , CHANGE );
  attachPinChangeInterrupt( 8 ,chfunc5 , CHANGE );
  attachPinChangeInterrupt( 7 ,chfunc6 , CHANGE );
  Serial.println(F("All the interrupts enabled"));

  Serial.println(F("done with setup"));
  delay(5000);
  Serial.println("send to start");
  while(!Serial.available());
  c=Serial.read();
  /*for(int i = 1000 ; i<1600 ;i++){
    lmot.writeMicroseconds(i);
    rmot.writeMicroseconds(i);
    delay(20);
  }*/
  packetSize = mpu.dmpGetFIFOPacketSize();
  fifoCount = mpu.getFIFOCount();  
}

void loop() {
  float looptime = (float)(timerstop-timerstart);
  timerstart = micros(); 
  int pitch=1 , height = 3 , roll = 2 , yaw = 0 ; 
  uint16_t lrec[6] ={900,900,900,900,900,900};
  uint16_t hrec[6] ={2000,2000,2000,2000,2000,2000};
  float ref[4];
  int i =0 ;
  unsigned long lch[6];


  noInterrupts();
  for( i=0;i<6;i++){
    if(ch[i]<hrec[i]&&ch[i]>lrec[i])lch[i]=ch[i];
  }
  interrupts();
  /*for(int i=0;i<6;i++){
    Serial.print("\t");
    Serial.print(lch[i]);
    lch[i]=map(lch[i],lrec[i],hrec[i],1000,2000);
  }*/
  Serial.println("");
  ref[pitch]=map(lch[pitch],1000,2000,-5,5);
  ref[roll]=map(lch[roll],1000,2000,-5,5);
  //ref[height]=map(lch[height],1000,2000,0,200); //height in cm 
  ref[yaw]=map(lch[yaw],1000,2000,-10,10);  //10deg/sec max
  
  for(i=0;i<3;i++){
    ref[i]=0;
  }
  
  if(mpuInterrupt && fifoCount >= packetSize){
    mpuInterrupt = false;
    uint8_t mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
      mpu.resetFIFO();
      Serial.println(F("FIFO overflow!"));
    } 
    else if (mpuIntStatus & 0x02) {
      while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
      uint8_t fifoBuffer[64]; 
      mpu.getFIFOBytes(fifoBuffer, packetSize);
      fifoCount -= packetSize;
      mpu.dmpGetQuaternion(&q, fifoBuffer);
      mpu.dmpGetGravity(&gravity, &q);
      mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
      float yawrate = ypr[0]-yawbefore ;
      yawbefore = ypr[0];
      ypr[0]=yawrate;
  
      Serial.print("ypr\t");
      Serial.print(ypr[0] * 180/M_PI);
      Serial.print("\t");
      Serial.print(ypr[1] * 180/M_PI);
      Serial.print("\t");
      Serial.println(ypr[2] * 180/M_PI);
    }
  }
  else {Serial.print("nointerrupt   ");Serial.print(mpuInterrupt ); Serial.print("  ");Serial.print(fifoCount);Serial.print(" ");Serial.println(packetSize);}
  float gotalt = (float)(sonar.ping_cm());
  //Serial.println(alt);
  if((gotalt<alt-5||gotalt>alt+5)&&gotalt!=0)alt=gotalt ; 
  

  //             yaw   pitch   roll   height 
  float kp[4]={   0 ,40   ,   0   ,    0    };
  float ki[4]={   0.0    , 0.0    ,     0.0 ,     0.0   };
  float kd[4]={  0.0     ,  0.0    ,    0.0  ,      0.0 };
  
  

  float delta[4];
  for(i=0;i<3;i++)delta[i]=pid(ref[i],ypr[i],kp[i],ki[i],kd[i],i);
  delta[3]=pid(ref[3],alt,kp[3],ki[3],kd[3],3);

  if(Serial.available()) th=Serial.parseInt();
  unsigned int thlservo = 90 /*- delta[0]*/ - delta[1] ;
  unsigned int thrservo = 90 /*- delta[0]*/ + delta[1] ; 
  unsigned int thlmot = th + delta[2] /*+ delta[4]*/ ;
  unsigned int thrmot = th - delta[2] /*+ delta[4] */;

  Serial.println("");
  Serial.print("\t");
  Serial.print(thlservo);
  Serial.print("\t");
  Serial.print(thlmot);
  Serial.print("\t");
  Serial.print(thrmot);
  Serial.print("\t");
  Serial.print(thrservo);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  
  lservo.write(thlservo);
  rservo.write(thrservo);
  lmot.writeMicroseconds(thlmot);
  rmot.writeMicroseconds(thrmot);
    
  timerstop=micros();
}

