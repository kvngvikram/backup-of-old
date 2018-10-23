void setup() {
  pinMode(A0 , INPUT );
  pinMode(A5 , INPUT );
  pinMode(A1 , INPUT );
  pinMode(A2 , INPUT );
  pinMode(A3 , INPUT );
  pinMode(A4 , INPUT );  
  Serial.begin(9600);

}

void loop() {
   int fr = digitalRead(A0);
   int fl = digitalRead(A1);
   int rr = digitalRead(A2);
   int lr = digitalRead(A3)
   int rl = digitalRead(A4);
   int ll = digitalRead(A5);
      Serial.println(fr);
      Serial.println(fl);
      Serial.println(rr);
      Serial.println(lr);
      Serial.println(ll);
      Serial.println(rl);
      Serial.print("\n\n");
      delay(100);
   

}
