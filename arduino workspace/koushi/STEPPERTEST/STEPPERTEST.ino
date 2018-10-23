#include <AFMotor.h>
AF_Stepper motor(200,2);
void setup() {
  
for(int i = 0 ; i<100 ; i++){
  motor.step(1,FORWARD,MICROSTEP);
  delay(20);
  }
  
 motor.release();
}

void loop() {
  
}
