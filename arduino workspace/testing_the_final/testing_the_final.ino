#include <AFMotor.h>
int t = 1 ;
int d = 100 ;
int s = 175 ;
AF_DCMotor rmotor(1);
AF_DCMotor lmotor(2);
void setup() {
  pinMode(A0 , INPUT );
  pinMode(A5 , INPUT );
  pinMode(A1 , INPUT );
  pinMode(A2 , INPUT );
  pinMode(A3 , INPUT );
  pinMode(A4 , INPUT );  
  pinMode(2 , INPUT );
  Serial.begin(9600);
  int pbt =  digitalRead( 2 );
 
  
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
   lmotor.setSpeed(255);
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
   rmotor.setSpeed(255);
}
void straight(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(255);
   rmotor.setSpeed(255);
}
void freeze(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(0);
   rmotor.setSpeed(0);
}
void wblank(){  
   slowstraight();
  delay(d);
  int fl =  digitalRead( A1 );
  int fr =  digitalRead( A0 );
  if( fr ==HIGH && fl ==HIGH)  pechemud();
  
}
void back(){
  rmotor.run(BACKWARD);
  lmotor.run(BACKWARD);
  lmotor.setSpeed(s);
  rmotor.setSpeed(s);
}
void pechemud(){
   back();
   delay(d);
  int fl =  digitalRead( A1 );
  int fr =  digitalRead( A0 );
  while ( fl ==HIGH || fr ==HIGH ){
   rmotor.run(FORWARD);
   lmotor.run(BACKWARD);
   lmotor.setSpeed(s);
   rmotor.setSpeed(s);
   int fl =  digitalRead( A1 );
   int fr =  digitalRead( A0 );
  }
}
void bblank(){
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(255);
   rmotor.setSpeed(255);
}

void loop (){
  int fl =  digitalRead( A1 );
  int fr =  digitalRead( A0 );
  int rr =  digitalRead( A2 );
  int rl =  digitalRead( A3 ); 
  int lr =  digitalRead( A4 ); 
  int ll =  digitalRead( A5 ); 
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
    if( lr ==HIGH && rl ==HIGH ) {
      if( fr ==LOW || fl ==LOW )  straight();                                                         // verify
      else if( fr ==HIGH && fl ==HIGH )  left();                                                      // verify
    }
    else if( ( lr ==LOW && rl ==HIGH ) || ( lr ==LOW && rl ==LOW ) ) {
      sleft();
      t = -1 ;                                                                                        // verify
    }
    else if( lr ==HIGH && rl ==LOW )  right() ;
  }
  else if( ll ==HIGH && rr ==LOW) {
    if( lr ==HIGH && rl ==HIGH ) {
      if( fr ==LOW || fl ==LOW )  straight();                                                         // verify
      else if( fr ==HIGH && fl ==HIGH )  right();                                                     // verify
    }
    else if( ( lr ==HIGH && rl ==LOW ) || ( lr ==LOW && rl ==LOW ) ) {
      sright();
      t = 1 ;                                                                                         // verify
    }
    else if( lr ==LOW && rl ==HIGH )  left() ;                       
  }
  else if( ll ==LOW && rr ==LOW ){
    if( lr ==LOW && rl ==HIGH )  left();                                                              // verify
    else if( lr ==HIGH && rl ==LOW )  right();                                                        // verify
    else if( lr ==LOW && rl ==LOW ) {
      if( fl ==LOW && fr ==LOW )  bblank();
      else if( fl ==LOW && fr ==HIGH ){
        while( fr ==HIGH ){
             left();
            fr = digitalRead(A0);
          }
      }
      else if( fl ==HIGH && fr ==LOW ){
        while( fl ==HIGH ){
             right();
            fl =digitalRead(A1);
          }
      }
      else if( fl ==HIGH && fr ==HIGH ){
        if( t < 0 ){
          while( fr ==HIGH ){
             left();
            fr = digitalRead(A0);
          }
          t = 1 ;
        }
        else if( t > 0 ){
          while( fl ==HIGH ){
             right();
            fl =digitalRead(A1);
          }
          t = -1 ;
        }
      }
    }
    
  }
  Serial.println(fr);
      Serial.println(fl);
      Serial.println(rr);
      Serial.println(lr);
      Serial.println(ll);
      Serial.println(rl);
      Serial.print("\n\n");
      delay(100);
} 
 
