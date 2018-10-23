#include "I2Cdev.h"
#include "Wire.h"
#include "MPU6050_6Axis_MotionApps20.h"
int ax_offset,ay_offset,az_offset,gx_offset,gy_offset,gz_offset;
MPU6050 mpu;
Quaternion q; 
VectorFloat gravity;  
float ypr[3];   
uint16_t packetSize ;
volatile bool mpuInterrupt = false ;
void setup() {
  Wire.begin();
 // TWBR = 24;
  Serial.begin(115200);
  while (!Serial);
  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
  Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  /*while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available());                 // wait for data
  while (Serial.available() && Serial.read()); // empty buffer again
  */Serial.println(F("Initializing DMP..."));
  uint8_t devStatus = mpu.dmpInitialize();
 // calibrate();
  mpu.setXAccelOffset(-887);
    mpu.setYAccelOffset(-1836);
    mpu.setZAccelOffset(1881);
    mpu.setXGyroOffset(67);
    mpu.setYGyroOffset(2);
    mpu.setZGyroOffset(-18);
  while(devStatus)Serial.println(F("dmp initialising failed"));
  mpu.setDMPEnabled(true);
  Serial.println(F("Enabling DMP..."));
  attachInterrupt(0, dmpDataReady, RISING);
  Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
//  mpuIntStatus = mpu.getIntStatus();
  packetSize = mpu.dmpGetFIFOPacketSize();
  Serial.println(F("done with setup"));
  
}

void loop() {
  uint16_t fifoCount;
  uint8_t fifoBuffer[64];
  do{
    //
    Serial.println(F("hello"));
    //
  }while(!mpuInterrupt && fifoCount < packetSize);
  mpuInterrupt=false;
  fifoCount=mpu.getFIFOCount();
  uint8_t mpuIntStatus = mpu.getIntStatus();

  if ((mpuIntStatus & 0x10) || fifoCount ==1024) {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));
  
    // otherwise, check for DMP data ready interrupt (this should happen frequently)
  }
  else if(mpuIntStatus & 0x02){
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
void dmpDataReady(){
  mpuInterrupt = true ;
}
void calibrate(){
  
  int16_t ax, ay, az,gx, gy, gz;
  int buffersize=1000;     //Amount of readings used to average, make it higher to get more precision but sketch will be slower  (default:1000)
  int acel_deadzone=8;     //Acelerometer error allowed, make it lower to get more precision, but sketch may not converge  (default:8)
  int giro_deadzone=1;     //Giro error allowed, make it lower to get more precision, but sketch may not converge  (default:1)
  int mean_ax,mean_ay,mean_az,mean_gx,mean_gy,mean_gz,state=0;
  
  Serial.println(F("\nMPU6050 Calibration Sketch"));
  delay(2000);
  Serial.println(F("\nYour MPU6050 should be placed in horizontal position, with package letters facing up. \nDon't touch it until you see a finish message.\n"));
  delay(3000);
  // verify connection
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
  delay(1000);
  // reset offsets
  mpu.setXAccelOffset(0);
  mpu.setYAccelOffset(0);
  mpu.setZAccelOffset(0);
  mpu.setXGyroOffset(0);
  mpu.setYGyroOffset(0);
  mpu.setZGyroOffset(0);
  Serial.println(F("\nReading sensors for first time..."));

///////////////////////////////////////////////////////////////mean sensors function
  
  long i=0,buff_ax=0,buff_ay=0,buff_az=0,buff_gx=0,buff_gy=0,buff_gz=0;

  while (i<(buffersize+101)){
    // read raw accel/gyro measurements from device
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    if (i>100 && i<=(buffersize+100)){ //First 100 measures are discarded
      buff_ax=buff_ax+ax;
      buff_ay=buff_ay+ay;
      buff_az=buff_az+az;
      buff_gx=buff_gx+gx;
      buff_gy=buff_gy+gy;
      buff_gz=buff_gz+gz;
    }
    if (i==(buffersize+100)){
      mean_ax=buff_ax/buffersize;
      mean_ay=buff_ay/buffersize;
      mean_az=buff_az/buffersize;
      mean_gx=buff_gx/buffersize;
      mean_gy=buff_gy/buffersize;
      mean_gz=buff_gz/buffersize;
    }
    i++;
    delay(2); //Needed so we don't get repeated measures
  }
//////////////////////////////////////////////////////////////////mean sensors finish
  
  delay(1000);
  Serial.println(F("\nCalculating offsets..."));
////////////////////////////////////////////////////////// calibration function
  
  ax_offset=-mean_ax/8;
  ay_offset=-mean_ay/8;
  az_offset=(16384-mean_az)/8;

  gx_offset=-mean_gx/4;
  gy_offset=-mean_gy/4;
  gz_offset=-mean_gz/4;
  while (1){
    int ready=0;
    mpu.setXAccelOffset(ax_offset);
    mpu.setYAccelOffset(ay_offset);
    mpu.setZAccelOffset(az_offset);

    mpu.setXGyroOffset(gx_offset);
    mpu.setYGyroOffset(gy_offset);
    mpu.setZGyroOffset(gz_offset);

//////////////////////////////////////////////////////////////////////////// meansensors function
  
  long i=0,buff_ax=0,buff_ay=0,buff_az=0,buff_gx=0,buff_gy=0,buff_gz=0;

  while (i<(buffersize+101)){
    // read raw accel/gyro measurements from device
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    if (i>100 && i<=(buffersize+100)){ //First 100 measures are discarded
      buff_ax=buff_ax+ax;
      buff_ay=buff_ay+ay;
      buff_az=buff_az+az;
      buff_gx=buff_gx+gx;
      buff_gy=buff_gy+gy;
      buff_gz=buff_gz+gz;
    }
    if (i==(buffersize+100)){
      mean_ax=buff_ax/buffersize;
      mean_ay=buff_ay/buffersize;
      mean_az=buff_az/buffersize;
      mean_gx=buff_gx/buffersize;
      mean_gy=buff_gy/buffersize;
      mean_gz=buff_gz/buffersize;
    }
    i++;
    delay(2); //Needed so we don't get repeated measures
  }

    
///////////////////////////////////////////////////////////////meansensors finish
    Serial.println(F("..."));

    if (abs(mean_ax)<=acel_deadzone) ready++;
    else ax_offset=ax_offset-mean_ax/acel_deadzone;

    if (abs(mean_ay)<=acel_deadzone) ready++;
    else ay_offset=ay_offset-mean_ay/acel_deadzone;

    if (abs(16384-mean_az)<=acel_deadzone) ready++;
    else az_offset=az_offset+(16384-mean_az)/acel_deadzone;

    if (abs(mean_gx)<=giro_deadzone) ready++;
    else gx_offset=gx_offset-mean_gx/(giro_deadzone+1);

    if (abs(mean_gy)<=giro_deadzone) ready++;
    else gy_offset=gy_offset-mean_gy/(giro_deadzone+1);

    if (abs(mean_gz)<=giro_deadzone) ready++;
    else gz_offset=gz_offset-mean_gz/(giro_deadzone+1);

    if (ready==6) break;
  }
  
//////////////////////////////////////////////////////////////////////function finish
  
  Serial.println(F("\nFINISHED!"));
  Serial.print(F("Your offsets:\t"));
    Serial.print(ax_offset); 
    Serial.print("\t");
    Serial.print(ay_offset); 
    Serial.print("\t");
    Serial.print(az_offset); 
    Serial.print("\t");
    Serial.print(gx_offset); 
    Serial.print("\t");
    Serial.print(gy_offset); 
    Serial.print("\t");
    Serial.println(gz_offset); 
    Serial.println(F("\nData is printed as: acelX acelY acelZ giroX giroY giroZ"));
    Serial.println(F("Check that your sensor readings are close to 0 0 16384 0 0 0"));
    Serial.println(F("If calibration was succesful write down your offsets so you can set them in your projects using something similar to mpu.setXAccelOffset(youroffset)"));
    mpu.setXAccelOffset(ax_offset);
    mpu.setYAccelOffset(ay_offset);
    mpu.setZAccelOffset(az_offset);
    mpu.setXGyroOffset(gx_offset);
    mpu.setYGyroOffset(gy_offset);
    mpu.setZGyroOffset(gz_offset);
}

