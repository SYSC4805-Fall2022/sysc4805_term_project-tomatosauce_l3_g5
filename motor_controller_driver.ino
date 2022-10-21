#include "MotorControl.h"
void setup() {
  setupMotorControl();
  Serial.begin(9600);
}

void loop() {
  Serial.println(calculateCounterLeft(60));
  
}
