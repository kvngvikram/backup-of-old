volatile float number,speedd , previoustime;


void setup() {
  attachInterrupt( 0 , interrupted , HIGH);
  Serial.begin(115200);

}

void loop() {
  Serial.println(speedd);
  delay(10000);
}

void interrupted(){
  if(millis()-previoustime>1000){
    previoustime = millis();
    speedd=number;
    number = 0;
  }
  else number++;
}
