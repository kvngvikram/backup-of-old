#include <SoftwareSerial.h>
SoftwareSerial VLC (2,3);
void setup() {
  VLC.begin(300);
  Serial.begin(115200);

}

void loop() {
  if(VLC.available()){
    Serial.println(VLC.read());
  }
}
