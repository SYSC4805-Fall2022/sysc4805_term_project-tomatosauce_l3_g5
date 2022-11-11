//#include <Gyro.h>
#include <LRObsSensors.hpp>

void setup() {
 Serial.begin(115200);
 LRObsSensorssetup();

}

void loop() {
  Serial.println(checkLeftRight());
  delay(1000);
}
