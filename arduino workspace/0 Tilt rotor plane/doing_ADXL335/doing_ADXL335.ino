void setup() {
  Serial.begin(9600);
  Serial.println("ADXL335 testing ");
  

}

void loop() {
  analogReference(EXTERNAL);
  int x = analogRead(A0);
  int y = analogRead(A1);
  int z = analogRead(A2);

  Serial.print("  X = ");Serial.print(x-512);  Serial.print("  Y = ");Serial.print(y-512);  Serial.print("  Z = ");Serial.print(z-512);
  Serial.println();Serial.println();
  delay(100);
  

}
