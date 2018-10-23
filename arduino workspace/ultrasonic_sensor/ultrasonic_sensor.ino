

    #define echoPin 11 // Echo Pin
    #define trigPin 12 // Trigger Pin
     
    float duration, distance; // Duration used to calculate distance
     
    void setup() {
     Serial.begin (9600);
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
    }
     
    void loop() {
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
     
     Serial.println(distance);
     
     delay(50);
    }


