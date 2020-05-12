#include <AFMotor.h>
int turndelay = 350 ;
int t = 1 ;
int h = 0 ;
int d = 50 ;            // d is time to cross the cut gap of length l in the line
int s = 100 ;            // s is speed      d = (l/s)+
int ts = 100 ;
int i  ;       // for loop variable in wblank            
int inversiontime = 500 ;
AF_DCMotor rmotor(2);
AF_DCMotor lmotor(1);
int fl ;
int fr ;
int ll ;
int rl ;
int lr ;
int rr ;
void setup() {
  pinMode(A0 , INPUT );
  pinMode(A5 , INPUT );
  pinMode(A1 , INPUT );
  pinMode(A2 , INPUT );
  pinMode(A3 , INPUT );
  pinMode(A4 , INPUT );  
  Serial.begin(9600);
  
  
}
void slowstraight(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(s);
   rmotor.setSpeed(s);
}
void sleft(){
   rmotor.run(FORWARD);
   lmotor.run(BACKWARD);
   lmotor.setSpeed(s);
   rmotor.setSpeed(s);
}
void sright(){
   rmotor.run(BACKWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(s);
   rmotor.setSpeed(s);
}
void right(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(s);
   rmotor.setSpeed(0);
}
void fright(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(ts);
   rmotor.setSpeed(s);
}
void left(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(0);
   rmotor.setSpeed(s);
}
void fleft(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(s);
   rmotor.setSpeed(ts);
}
void straight(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(150);
   rmotor.setSpeed(150);
}
void freeze(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(0);
   rmotor.setSpeed(0);
   delay(400);
}
void wblank(){  
  int n = d/10 ;
  for(  i = 0 ; fl==HIGH&&fr==HIGH&&ll==HIGH&&lr==HIGH&&rl==HIGH&&rr==HIGH&&i<=n ; i++ ){
    slowstraight();
    delay(10);
    fl =  digitalRead( A5 );
    fr =  digitalRead( A4 );
    ll =  digitalRead( A3 );
    rl =  digitalRead( A1 );
    lr =  digitalRead( A2 );
    rr =  digitalRead( A0 );  
  }
  if(i>=n) {
  rmotor.run(BACKWARD);
  lmotor.run(BACKWARD);
  lmotor.setSpeed(s);
  rmotor.setSpeed(s);
  delay(d + 50 );
  fl =  digitalRead( A5 );
  fr =  digitalRead( A4 );
  while ( fl ==HIGH && fr ==HIGH ){
   if (t==1) sright();
   else if (t== -1) sleft();
   fl =  digitalRead( A5 );
   fr =  digitalRead( A4 );
  }}
}
void back(){
  rmotor.run(BACKWARD);
  lmotor.run(BACKWARD);
  lmotor.setSpeed(s);
  rmotor.setSpeed(s);
}
void pechemud(){

  

  
}
void bblank(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(ts);
   rmotor.setSpeed(ts);
}

void loop (){
  fl =  digitalRead( A5 );
  fr =  digitalRead( A4 );
  rr =  digitalRead( A0 );
  rl =  digitalRead( A1 ); 
  lr =  digitalRead( A2 ); 
  ll =  digitalRead( A3 ); 
  if( rr ==HIGH && ll ==HIGH ){
    if( lr ==HIGH && rl ==HIGH ){
      if( fr ==LOW && fl ==LOW )  straight();
      else if( fr ==LOW && fl ==HIGH )  fright();
      else if( fr ==HIGH && fl ==LOW )  fleft();
      else if( fr ==HIGH && fl ==HIGH )  wblank();
    } 
    else if( lr ==LOW && rl ==HIGH )  left() ;
    else if( lr ==HIGH && rl ==LOW )  right() ;
    else if( lr ==LOW && rl ==LOW )  straight() ; 
  }
  else if( ll ==LOW && rr ==HIGH ) {
    if( fr ==HIGH && fl ==HIGH ) {
      if( ( lr ==LOW && rl ==HIGH ) || ( lr ==LOW && rl ==LOW ) ) {
      sleft();                                                                                        
      delay(turndelay);
      while(fr==HIGH){
        left();
        fr=digitalRead(A4);
      }
      slowstraight();
      delay(turndelay);
      h = -2 ;
      t = -1 ;
      }
      else if(lr == HIGH && rl == LOW )right();
      else if (lr == HIGH && rl == HIGH ) slowstraight();
    }
    else if(fr==LOW && fl==LOW)slowstraight();
    else if(fr==LOW && fl==HIGH)fright();
    else if(fr==HIGH && fl==LOW)fleft();
  }
      
  else if( ll ==HIGH && rr ==LOW) {
    if( fr ==HIGH && fl ==HIGH ) {
      if( ( rl ==LOW && lr ==HIGH ) || ( rl ==LOW && lr ==LOW ) ) {
      sright();                                                                                        
      delay(turndelay);
      while(fl==HIGH){
        right();
        fl=digitalRead(A5);
      }
      slowstraight();
      delay(turndelay);
      h = 2 ;
      t = 1 ;
      }
      else if(rl == HIGH && lr == LOW )left();
      else if (rl == HIGH && lr == HIGH ) slowstraight();
    }
    else if(fr==LOW && fl==LOW)slowstraight();
    else if(fl==LOW && fr==HIGH)fleft();
    else if(fl==HIGH && fr==LOW)fright();
  }
  else if( ll ==LOW && rr ==LOW ){
    if( lr ==LOW && rl ==HIGH )  left();                                                              // verify
    else if( lr ==HIGH && rl ==LOW )  right();                                                        // verify
    else if( lr ==HIGH && rl ==HIGH )  slowstraight();
    else if( lr ==LOW && rl ==LOW ) {
      
        if( fl ==LOW && fr ==LOW )  bblank();
        else{
          sright();                                                                                        
          delay(turndelay);
          while(fl==HIGH){
            right();
            fl=digitalRead(A5);
          }
          slowstraight();
          delay(turndelay);
        }
        
       
        



    }
    
  }
 
}
