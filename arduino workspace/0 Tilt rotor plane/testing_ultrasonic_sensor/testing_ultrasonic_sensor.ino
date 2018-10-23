#include <PinChangeInt.h>
volatile int uflag=0;
volatile unsigned long pulsesentat ;
volatile unsigned long  timetaken=0 ;
void setup() {
Serial.begin(9600);
pinMode(4,INPUT);
pinMode(3,OUTPUT);
//attachPinChangeInterrupt(4,usense,RISING);
  

}

void loop() {
  if(uflag==0){
    digitalWrite(3,HIGH);
    delay(1);
    digitalWrite(3,LOW);
    uflag=1;
    pulsesentat=micros();
  }
  while(!digitalRead(4));
  timetaken=micros()-pulsesentat ;
 Serial.print(timetaken);
  Serial.println("is the time");
  
}
void usense(){
  if(uflag==1){
    unsigned long now = micros();
    Serial.print(now);
    timetaken=now-pulsesentat;
    Serial.print("   ");
    Serial.print (pulsesentat);
    Serial.print(" is now,pulsesentat and timetaken in func is ");
    Serial.println(timetaken);
    uflag=0 ;
  }
}

