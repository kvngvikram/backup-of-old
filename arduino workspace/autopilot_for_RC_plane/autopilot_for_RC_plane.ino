
float pitchkp =1  , pitchkd = 500 , pitchki =0;
float rollkp =1  , rollkd = 800 , rollki =0;

int motorpin , rudderpin , elevatorpin , leftaileronpin , rightaileronpin ;
int yawpin = 12 , pitchpin = A0 , rollpin = 4 , thrustpin = 13 , toggle1pin = 8 , toggle2pin = 7;
float minpitchrec=1000 , maxpitchrec = 2000 , minpitch = -50 , maxpitch = 50 ;
float minrollrec=1000 , maxrollrec = 2000 , minroll = -60 , maxroll = 60 ;


float pitche_old,rolle_old,pitchE,rollE;
#include <Servo.h>
Servo motor;
Servo leftaileron;
Servo rightaileron;
Servo elevator;
Servo rudder;
int yaw=0 , pitch=1 , roll=2 , thrust=3 , toggle1=4 , toggle2=5 ;
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
MPU6050 mpu;

bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high


#include <PinChangeInt.h>
volatile unsigned long lastpulsetime[6] ;
volatile unsigned long firstpulsetime[6];
volatile unsigned long ch[6];

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  attachreceiver();
  startmpu();
  attachservos();
}

void loop(){
  unsigned long lch[6];
  //noInterrupts();
  for(int i=0;i<6;i++){
    Serial.print("    ");
    Serial.print(ch[i]);
    lch[i]=ch[i];
    }
  Serial.println("");
  //interrupts();
  motor.writeMicroseconds(lch[thrust]);
  rudder.writeMicroseconds(lch[yaw]);

  bool autocondition = lch[toggle1]>1500;
  while (!mpuInterrupt && fifoCount < packetSize && autocondition ){
    
  }



  if(!autocondition){
    elevator.writeMicroseconds(lch[pitch]);
    rightaileron.writeMicroseconds(lch[roll]);
    leftaileron.writeMicroseconds(lch[roll]);
  }
  else {
    calculate_ypr();
    float targetpitch=map(lch[pitch],minpitchrec,maxpitchrec,minpitch,maxpitch);
    float targetroll=map(lch[roll],minrollrec,maxrollrec,minroll,maxroll);
    int pitchdelta=(int)pitchpid(targetpitch,ypr[1]);
    int rolldelta=(int)rollpid(targetroll,ypr[2]);
    if(pitchdelta<85&&pitchdelta>-85)elevator.write(90+pitchdelta);
    if(rolldelta<85&&rolldelta>-85){
      rightaileron.write(90+rolldelta);
      leftaileron.write(90+rolldelta);
    }
  }

  

}







void attachservos(){
  motor.attach(motorpin);
  elevator.attach(elevatorpin);
  rudder.attach(rudderpin);
  leftaileron.attach(leftaileronpin);
  rightaileron.attach(rightaileronpin);
}


float pitchpid(float target , float current){
  float e , e_dot , outpid ;    // error , change in error , output
  e = target - current ;     // error is required - actual 
  e_dot = e - pitche_old ;        // change in error , ideally it is derivative but we just subract
  pitchE=pitchE+e ;                 // This sums up all the errors from biginning 
  if(pitchE>500){                 // but check that it don't go too large
    /*Serial.println("E overflow");*/
    pitchE=0;
    }                        
  outpid = pitchkp*e + pitchkd*e_dot + pitchki*pitchE ;         // calculating output     
  pitche_old = e ;
  return outpid ;                              // returning output for corresponding i  
} 
float rollpid(float target , float current){
  float e , e_dot , outpid ;    // error , change in error , output
  e = target - current ;     // error is required - actual 
  e_dot = e - rolle_old ;        // change in error , ideally it is derivative but we just subract
  rollE=rollE+e ;                 // This sums up all the errors from biginning 
  if(rollE>500){                 // but check that it don't go too large
    /*Serial.println("E overflow");*/
    rollE=0;
    }                        
  outpid = rollkp*e + rollkd*e_dot + rollki*rollE ;         // calculating output     
  rolle_old = e ;
  return outpid ;                              // returning output for corresponding i  
} 

void attachreceiver(){
  pinMode(yawpin,INPUT);
  pinMode(pitchpin,INPUT);
  pinMode(rollpin,INPUT);
  pinMode(thrustpin,INPUT);
  pinMode(toggle1pin,INPUT);
  pinMode(toggle2pin,INPUT);
  attachPinChangeInterrupt( yawpin ,yawch , CHANGE );
  attachPinChangeInterrupt( pitchpin,pitchch , CHANGE );
  attachPinChangeInterrupt( rollpin ,rollch , CHANGE );
  attachPinChangeInterrupt( thrustpin ,thrustch , CHANGE);
  attachPinChangeInterrupt( toggle1pin ,toggle1ch , CHANGE );
  attachPinChangeInterrupt( toggle2pin ,toggle2ch , CHANGE );
}


void startmpu(){
  Wire.begin();
  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
/*
  // wait for ready
  Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available());                 // wait for data
  while (Serial.available() && Serial.read()); // empty buffer again
*/
   
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

 
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else while(1);
}

void dmpDataReady() {
    mpuInterrupt = true;
}



void calculate_ypr(){
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));
    } 
    else if (mpuIntStatus & 0x02) {
      while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            Serial.print("ypr\t");
            Serial.print(ypr[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(ypr[2] * 180/M_PI);
    }
  
}




void yawch(){
  unsigned long now = micros();
  if(!digitalRead(yawpin)){
    lastpulsetime[yaw] = now ;
    ch[yaw]=lastpulsetime[yaw]-firstpulsetime[yaw];
 
  }
  else{
    firstpulsetime[yaw] = now ;
  }
}
void pitchch(){
  unsigned long now = micros();
  if(!digitalRead(pitchpin)){
    lastpulsetime[pitch] = now ;
    ch[pitch]=lastpulsetime[pitch]-firstpulsetime[pitch];
  }
  else{
    firstpulsetime[pitch] = now ;
  }
}
void rollch(){
  unsigned long now = micros();
  if(!digitalRead(rollpin)){
    lastpulsetime[roll] = now ;
    ch[roll]=lastpulsetime[roll]-firstpulsetime[roll];
    //cycle[roll] = ! cycle[roll] ;
  }
  else{
    firstpulsetime[roll] = now ;
  }
}
void thrustch(){
  unsigned long now = micros();
  if(!digitalRead(thrustpin)){
    lastpulsetime[thrust] = now ;
    ch[thrust]=lastpulsetime[thrust]-firstpulsetime[thrust];
  }
  else{
    firstpulsetime[thrust] = now ;
  }
}
void toggle1ch(){
  unsigned long now = micros();
  if(!digitalRead(toggle1pin)){
    lastpulsetime[toggle1] = now ;
    ch[toggle1]=lastpulsetime[toggle1]-firstpulsetime[toggle1];
  }
  else{
    firstpulsetime[toggle1] = now ;
  }
}
void toggle2ch(){
  unsigned long now = micros();
  if(!digitalRead(toggle2pin)){
    lastpulsetime[toggle2] = now ;
    ch[toggle2]=lastpulsetime[toggle2]-firstpulsetime[toggle2];
  }
  else{
    firstpulsetime[toggle2] = now ;
  }
}

