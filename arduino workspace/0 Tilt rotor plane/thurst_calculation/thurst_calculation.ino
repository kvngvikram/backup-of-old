#include <SoftwareSerial.h>
SoftwareSerial BT ( 4 , 5 );
int y = 30 ;
char x ;
void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  BT.write("SEnd sOmEThinG");
  while(Serial.available()<0){
    
  }
  while(BT.available()<0){
    
  }
  x=BT.read();
 
  BT.println("Start");
  Serial.println("Start");
  delay(1000);
  pinMode(9,OUTPUT);
  analogWrite(9 , 10);
  BT.println(10);
  Serial.println(10);
  delay(1000);
  analogWrite(9 , 255);
  BT.println(255);
  Serial.println(255);
  delay(5000);
  analogWrite(9 , 0 );
  BT.println(0);
  Serial.println(0);
  delay(5000);
  analogWrite(9 , 30 );
  BT.println(y);
  Serial.println(y);
  delay(1000);
  Serial.println("get ready dude");

}

void loop() {
  if(BT.available()){
     x = BT.read();
    if(x=='F'){
      if(y<255)y++;
      analogWrite(9,y);
    }
    else if(x=='B'){
      if(y>0)y--;
      analogWrite(9,y);
    }
    else if (x=='S');
    else {
      y=1;
      analogWrite(9,y);
    }
  }
  BT.println(y);
  Serial.println(y);
  
}
