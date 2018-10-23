/* bluetooth module Vcc to 3.3V
 *                  gnd to gnd 
 *                  TX to pin 5
 *                  RX to pin 6
 */


    char input[100];  
    char output;
    #include <SoftwareSerial.h>
    int i=0;

    SoftwareSerial BT(5, 6); // RX, TX
      
    void setup() 
    {  
      Serial.begin(9600);  
      BT.begin(9600);
   
      
      Serial.println(">> START<<");  

    }  
      
    void loop() 
    {  
      if(BT.available()>0)  
      { 
        i = 0;
        while(BT.available()>0){
          input[i]=BT.read();
          i++;
        }
        Serial.println(input); 
        
      }  
      else if(Serial.available()>0)  
      {  
        output= Serial.read(); 
        BT.write(output); 
      }  
      
    }  
