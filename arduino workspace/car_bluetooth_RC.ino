//            Bluetooth car
/*
 * 
 * This code if for the Bluetooth controlled car using HC-05 bluetooth module and " Car Bluetooth RC " android app
 * HC-05 bluetooth module has device name "HC-05" and password " 1234 "  and is in 'Slave mode' by default 
 * if you want you can change them by AT commands 
 * pair your android device with the module , download install and run Car Bluetooth RC android app
 * press play button and connect to the module
 * 
 * the code is for the car which has two motors , left and right 
 * for turning it changes the motion of the left and right wheels 
 */



#include <SoftwareSerial.h>
#include <AFMotor.h>            // library for Adafruit motor driver sheild


/*
 * connect Vcc of bluetooth module to 3.3V  and ground to module to ground of arduino
 * if the module has a voltage regulator then Vcc of module can be connected to 5V Vcc of arduino
 * 
 * 
 * Starting a Serial communication named BT 
 * A5 is the RX (receive) pin for this communication
 * A4 is the TX (transmit) pin for this communication
 * connect TX of bluetooth module to RX i.e A5
 * 
 * if you don't want to use some other serial communication instead use 'Serial' then don't defint BT serial
 * don't start BT serial (BT.begin(9600);)
 * replace 'BT' in the below contitons with 'Serial'
 * connect TX of bluetooth module to digital pin '0' 
 */
SoftwareSerial BT(A5, A4); // RX, TX

//defining pins
int headlight = 2 ;
int backlight = 10 ;
int sound = 9 ;


int s = 100 ;     //variable for speed
int count = 0 ;   //variable to count will if explained later


char input;       //input received from bluetooth module  



/*
 * defining the motors , left motor and right motor in the Adafruit motor driver sheild
 * if not using this sheild these two lines are not needed
 */
AF_DCMotor lmotor(4);
AF_DCMotor rmotor(3);



void setup() 
  {  
    Serial.begin(250000); // starting Serial with baud rate 250000
    while (!Serial) {
      ;   // wait for serial port to connect. Needed for native USB port only
    }
    BT.begin(9600);    // starting serial named BT with baud rate 9600
    Serial.println("Start");  
  }  




void loop() {  

  if(BT.available())  // if something is received from BT serial
  {  
  
    input= BT.read();  // input is read 
    
    
    if(input=='F')  // to froward if character 'F' is received
    {  
      /*now car should move forward
       *  
       *if you are using some other motor driver for example L293D then define motor pins and write  
       *            
       *            digitalWrite(left_motor_pinA , HIGH );
       *            digitalWrite(left_motor_pinB , LOW  );
       *            digitalWrite(left_motor_pinA , HIGH );
       *            digitalWrite(left_motor_pinB , LOW  );
       *            
       *if you are using L298D motor driver the for speed control for motors write these code next to the above digitalWrite lines            
       *        
       *            analogWrite(left_motor_speed_pin  , s );
       *            analogWrite(right_motor_speed_pin , s );
       *
       *use similarly for other movements also            
       *if using moter driver sheild use the below codes            
       */
      //  Serial.println("front");  // uncomment this to see messages in the serial moniter 
      rmotor.run(FORWARD);        //right motor turn forward at a speed of s
      rmotor.setSpeed(s);  
      lmotor.run(FORWARD);        //left motor turn forward at a speed of s
      lmotor.setSpeed(s);  
    }  
    else if(input=='B')  // move backward if character 'B' is received
    {  
    //  Serial.println("back");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(s);  
    }  
    else if(input=='R')  // turning right staying at the same position
    {  
    //  Serial.println("turning right");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(s);  
      lmotor.run(FORWARD);
      lmotor.setSpeed(s);  
    }  
    else if(input=='L')    // turning left staying at the same position
    {  
    //  Serial.println("turning left");  
      rmotor.run(FORWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(s);  
    }  
    else if(input=='G')  // taking left turn
    {  
    //  Serial.println("going left");  
      rmotor.run(FORWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(0);  
    }  
    else if(input=='I')  // taing right turn
    {  
    //  Serial.println("going right");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(0);  
      lmotor.run(FORWARD);
      lmotor.setSpeed(s);  
    }  
    else if(input=='H')  // going rightward towards back
    {  
    //  Serial.println("back right");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(0);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(s);  
    }  
    else if(input=='J')  // going leftward towards back
    {  
    //  Serial.println("back left");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(s);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(0);  
    }  

    else if(input=='W')  //oning headlight 
    {  
    //  Serial.println("headlight ON");  
      digitalWrite(headlight , HIGH );
    }  
    else if(input=='w')  //offing headlight
    {  
    //  Serial.println("headlight OFF");  
      digitalWrite(headlight , LOW );   
    }  
    else if(input=='U')  //oning backlight
    {  
    //  Serial.println("backlight ON");  
      digitalWrite(backlight , HIGH );
    }  
    else if(input=='u')  //offing backlight
    {  
    //  Serial.println("backlight OFF");  
      digitalWrite(backlight , LOW );  
    }  
    else if(input=='V')  // sound on
    {  
      /*
       * sound made using piezeo speaker 
       * connect one terminal of pizeo to the pin 9 (sound) and the other to ground
       * sound made using 'tone' function
       * 
       *          tone( piezeo_pin , frequency_in_hertz );
       * 
       * sound will not stop till character 'v' is received          
       */
    //  Serial.println("sound ON");  
      tone(sound , 1000 );  
    }  
    else if(input=='v')  
    {  
      /*
       * Above tone function is called without time duration , but it can be called with a time duration also 
       * 
       *            tone( piexeo_pin , frequency , time_duraion_in_milliseconds );
       *            
       * now sound will come for the duration and stops , if duraion is not given it will not stop           
       */
    //  Serial.println("sound OFF");  
      tone(sound , 400 , 10);   // give a tone for 10 milliseconds and stop
    }  


    
    /*
     * there are ten levels of speed in the app 
     * variable for speed 's' can have values form 0 to 255 
     * assigning value of s for each speed level from 0 to 9
     * motors always run at a speed s , top speed is 255 i.e. full 
     */
    else if(input=='0'){ s = 0    ;   /*   Serial.println("0");  */}
    else if(input=='1'){ s = 28   ;   /*   Serial.println("1");  */}
    else if(input=='2'){ s = 57   ;   /*   Serial.println("2");  */}
    else if(input=='3'){ s = 85   ;   /*   Serial.println("3");  */}
    else if(input=='4'){ s = 113  ;   /*   Serial.println("4");  */}
    else if(input=='5'){ s = 141  ;   /*   Serial.println("5");  */}
    else if(input=='6'){ s = 170  ;   /*   Serial.println("6");  */}
    else if(input=='7'){ s = 199  ;   /*   Serial.println("7");  */}
    else if(input=='8'){ s = 226  ;   /*   Serial.println("8");  */}
    else if(input=='9'){ s = 255  ;   /*   Serial.println("9");  */} 
    
    
  
    else {        //if any other character is sent then stop , if no button is pressed character 'S' is sent
    //  Serial.println("stop");  
      rmotor.run(BACKWARD);
      rmotor.setSpeed(0);  
      lmotor.run(BACKWARD);
      lmotor.setSpeed(0);  
        
    }
  }  



  /*
   * if any character other than above is received the car stops 
   * if the signal is lost then there will be no serial so car should stop 
   * app sends characters at a particular time intervels 
   * arduino will not get any serial if it checks in between the time intervels of app
   * when there is no serial then there are two cases 
   * 1) connection lost :- will not get a input at all
   * 2) arduino checked in between :-  will get input if it waits for some time
   */
  else {  
    while(BT.available()==0){   // condition of while loop , if there is no input
      count++;                  // variable count is added one , i.e. measuring time 
                                // see the delay time at the end of while loop 
      if(count > 300 ){         // if count is more then 300 , i.e. no input for 300*5=1500milliseconds
      //  Serial.println("NO INPUT");
        rmotor.run(BACKWARD);   // if there is no input for 1.5 seconds then consider connection lost and stop
        rmotor.setSpeed(0);  
        lmotor.run(BACKWARD);
        lmotor.setSpeed(0);
        
        count = 0 ;             // count variable made 0 , next time start counting from 0 
      }
      delay(5);                 //delay time 5 milliseconds 
    }
    /*
     * if input was availabel within 1.5 sec then connection is not lost , count < 300
     * count made 0 for counting in next turn
     * Serial will be available till you read it 
     */
    count=0;                    
    
  }    
}    
