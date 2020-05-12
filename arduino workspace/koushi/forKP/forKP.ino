

    #define echoPin 11 // Echo Pin
    #define trigPin 12 // Trigger Pin
    float timerequired = 10 , samplefrequency = 36 , gaptime = 5 ; //seconds
    float duration, distance; // Duration used to calculate distance
    float starttime;
    void setup() {
     Serial.begin (9600);
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     starttime = millis();
    }
     
    void loop() {
     if(millis()-starttime > timerequired*1000){
      Serial.println("Break for 5 seconds , adjust the height of object");
      delay(gaptime*1000);
      starttime = millis();
     }
     digitalWrite(13,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     
     digitalWrite(trigPin, LOW);
     duration = pulseIn(echoPin, HIGH);
     
     //Calculate the distance (in cm) based on the speed of sound.
     distance = duration/58.2;
     
     Serial.println(25-distance);
     
     delay((1/samplefrequency)*1000);
    }


