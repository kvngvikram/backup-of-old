#include <VirtualWire.h>
#include <VirtualWire_Config.h>
#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
    #include "Wire.h"
MPU6050 mpu;


bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };



// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}



// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    Wire.begin();
    Serial.begin(115200);
    while (!Serial); 
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
    Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    while (Serial.available() && Serial.read()); // empty buffer
    while (!Serial.available());                 // wait for data
    while (Serial.available() && Serial.read()); // empty buffer again

   
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); 


    if (devStatus == 0) {

        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);


        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else while(1)Serial.println("setup fail");
        
  
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(12); 
    
}



// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    while (!mpuInterrupt && fifoCount < packetSize) {
      if(ypr[1]>20&&ypr[2]<20&&ypr[2]>-20)tosend('F');
      else if(ypr[1]<-20&&ypr[2]<20&&ypr[2]>-20)tosend('B');
      else if(ypr[2]>20&&ypr[1]<20&&ypr[1]>-20)tosend('L');
      else if(ypr[2]<-20&&ypr[1]<20&&ypr[1]>-20)tosend('R');
      else if(ypr[1]>20&&ypr[2]>20)tosend('G');
      else if(ypr[1]<-20&&ypr[2]>20)tosend('J');
      else if(ypr[1]>20&&ypr[2]<-20)tosend('I');
      else if(ypr[1]<-20&&ypr[2]<-20)tosend('H');
      else if(ypr[1]>-20&&ypr[1]<20&&ypr[2]<20&&ypr[2]>-20)tosend('S');
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
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
void tosend(char sendByte){
   switch (sendByte){
 
    case 'F':  //if the controller type f
  {
    
    char *msg2 = "F";
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    Serial.println("front");
    break;
     
  }
    case 'B':  //if controller types b
    {
   char *msg2 = "B";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);  
   break;
    }

    case 'S': //if controller types s
    {
   char *msg2 = "S";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);  
   break;
    }
    
    case 'R': //if controller types s
    {
   char *msg2 = "R";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);  
   break;
    }
    
    case 'L': //if controller types l
  {  
   char *msg2 = "L";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);    
   break;
  }     
    case 'G': //if controller types r
    {
   char *msg2 = "G";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'H': //if controller types r
    {
   char *msg2 = "H";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'I': //if controller types r
    {
   char *msg2 = "I";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'J': //if controller types r
    {
   char *msg2 = "J";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'W': //if controller types r
    {
   char *msg2 = "W";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'w': //if controller types r
    {
   char *msg2 = "w";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'U': //if controller types r
    {
   char *msg2 = "U";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'u': //if controller types r
    {
   char *msg2 = "u";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'V': //if controller types r
    {
   char *msg2 = "V";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case 'v': //if controller types r
    {
   char *msg2 = "v";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }

case '0': //if controller types r
    {
   char *msg2 = "0";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '1': //if controller types r
    {
   char *msg2 = "1";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '2': //if controller types r
    {
   char *msg2 = "2";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '3': //if controller types r
    {
   char *msg2 = "3";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '4': //if controller types r
    {
   char *msg2 = "4";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '5': //if controller types r
    {
   char *msg2 = "5";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '6': //if controller types r
    {
   char *msg2 = "6";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '7': //if controller types r
    {
   char *msg2 = "7";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '8': //if controller types r
    {
   char *msg2 = "8";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }
case '9': //if controller types r
    {
   char *msg2 = "9";
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send byte to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
   digitalWrite(13, false);   
   break;
    }  
    default:;//if any other value is entered
    
    }
}
