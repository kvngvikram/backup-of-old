// RECIEVER CODE

  
  #include <VirtualWire.h>
#include <AFMotor.h>
int headlight = A5 , backlight = A0 ;
int s = 255 ;
AF_DCMotor lmotor(4);
AF_DCMotor rmotor(3);
void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_rx_pin(A1);//Receiver at Digital Pin 2
    vw_rx_start();// Start the receiver PLL running

    

}

void loop()
{
  
  
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

   
  
  for (i = 0; i < buflen; i++)
  {
      Serial.print(buf[i]);
        if(buf[i] == 'F')
        {
                Serial.println("front");  
      rmotor.run(FORWARD);
      rmotor.setSpeed(s);  
      lmotor.run(FORWARD);
      lmotor.setSpeed(s);  
      }
       if(buf[i] == 'B')
      {
      Serial.println("back");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(s);  
      }
        if(buf[i] == 'S')
      {
      Serial.println("stop_____");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(0);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(0);  
      }
        if(buf[i] == 'L')
      {
      Serial.println("turning left");  
      rmotor.run(FORWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(s);  
      }
        if(buf[i] == 'R')
        {
      Serial.println("turning right");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(s);  
      lmotor.run(FORWARD);
      lmotor.setSpeed(s);  

        }
        if(buf[i] == 'G')
      {
      Serial.println("going left");  
      rmotor.run(FORWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(0);  
      }
        if(buf[i] == 'H')
      {
      Serial.println("back right");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(0);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(s);  
      }
        if(buf[i] == 'I')
      {
      Serial.println("going right");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(0);  
      lmotor.run(FORWARD);
      lmotor.setSpeed(s);  

      }
        if(buf[i] == 'J')
      {
      Serial.println("back left");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(0);  

      }
        if(buf[i] == 'W')
      {
      Serial.println("headlight ON");  
      digitalWrite(headlight , HIGH );

      }
        if(buf[i] == 'U')
      {
      Serial.println("backlight ON");  
      digitalWrite(backlight , HIGH );

      }
        if(buf[i] == 'V')
      {
         Serial.println("V");
      }
        if(buf[i] == 'u')
      {
      Serial.println("backlight OFF");  
      digitalWrite(backlight , LOW );  

      }
        if(buf[i] == 'v')
      {
         Serial.println("v");
      }
        if(buf[i] == 'w')
      {
      Serial.println("headlight OFF");  
      digitalWrite(headlight , LOW );   

      }
        if(buf[i] == '0')
      {
         s=0;
         Serial.println("0");
      }
        if(buf[i] == '1')
      {
         s=28;
         Serial.println("1");
      }
        if(buf[i] == '2')
      {
         s=57;
         Serial.println("2");
      }
        if(buf[i] == '3')
      {
         s=65;
         Serial.println("3");
      }
        if(buf[i] == '4')
      {
         s=113;
         Serial.println("4");
      }
        if(buf[i] == '5')
      {
         s=141;
         Serial.println("5");
      }
        if(buf[i] == '6')
      {
         s=170;
         Serial.println("6");
      }
        if(buf[i] == '7')
      {
         s=199;
         Serial.println("7");
      }
        if(buf[i] == '8')
      {
         s=226;
         Serial.println("8");
      }
        if(buf[i] == '9')
      {
         s=255;
         Serial.println("9");
      }
      
  }//close for loop
  


   }//close main if
}//close loop
//you can print the data entered when debugging by adding Serial.println

////////////////////////////////////////////////////////////////////////////////////////


