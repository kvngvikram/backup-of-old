float speed_of_transmission = 10 ;
int pin = 2 ;
void transmit(byte a , float baud , int pin ){
  bool b[10]={0,0,0,0,0,0,0,0,0,0};
  for(int i=8;i>0;i--)b[i]=bitRead(a,i);
  for(int i=0;i<10;i++){
    digitalWrite(pin,b[i]);
    wait(baud);
  }
  digitalWrite(pin,HIGH);
}
void wait(float baud ){
  float t = (1/baud)*1000;
  int t1=millis();
  while(millis()<t1+t);
}
void setup() {
  Serial.begin(115200);
  pinMode(pin,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  if(Serial.available()){
    digitalWrite(13,HIGH);
    byte a = Serial.read();
    while(Serial.available())Serial.read();
    for(int i=7;i>=0;i--){
      bool s=bitRead(a,i);
      Serial.print(s);
    }
    Serial.println();
    transmit(a,speed_of_transmission,pin);
    digitalWrite(13,LOW);
  }
}
