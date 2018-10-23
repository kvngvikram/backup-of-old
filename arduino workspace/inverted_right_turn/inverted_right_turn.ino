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
void invertedwblank(){  
  int n = d/10 ;
  for(  i = 0 ; fl==LOW&&fr==LOW&&ll==LOW&&lr==LOW&&rl==LOW&&rr==LOW&&i<=n ; i++ ){
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
  while ( fl ==LOW && fr ==LOW ){
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
  if( rr ==LOW && ll ==LOW ){//////////////////
    if( lr ==LOW && rl ==LOW ){
      if( fr ==HIGH && fl ==HIGH )  straight();///////////////////
      else if( fr ==HIGH && fl ==LOW )  fright();//////////////////////
      else if( fr ==LOW && fl ==HIGH )  fleft();
      else if( fr ==LOW && fl ==LOW )  invertedwblank();
    } ///////////////////////
    else if( lr ==HIGH && rl ==LOW )  left() ;
    else if( lr ==LOW && rl ==HIGH )  right() ;
    else if( lr ==HIGH && rl ==HIGH )  straight() ; 
  }//////////////////////////////
  else if( ll ==HIGH && rr ==LOW ) {
    if( fr ==LOW && fl ==LOW ) {/////////////////////////////
      if( ( lr ==HIGH && rl ==LOW ) || ( lr ==HIGH && rl ==HIGH ) ) {
      sleft();    /////////////////////////////                                                                                    
      delay(turndelay);
      while(fr==LOW){
        left();
        fr=digitalRead(A4);
      }
      slowstraight();
      delay(turndelay);
      h = -2 ;
      t = -1 ;
      }////////////////////////////////////////////////////////////
      else if(lr == LOW && rl == HIGH )right();
      else if (lr == LOW && rl == LOW ) slowstraight();
    }///////////////////
    else if(fr==HIGH && fl==HIGH)slowstraight();
    else if(fr==HIGH && fl==LOW)fright();
    else if(fr==LOW && fl==HIGH)fleft();
  }///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
  else if( ll ==LOW && rr ==HIGH) {
    if( fr ==LOW && fl ==LOW ) {
      if( ( rl ==HIGH && lr ==LOW ) || ( rl ==HIGH && lr ==HIGH ) ) {
      sright();     ///////////////////////////////////////////////////////////                                                                                   
      delay(turndelay);
      while(fl==LOW){
        right();
        fl=digitalRead(A5);
      }
      slowstraight();
      delay(turndelay);
      h = 2 ;
      t = 1 ;
      }//////////////////////////////////////////////////////////////////
      else if(rl == LOW && lr == HIGH )left();
      else if (rl == LOW && lr == LOW ) slowstraight();
    }
    else if(fr==HIGH && fl==HIGH)slowstraight();
    else if(fl==HIGH && fr==LOW)fleft();
    else if(fl==LOW && fr==HIGH)fright();
  }//////////////////////////////////////////////////////////////////
  else if( ll ==HIGH && rr ==HIGH ){
    if( lr ==HIGH && rl ==LOW )  left();                                                              // verify
    else if( lr ==LOW && rl ==HIGH )  right();                                                        // verify
    else if( lr ==LOW && rl ==LOW )  slowstraight();
    else if( lr ==HIGH && rl ==HIGH ) {
      
        if( fl ==HIGH && fr ==HIGH )  bblank();
        else{
          sright();                                                                                        
          delay(turndelay);
          while(fl==LOW){
            right();
            fl=digitalRead(A5);
          }
          slowstraight();
          delay(turndelay);
        }
        
       
        



    }
    
  }
 
}
