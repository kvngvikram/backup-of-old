#include <PinChangeInt.h>


int             a = 0 , b = 1 , c = 2 , d = 3 , e = 4 , f = 5 ; 
int i[6]    = {   0   ,   1   ,   2   ,   3   ,   4   ,   5   } ;  
int o[6]    = {   6   ,   7   ,   8   ,   9   ,   10  ,   11  } ;  
bool pinflag=LOW; 
bool flag = LOW ;
int flagpin = 13 ;  

int sega = A0 ; 
int segb = A1 ; 
int segc = A2 ; 
int segd = A3 ; 
int sege = A4 ;
int segf = A5 ; 
int segg = 12 ; 

volatile unsigned long presstime[6];   
 
void setup() {
  for(int j=0 ; j<6 ; j++) presstime[j]=4294967295;
  attachPinChangeInterrupt( i[a] , apin , RISING);
  attachPinChangeInterrupt( i[b] , bpin , RISING);
  attachPinChangeInterrupt( i[c] , cpin , RISING);
  attachPinChangeInterrupt( i[d] , dpin , RISING);
  attachPinChangeInterrupt( i[e] , epin , RISING);
  attachPinChangeInterrupt( i[f] , fpin , RISING);

}

void loop() {
  delay(5);
  flag = digitalRead(flagpin) ; 
  
  if(flag==HIGH){
    for(int j=0 ; j<6 ; j++)presstime[j]=4294967295;
    while( pinflag == LOW );
    delay(1000);
    unsigned long besttime = 4294967295 ;
    int winner = 0 ; 
    for(int j=0 ; j<6 ; j++ ){
      if (besttime > presstime[j]) {
        besttime = presstime[j];
        winner = j ; 
      }
    }
    for(int j=0 ; j<6 ; j++){
      if(winner == j){
        digitalWrite(o[j],HIGH);
        segdisplay(j+1);
      }
      else digitalWrite(o[j],LOW);
    }
    delay(5000);
  }
}




void apin(){
  pinflag = HIGH ;
  presstime[a]= flag ? micros() : 4294967295;  
}
void bpin(){
  pinflag = HIGH ;
  presstime[b]= flag ? micros() : 4294967295;  
}
void cpin(){
  pinflag = HIGH ;
  presstime[c]= flag ? micros() : 4294967295;  
}
void dpin(){
  pinflag = HIGH ;
  presstime[d]= flag ? micros() : 4294967295;  
}
void epin(){
  pinflag = HIGH ;
  presstime[e]= flag ? micros() : 4294967295;  
}
void fpin(){
  pinflag = HIGH ;
  presstime[f]= flag ? micros() : 4294967295;  
}


void segdisplay(int num){
  switch (num) 
  case  1 : {
    digitalWrite(sega,HIGH);
    digitalWrite(segb,HIGH);
    digitalWrite(segc,HIGH);
    digitalWrite(segd,HIGH);
    digitalWrite(sege,HIGH);
    digitalWrite(segf,HIGH);
    digitalWrite(segg,HIGH);
  }
}

