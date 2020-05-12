#include <SoftwareSerial.h>
SoftwareSerial bt(2,3);

///////// BOTH NL AND CR 
///////// baud rate in serial monitor = 9600
char c,d;
void  setup ()
{
    Serial.begin (9600);
    bt.begin (38400);
    pinMode (4, OUTPUT);
    digitalWrite (4, HIGH);
    Serial.println ( "Enter the AT commands" );
}
 
void  loop ()
{
    if (Serial.available ())
    {
       c = Serial.read();
       bt.write (c);
    }
    if (bt.available ())
    {
        d= bt.read();
        Serial.write (d);
    }
  //  delay (500);
}
