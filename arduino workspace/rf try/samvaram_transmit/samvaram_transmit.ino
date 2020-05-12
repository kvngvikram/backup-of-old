#include <SoftwareSerial.h>


// TRANSMITTER CODE




#include <VirtualWire.h>
SoftwareSerial BT(A0 , A2);
void setup()
{
    Serial.begin(9600);    

    BT.begin(9600);    
    Serial.println("setup");

    // Initialise the IO and ISR
     
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(2); //Transmitter Data Pin to Digital Pin 3
}//close setup

void loop()
{
  
  if (BT.available() > 0)
  {
     int sendByte = BT.read();//Starts reading data from the serial monitor once condition is met
     
 
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









    
    
    
    default://if any other value is entered
    {
      
       Serial.println("wrong entry");//print wrong entry in the serial monitor
    }
   }// close switch-case
  }//close if 
 }//close loop
  
 // End Of Code 
