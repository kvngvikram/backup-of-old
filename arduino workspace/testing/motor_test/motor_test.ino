#include <AFMotor.h>
AF_DCMotor rmotor(3);
AF_DCMotor lmotor(4);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
 
   rmotor.run(FORWARD);
   lmotor.run(FORWARD);
   lmotor.setSpeed(105);
   rmotor.setSpeed(105);


}
