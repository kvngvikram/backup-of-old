/*Code written by KVNG Vikram, Chinmay S Mahtre, Vamshi Bollam and Mathin Yadav during the AeroClub 
 * Summer Project 2016, TILT ROTOR PLANE.
 * This is code for Arduino UNO (microcontroller) of the bicopter(tilt rotor) which controlls the servos and brushless
 * DC motors. It takes the orientation information from the MPU6050 accelerometer gyroscope sensor,
 * gets the data from the radio receiver in the form of PWM signals, uses the PID controller to find
 * the required output for piloting the bicopter acording to the received data and feeds that output 
 * to the two servos and two ESCs(Electronic Speed Controller controlling BLDC motors)in the form of 
 * PWM signals .
 */



/*connections of arduino UNO , MPU 6050, Radio receiver, servos and BLDC motors  
 *  Interrupt 0 or Pin 2 =====> INT pin of MPU
 *  Analog Pin A5 =====> SCL pin of MPU
 *  Analog Pin A4 =====> SDA pin of MPU
 *  PWM Pin 6     =====> Signal pin of left ESC  
 *  PWM Pin 9     =====> Signal pin of right ESC  
 *  PWM Pin 3     =====> Signal pin of left Metal gear servo  
 *  PWM Pin 5     =====> Signal pin of right Metal gar servo  
 *  PWM Pin 11    =====> Signal pin of aileron servo
 *  PWM Pin 10    =====> Signal pin of elevator servo  
 *  Pin A0        =====> Receiver channel 1
 *  Pin 13        =====> Receiver channel 2
 *  Pin 12        =====> Receiver channel 3
 *  Pin 4         =====> Receiver channel 4
 *  Pin 8         =====> Receiver channel 5
 *  Pin 7         =====> Receiver channel 6
 */



/* 
 *  These are the constants for yaw , pitch , roll , height for the PID controller. Yaw Pithc Roll are 
 *  measured by MPU6050 and height is measured bu Ultrasonic distance sensor. These constants are obtained 
 *  by hit and trial method and checking the response. Tests are not yet completed so not all the 
 *  constants are known.
 */
 //             yaw      pitch   roll      height 
float kp[4]={   10     , 40   ,  100    ,    0    };
float ki[4]={   0.0    , 0    ,   0     ,   0.0   };
float kd[4]={  1300    , 1000 , 10000   ,    0.0  };




/*
 * these are the variable used while receiving data from radio reciever. Radio receiver which we used
 * has six channels among which four channels are controlled by the sitcks of the transmitter which give
 * information about yaw pitch roll height and other two channels are toggles . Receiver gives PWM signals 
 * to arduino UNO and arduino UNO reads the signals using interrupts.
 */
unsigned long lch[6];                                  //  variables storing channel data in main loop
int i ;                                                //  variable used in for loops
int pitch=1 , height = 3 , roll = 2 , yaw = 0 ;        //  yaw pitch roll height are assigned numbers for ease of writing 
uint16_t lrec[6] ={900,900,900,900,900,900};           //  lower limit of the PWM singnal from receiver
uint16_t hrec[6] ={2000,2000,2000,2000,2000,2000};     //  upper limit of the PWM singnal from receiver
float ref[4]={0,0,0,0}, yref=0;                        //  set points for yaw pitch roll height and yref for yaw




/*
 * to read the PWM singals pulseIn funciton can be used but there will be huge time lag due
 * to this. So interrupts are used.Working of interrupts will be explained further. For arduino UNO there
 * are only two hardware interrupt pins but we need 6 interrupt pins for receiver and one for MPU6050
 * To increase the number of interrupt pins we used PinChangeInt library which attached software interrupts 
 * to which ever pin required. Here variables are defined as array of 6 for the 6 channels. Use of 
 * lastpulsetime and firstpulsetime will be explained further.
 */
#include "PinChangeInt.h"
volatile unsigned long lastpulsetime[6] ;        
volatile unsigned long firstpulsetime[6];
volatile unsigned long ch[6]={0,0,0,0,0,0};            //  Stores value of PWM in interrupt functions          
/* 
 *  Variable is declared as 'volatile' if it is not assigned or changed in setup or loop functions
 *  but only in interrupt functions. If not declared as 'volatile' compiler will consider it as
 *  constant since it is not changed in setup and loop.
 */




/*
 * to measure the height from ground we are using Ultrasonic sensor which has a range of 5cm to 2m
 * NewPing.h is used to interface with this sensor. Variation of height with different attitudes is 
 * not considered for now
 */
#include "NewPing.h"
NewPing sonar(A1,A2,200);                              //  sensor is defined with A1 as trigger pin, A2 as echo pin and 200 is maximum distance 
float alt = 0 ;                                        //  varable to store altitude





/*
 * To cotrol servos and BLDC motors we used servo library which gives servo and ESC signal via the 
 * signal wire in the form of Pulse Width Modulation (rectangular pulses of 5V and 0V) by changing the
 * width of the pulses. The width of the pulses is between 1000 to 2000 microseconds which corresponds
 * to 0 to 180 degrees in servos and minimum to maximum throttle in BLDC motors. Serov elements are 
 * created for motors and signal can be given to them by servo library functions.
 */
#include "Servo.h"
Servo lservo;                                          //  Left Metal geared servo
Servo rservo;                                          //  Right Metal geared servo
Servo lmot;                                            //  Left BLDC Motor
Servo rmot;                                            //  Right BLDC Motor
Servo elev;                                            //  Servo to control elevator (just created not used)
Servo alrn;                                            //  Serov to control aleron (not used)
int th=1000 ;                                          //  Variable to store throttle of BLDC  




/*
 * The followeing lines are form the MPU 6050 DMP example(I2Cdev MPU6050 class, MotionApps v2.0) by 
 * Jeff Rowberg <jeff@rowberg.net>. No changes are made from the example. 
 */
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
MPU6050 mpu;            // MPU6050 object is created
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
Quaternion q;           // Data type from library to store quaternion which is used to calculate ypr
VectorFloat gravity;    // Data type from library to storegravity vector variable, used to calculate ypr
float ypr[3]={0,0,0};   // [yaw, pitch, roll]  variable which stores value and which is used
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
                                        // when data is ready MPU int pin goes high 




//  Variables to store errors in PID controller. Array corresponds to yaw pitch roll height
float e_old[4]={0,0,0,0} ;              // error in previous instant 
double E[4]={0,0,0,0};                  // sum of error from beguining 




// ================================================================
// ===                        SETUP                             ===
// ================================================================
//  Setup function, executed only once
void setup() {
  

  //  attaching servo objects to pins required using library functions
  lservo.attach(3);
  rservo.attach(5);
  lmot.attach(6);
  rmot.attach(9);
  elev.attach(10);
  alrn.attach(11);

  //  Setting BLDC at low throttles and Metal Geared servos at 90degrees using library functions
  lmot.writeMicroseconds(1000);
  rmot.writeMicroseconds(1000);
  lservo.write(90);
  rservo.write(90);
   

  
  /*
   * Attaching software interrupts using PinChangeInt library function. The working of interrupt is
   * an interrupt is attached to a pin (which is an input) and when ever there is a change in voltage 
   * of that pin the execution of setup or loop function is stopped and interrupt function for that 
   * pin is executed. Only after its completion execution of setup or loop continues. The type of 
   * change for a pin can be defined as 
   * RISING - execute function when pin changes from 0V to 5V
   * FALLING - execute function when pin changes from 5V to 0V
   * CHANGE - execute function when voltage of pin changes(5-0V or 0-5V) 
   * The condition for interrupt function are they should not be returning anything.
   * When an interrupt function is being executed interrupts don't work.
   * There can't be serial communication in the interrupt functions.
   * Here for each channel a function is called. Each function updates the PWM value of that channel
   * in ch[] variable.
   */ 
  attachPinChangeInterrupt( A0,chfunc1 , CHANGE );     //  ( Pin , function , <typr of change> )                     
  attachPinChangeInterrupt( 13,chfunc2 , CHANGE );
  attachPinChangeInterrupt( 12,chfunc3 , CHANGE );
  attachPinChangeInterrupt( 4 ,chfunc4 , CHANGE );
  attachPinChangeInterrupt( 8 ,chfunc5 , CHANGE );
  attachPinChangeInterrupt( 7 ,chfunc6 , CHANGE );



  /*
   * Begining the serial communication. Comment this when arduino is not connected to PC. Used for
   * debugging using serial monitor. Not required during flight.
   */
  Serial.begin(115200);
  while (!Serial);                                     //  Wait till communication established



  /*
   * The following lines are from DMP example where library functions are used. Small changes are 
   * made like using pinchangeInt for MPU interrupt and stopping of execution when mpu 
   * initialisation fails using while loop.
   */
  Wire.begin();                                        //  I2C communication started
  Serial.println(F("Initializing I2C devices..."));
  mpu.initialize();                                    //  For the MPU object 
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

  //  execution waits till some character is entered in serial monitor
  Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available());                 // wait for data
  while (Serial.available() && Serial.read()); // empty buffer again
  
  Serial.println(F("Initializing DMP..."));
  uint8_t devStatus = mpu.dmpInitialize();     //  = 0 if initialisation is successful



  /*
   * These are the 6 offsets 3 for accelerometers and 3 for gyros. These offsets are calculated by 
   * MPU calibration example for a particular orientation and given using library functions. These 
   * are always calculated using calibration example before running this code and given here. By this
   * ypr values are made near zero for this orientation and gyro drifts are reduced.
   */
  mpu.setXAccelOffset(-452);
  mpu.setYAccelOffset(-1742);
  mpu.setZAccelOffset(1860);
  mpu.setXGyroOffset(68);
  mpu.setYGyroOffset(0);
  mpu.setZGyroOffset(-8);

 
  //  If MPU initialisation was successful devStatus=0 else execution stops
  if (devStatus == 0) {
    Serial.println(F("Enabling DMP..."));
    mpu.setDMPEnabled(true);
    Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
    attachPinChangeInterrupt( 2 , dmpDataReady , RISING );    //  Attaching interrupt to pin 2
    mpuIntStatus = mpu.getIntStatus();
    Serial.println(F("DMP ready! Waiting for first interrupt..."));
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else while(1)Serial.println(F("dmp initialization failed"));   // Cannot go out of this loop
  delay(5000);
  Serial.println("Start it ");
}



// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
  while (!mpuInterrupt && fifoCount < packetSize) {
  /*
   * When ever MPU data is ready variable 'mpuInterrupt' is made true by interrupt function 
   * 'dmpDataReady' and while condition is not satisfied. If not while loop continues till MPU 
   * sends an interrupt. While loop also breaks when fifoCount is greater that packetSize. fifoCount
   * is obtained by library function in the main loop.
   * 
   * Till the MPU gives an interrupt other tasks which are not related to MPU can be carried out 
   * in this while loop instead of wasting time.
   */
  }
  mpuInterrupt = false;                        //  so that next interrupt can be detected 
  mpuIntStatus = mpu.getIntStatus();
  fifoCount = mpu.getFIFOCount();              //  Fifo count is obtained
  if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));
  } 
  else if (mpuIntStatus & 0x02) {              //  Going for computation of ypr
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    fifoCount -= packetSize;
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);


    // Uncomment the below lines to print values of yaw pitch roll
/*  
 *   Serial.print("ypr\t");
    Serial.print(ypr[0] * 180/M_PI);
    Serial.print("\t");
    Serial.print(ypr[1] * 180/M_PI);
    Serial.print("\t");
    Serial.println(ypr[2] * 180/M_PI);
*/
  }

  

  // storing the receiver PWM values in local variables to manipulate because ch[] value may change
  // in between.
  noInterrupts();                              // Interrupts are stopped     
  for( i=0;i<6;i++){
    if(ch[i]<hrec[i]&&ch[i]>lrec[i])lch[i]=ch[i];
  }
  interrupts();                                // Interrupts are started              


  
  /*
   * ref[] are the set points and copter always tries to orient itself at these yaw pitch roll 
   * angles. Receriver values are mapped to -5 to 5 degrees of pitch and roll. Height from 0 to
   * 200cm (range of ultrasonic sensor).Yaw from -160 to 160.But code should be improvised for yaw.
   */
  ref[pitch]=map(lch[pitch],1000,2000,-5,5);
  ref[roll]=map(lch[roll],1000,2000,-5,5);
  //ref[height]=map(lch[height],1000,2000,0,200);   // did not use
  yref=map(lch[yaw],1000,2000,-160,160);  


  // For using ultrosonic sensor uncomment these. Library function sonar.ping_cm() returns height
  // in integers.This value is converted into float variable
  /*  
  alt = (float)(sonar.ping_cm());                   // stores value of height  
  // Serial.println(alt); 
  */


  /*
   * Calculating the changes to be made in motors and servos using pid function which takes 
   * ref[i],ypr[i],kp[i],ki[i],kd[i] and i. i=o for yaw,i=1 for pitch, i=2 for roll and i=3
   * for height.
   */
  float delta[4];                                   // variable to store the change         
  for( i=0;i<3;i++)delta[i]=pid(ref[i],ypr[i],kp[i],ki[i],kd[i],i);
  // delta[3]=pid(ref[3],alt,kp[3],ki[3],kd[3],3);


  /* 
   * the following lines are to change the speed of BLDC by serial monitor during testing 
   * without ultrasonic sensor. Comment these during flight.
   */
  // from here 
  if(Serial.available()) {                          // if something is entered in serial monitor         
    int getting = Serial.parseInt();                // read that integer value
    Serial.println("Got ");                         // say that you got something
    if(getting<2000&&getting>=1000){                // only if that value is possible to set
                                                    // i.e. between 1000 to 2000us    
      if(getting>th){                               // check weather to increase or decrease the present one  
        for(;getting>th;th++){                      // increase in small steps.
          lmot.writeMicroseconds(th);               // sending signal
          rmot.writeMicroseconds(th);               // sudden change makes motor to draw high currents
          delay(100);                               // how quick to change
          }
      }
      else if(getting<th){                          // if should be decreased  
        for(;getting<th;th--){
          lmot.writeMicroseconds(th);
          rmot.writeMicroseconds(th);
          delay(100);
          }
      }
    }
    Serial.println("done");                         // send message that change is made 
  }
  // till here



  // adding the change to the values of servos and motors 
  unsigned int thlservo = 87 + delta[0] - delta[1] ;            //left servo
  unsigned int thrservo = 85 + delta[0] + delta[1] ;            //right servo
  unsigned int thlmot = th + delta[2] /*+ delta[4]*/ ;          //left motor  
  unsigned int thrmot = th - delta[2] /*+ delta[4] */;          //right motor
  /*
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
  */

  // checking weather outputs are meaningful and sending the corresponding PWM signal
  if(thlservo<180&&thlservo>0)lservo.write(thlservo);          
  if(thrservo<180&&thrservo>0)rservo.write(thrservo);
  if(thlmot<1500&&thlmot>990)lmot.writeMicroseconds(thlmot);
  if(thrmot<1500&&thrmot>990)rmot.writeMicroseconds(thrmot);



  
  // End of main loop.
}



// ================================================================
// ===                         FUNCTIONS                        ===
// ================================================================

//
/*
 *this is pid function, returns the change to be made so that copter comes to required orientation. 
 *Here instead of writing different functions for yaw, pitch, roll and height the input argument i
 *decides which one is calculated,  i=0 for yaw,1 for pitch,2 for roll and 3 for height. And in the
 *loop we give constants corresponding to i.
 *
 *simple explanation :
 *Assume that required roll is 0 degrees and copter is in 0degrees roll initially. Now we disturb
 *by increasing the roll by hand by 20degrees and leave it.
 *Kp is measure of how quick it tries to come to 0degrees. If only Kp is given then copter
 *executed Simple Harmonic Motion.
 *Kd is measure of how quick it damps its oscillations. With increase in Kd copters oscillation
 *die out and comes to 0 degrees and stops.
 *When Kp and Kd are present for some values of Kp and Kd there will be no overshooting(will not go
 *to negative roll) but also copter reaches near to 0 degrees but takes time to come to 0degrees. To
 *reduce the time it takes to come to 0 degrees Ki is given. Due to Ki error sums up. The small error
 *is added many times which makes considerable change and this brings it to 0degrees. Due to Ki change
 *will be made if error is present for long time.
 *
 *Either by hit and trial or by modelling good Kp,Ki,Kd values can be found for which there will be
 *no overshooting, comes to required positon very quick and do not oscillate.
 */
//         required_value   sensor_output   proportional  integral   derivative     variable for ypr
float pid(float set_point , float current ,   float kp  , float ki ,  float kd  ,   int i){
  float e , e_dot , outpid ;    // error , change in error , output
  e = set_point - current ;     // error is required - actual 
  e_dot = e - e_old[i] ;        // change in error , ideally it is derivative but we just subract
  E[i]=E[i]+e ;                 // This sums up all the errors from biginning 
  if(E[i]>500){                 // but check that it don't go too large
    /*Serial.println("E overflow");*/
    E[i]=0;
    }                        
  outpid = kp*e + kd*e_dot + ki*E[i] ;         // calculating output     
  e_old[i] = e ;
  return outpid ;                              // returning output for corresponding i  
} 




// interrupt function when DMP data is ready in MPU, mpuInterrupt is made true which results in
// coming out of while loop
void dmpDataReady() {
    mpuInterrupt = true;
}




/*
 * These are interrupt functions to calculate the PWM value of each channel which are executed whenever
 * there is a change in voltage of corresponding pin. When the pulse just arrives, i.e. pin goes from 
 * 0V to 5V due to interrupt main loop execution stops and interrupt function is executed.Voltage of 
 * the pin is read using digitalRead(pin) (which is HIGH now) and concluded that pulse just arrived 
 * and time is stored in firstpulsetime[] variable. Then execution of loop continues. When pulse ends i.e. 
 * voltage on pin goes from 5V to 0V (after 1000 to 2000 microseconds) loop stops. Voltage is read 
 * (which is LOW) and decided that pulse just ended , time is stored in lastpulsetime[] variable. 
 * Difference of firstpulsetime[] and lastpulsetime[] is calculated and updated as ch[], the value of PWM.
 * Value of present time is found by micros() which gives present time from begining from timer in  
 * microseconds.
 */
void chfunc1(){              // yaw
  unsigned long now = micros();                   // Stores present time. 
  if(!digitalRead(A0)){                           // condition satisfied if pulse just ended
    lastpulsetime[0] = now ;                      // ending time stored  
    ch[0]=lastpulsetime[0]-firstpulsetime[0];     // PWM value is calculated
  }
  else{                                           // if pin is HIGH
    firstpulsetime[0] = now ;                     // pulse starting time is stored
  }
}
void chfunc2(){              //pitch
  unsigned long now = micros();
  if(!digitalRead(13)){
    lastpulsetime[1] = now ;
    ch[1]=lastpulsetime[1]-firstpulsetime[1];
  }
  else{
    firstpulsetime[1] = now ;
  }
}
void chfunc3(){              //roll
  unsigned long now = micros();
  if(!digitalRead(12)){
    lastpulsetime[2] = now ;
    ch[2]=lastpulsetime[2]-firstpulsetime[2];
  }
  else{
    firstpulsetime[2] = now ;
  }
}
void chfunc4(){              //height 
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

