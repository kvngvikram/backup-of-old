
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  if(results.value==0x4CB0FADF)digitalWrite(13,HIGH);
  else if(results.value==0xDBE32B77) digitalWrite(13,LOW);
  delay(10);
}
