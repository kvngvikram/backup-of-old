#include <pitches.h>
int melody[89]={
  NOTE_B0,                                                                                                        //0  
  NOTE_C1,NOTE_CS1,NOTE_D1,NOTE_DS1,NOTE_E1,NOTE_F1,NOTE_FS1,NOTE_G1,NOTE_GS1,NOTE_A1,NOTE_AS1,NOTE_B1,           //12
  NOTE_C2,NOTE_CS2,NOTE_D2,NOTE_DS2,NOTE_E2,NOTE_F2,NOTE_FS2,NOTE_G2,NOTE_GS2,NOTE_A2,NOTE_AS2,NOTE_B2,           //24
  NOTE_C3,NOTE_CS3,NOTE_D3,NOTE_DS3,NOTE_E3,NOTE_F3,NOTE_FS3,NOTE_G3,NOTE_GS3,NOTE_A3,NOTE_AS3,NOTE_B3,           //36
  NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4,           //48
  NOTE_C5,NOTE_CS5,NOTE_D5,NOTE_DS5,NOTE_E5,NOTE_F5,NOTE_FS5,NOTE_G5,NOTE_GS5,NOTE_A5,NOTE_AS5,NOTE_B5,           //60
  NOTE_C6,NOTE_CS6,NOTE_D6,NOTE_DS6,NOTE_E6,NOTE_F6,NOTE_FS6,NOTE_G6,NOTE_GS6,NOTE_A6,NOTE_AS6,NOTE_B6,           //72
  NOTE_C7,NOTE_CS7,NOTE_D7,NOTE_DS7,NOTE_E7,NOTE_F7,NOTE_FS7,NOTE_G7,NOTE_GS7,NOTE_A7,NOTE_AS7,NOTE_B7,           //84
  NOTE_C8,NOTE_CS8,NOTE_D8,NOTE_DS8                                                                               //89
};
char note[89][3]={
  {'b','n','0'},
  {'c','n','1'},{'c','s','1'},{'d','n','1'},{'d','s','1'},{'e','n','1'},{'f','n','1'},{'f','s','1'},{'g','n','1'},{'g','s','1'},{'a','n','1'},{'a','s','1'},{'b','n','1'},
  {'c','n','2'},{'c','s','2'},{'d','n','2'},{'d','s','2'},{'e','n','2'},{'f','n','2'},{'f','s','2'},{'g','n','2'},{'g','s','2'},{'a','n','2'},{'a','s','2'},{'b','n','2'},
  {'c','n','3'},{'c','s','3'},{'d','n','3'},{'d','s','3'},{'e','n','3'},{'f','n','3'},{'f','s','3'},{'g','n','3'},{'g','s','3'},{'a','n','3'},{'a','s','3'},{'b','n','3'},
  {'c','n','4'},{'c','s','4'},{'d','n','4'},{'d','s','4'},{'e','n','4'},{'f','n','4'},{'f','s','4'},{'g','n','4'},{'g','s','4'},{'a','n','4'},{'a','s','4'},{'b','n','4'},
  {'c','n','5'},{'c','s','5'},{'d','n','5'},{'d','s','5'},{'e','n','5'},{'f','n','5'},{'f','s','5'},{'g','n','5'},{'g','s','5'},{'a','n','5'},{'a','s','5'},{'b','n','5'},
  {'c','n','6'},{'c','s','6'},{'d','n','6'},{'d','s','6'},{'e','n','6'},{'f','n','6'},{'f','s','6'},{'g','n','6'},{'g','s','6'},{'a','n','6'},{'a','s','6'},{'b','n','6'},
  {'c','n','7'},{'c','s','7'},{'d','n','7'},{'d','s','7'},{'e','n','7'},{'f','n','7'},{'f','s','7'},{'g','n','7'},{'g','s','7'},{'a','n','7'},{'a','s','7'},{'b','n','7'},
  {'c','n','8'},{'c','s','8'},{'d','n','8'},{'d','s','8'}
};
void speak(){
}
void show(int s){
  switch (note[s][0]){
    case 'a' :  digitalWrite( a1 , HIGH );  digitalWrite( b1 , HIGH );  digitalWrite( c1 , HIGH );  digitalWrite( d1 , LOW  );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , HIGH );  digitalWrite( g1 , LOW  );    break;
    case 'b' :  digitalWrite( a1 , HIGH );  digitalWrite( b1 , HIGH );  digitalWrite( c1 , HIGH );  digitalWrite( d1 , HIGH );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , HIGH );  digitalWrite( g1 , HIGH );    break;
    case 'c' :  digitalWrite( a1 , HIGH );  digitalWrite( b1 , LOW  );  digitalWrite( c1 , LOW  );  digitalWrite( d1 , HIGH );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , HIGH );  digitalWrite( g1 , LOW  );    break;
    case 'd' :  digitalWrite( a1 , LOW  );  digitalWrite( b1 , HIGH );  digitalWrite( c1 , HIGH );  digitalWrite( d1 , HIGH );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , LOW  );  digitalWrite( g1 , HIGH );    break;
    case 'e' :  digitalWrite( a1 , HIGH );  digitalWrite( b1 , LOW  );  digitalWrite( c1 , LOW  );  digitalWrite( d1 , HIGH );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , HIGH );  digitalWrite( g1 , HIGH );    break;
    case 'f' :  digitalWrite( a1 , HIGH );  digitalWrite( b1 , LOW  );  digitalWrite( c1 , LOW  );  digitalWrite( d1 , LOW  );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , HIGH );  digitalWrite( g1 , HIGH );    break;
    case 'g' :  digitalWrite( a1 , HIGH );  digitalWrite( b1 , LOW  );  digitalWrite( c1 , HIGH );  digitalWrite( d1 , HIGH );  digitalWrite( e1 , HIGH );  digitalWrite( f1 , HIGH );  digitalWrite( g1 , LOW  );    break;
    default  :  digitalWrite( a1 , LOW  );  digitalWrite( b1 , LOW  );  digitalWrite( c1 , LOW  );  digitalWrite( d1 , LOW  );  digitalWrite( e1 , LOW  );  digitalWrite( f1 , LOW  );  digitalWrite( g1 , LOW  );    
  }
  if(note[s][1]=='s') digitalWrite( h1 , HIGH );
  else          digitalWrite( h1 , LOW  );
  switch (note[s][2]){
    case '0' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , HIGH );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , HIGH );  digitalWrite( e2 , HIGH );  digitalWrite( f2 , HIGH );  digitalWrite( g2 , LOW  );    break;
    case '1' :  digitalWrite( a2 , LOW  );  digitalWrite( b2 , LOW  );  digitalWrite( c2 , LOW  );  digitalWrite( d2 , LOW  );  digitalWrite( e2 , HIGH );  digitalWrite( f2 , HIGH );  digitalWrite( g2 , LOW  );    break;
    case '2' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , HIGH );  digitalWrite( c2 , LOW  );  digitalWrite( d2 , HIGH );  digitalWrite( e2 , HIGH );  digitalWrite( f2 , LOW  );  digitalWrite( g2 , HIGH );    break;
    case '3' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , HIGH );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , HIGH );  digitalWrite( e2 , LOW  );  digitalWrite( f2 , LOW  );  digitalWrite( g2 , HIGH );    break;
    case '4' :  digitalWrite( a2 , LOW  );  digitalWrite( b2 , HIGH );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , LOW  );  digitalWrite( e2 , LOW  );  digitalWrite( f2 , HIGH );  digitalWrite( g2 , HIGH );    break;
    case '5' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , LOW  );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , HIGH );  digitalWrite( e2 , LOW  );  digitalWrite( f2 , HIGH );  digitalWrite( g2 , HIGH );    break;
    case '6' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , LOW  );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , HIGH );  digitalWrite( e2 , HIGH );  digitalWrite( f2 , HIGH );  digitalWrite( g2 , HIGH );    break;
    case '7' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , HIGH );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , LOW  );  digitalWrite( e2 , LOW  );  digitalWrite( f2 , LOW  );  digitalWrite( g2 , LOW  );    break;
    case '8' :  digitalWrite( a2 , HIGH );  digitalWrite( b2 , HIGH );  digitalWrite( c2 , HIGH );  digitalWrite( d2 , HIGH );  digitalWrite( e2 , HIGH );  digitalWrite( f2 , HIGH );  digitalWrite( g2 , HIGH );    break;   
    default  :  digitalWrite( a2 , LOW  );  digitalWrite( b2 , LOW  );  digitalWrite( c2 , LOW  );  digitalWrite( d2 , LOW  );  digitalWrite( e2 , LOW  );  digitalWrite( f2 , LOW  );  digitalWrite( g2 , LOW  );    
  }
}
void give(int s ){
  switch (s){
    case '0':   
  }
}
void setup(){

ok=digitalRead(okbutton);
while(ok==LOW){
  inc=digitalRead(incpin);
  dec=digitalRead(decpin);
  if(inc==HIGH&&dec==LOW){      s++ ; give(1);  }
  else if(inc==LOW&&dec==HIGH){ s-- ; give(1);  }  
  ok=digitalRead(okbutton);
}

}
void loop(){

}

