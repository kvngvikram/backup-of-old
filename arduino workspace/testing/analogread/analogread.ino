void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(A5));Serial.print("   ");
  Serial.print(analogRead(A4));Serial.print("   ");
  Serial.print(analogRead(A3));Serial.print("   ");
  Serial.println(analogRead(A2));Serial.print("   ");

}
