#include <AFMotor.h>
AF_Stepper motor(200,2);

int echoPin = A0 , trigPin = A1 ; 
float detectoraxisdistance = 25 ;
long count= 0;
float duration , distance ;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  
}

void loop() {
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  
//distance = 34029cmps*duration*10^-6 /2
  distance = duration/58.77;

  count++;
 // Serial.print(count);
 // Serial.print(" ");
 // Serial.print(" degrees --->  ");
  Serial.println(detectoraxisdistance-distance);
  
  if(count<100){
    motor.step(1, FORWARD, MICROSTEP);
    delay(100);
  }
  else if(count == 100){
    count = 0;
    motor.release();
    Serial.println();
    Serial.println();
    Serial.println("One set of readings taken /n Adjust the height of the object and enter the character 's' to proceed for next set");
    Serial.println();
    while(Serial.read()!='s');
    Serial.end();
    Serial.begin(9600);
    delay(100);
  
  }
}
