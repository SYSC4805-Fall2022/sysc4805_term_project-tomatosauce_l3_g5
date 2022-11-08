#include "Headers/MotorControl.h"
#include "Headers/LineDetector.h"

void setup() {
  Serial.begin(9600);
  setupMotorControl();
}

void loop() {
  
 
 //right();
  // delay(1000);
  left(17, 0.8);
  // delay(1000);
  // stop();
  // delay(1000);

}
