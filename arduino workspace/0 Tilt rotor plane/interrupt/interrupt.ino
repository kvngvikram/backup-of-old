



#include <PinChangeInt.h>
volatile unsigned long lastpulsetime[6] ;
volatile unsigned long firstpulsetime[6];
volatile unsigned long ch[6];
//volatile bool cycle[6]={0,0,0,0,0,0};
////////////////////////////////////////////////////////////
void chfunc1(){
  unsigned long now = micros();
  if(!digitalRead(A0)){
    lastpulsetime[0] = now ;
    ch[0]=lastpulsetime[0]-firstpulsetime[0];
    //cycle[0] = ! cycle[0] ;
  }
  else{
    firstpulsetime[0] = now ;
    //cycle[0] = ! cycle[0] ;
  }
}
void chfunc2(){
  unsigned long now = micros();
  if(!digitalRead(13)){
    lastpulsetime[1] = now ;
    ch[1]=lastpulsetime[1]-firstpulsetime[1];
    //cycle[1] = ! cycle[1] ;
  }
  else{
    firstpulsetime[1] = now ;
    //cycle[1] = ! cycle[1] ;
  }
}
void chfunc3(){
  unsigned long now = micros();
  if(!digitalRead(12)){
    lastpulsetime[2] = now ;
    ch[2]=lastpulsetime[2]-firstpulsetime[2];
    //cycle[2] = ! cycle[2] ;
  }
  else{
    firstpulsetime[2] = now ;
    //cycle[2] = ! cycle[2] ;
  }
}
void chfunc4(){
  unsigned long now = micros();
  if(!digitalRead(4)){
    lastpulsetime[3] = now ;
    ch[3]=lastpulsetime[3]-firstpulsetime[3];
    //cycle[3] = ! cycle[3];
  }
  else{
    firstpulsetime[3] = now ;
    //cycle[3] = ! cycle[3] ;
  }
}
void chfunc5(){
  unsigned long now = micros();
  if(!digitalRead(8)){
    lastpulsetime[4] = now ;
    ch[4]=lastpulsetime[4]-firstpulsetime[4];
    //cycle[4] = ! cycle[4] ;
  }
  else{
    firstpulsetime[4] = now ;
    //cycle[4] = ! cycle[4] ;
  }
}
void chfunc6(){
  unsigned long now = micros();
  if(!digitalRead(7)){
    lastpulsetime[5] = now ;
    ch[5]=lastpulsetime[5]-firstpulsetime[5];
    //cycle[5] = ! cycle[5] ;
  }
  else{
    firstpulsetime[5] = now ;
    //cycle[5] = ! cycle[5] ;
  }
}

////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(4,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(A0,INPUT);
  
  attachPinChangeInterrupt( A0,chfunc1 , CHANGE );
  attachPinChangeInterrupt( 13,chfunc2 , CHANGE );
  attachPinChangeInterrupt( 12,chfunc3 , CHANGE );
  attachPinChangeInterrupt( 4 ,chfunc4 , CHANGE);
  attachPinChangeInterrupt( 8 ,chfunc5 , CHANGE );
  attachPinChangeInterrupt( 7 ,chfunc6 , CHANGE );

}

void loop(){
 // noInterrupts();
  for(int i=0;i<6;i++){
    Serial.print("    ");
    Serial.print(ch[i]);
    }
 // interrupts();
  Serial.println("");
  delay(10);
}
