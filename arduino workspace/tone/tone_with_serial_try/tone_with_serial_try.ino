void setup() {
  Serial.begin(9600);
  

}

void loop() {
 
 if (Serial.available()){
  int input=Serial.read();
  tone(9,input);
  Serial.print("playing ");
  Serial.println(input);
 }
 else {
  Serial.println("no serial");
  tone(9,1000);
 }
 
delay(1000);
}

int a[10];
for(i=0;Serial.available();i++){
  a[i] = Serial.read();
}



