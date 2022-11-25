#ifndef ROBOT_CONTROLLER_INO
#define ROBOT_CONTROLLER_INO

#include <vector>
#include "Headers/inputs.hpp"
#include "Headers/EdgeDetected.hpp"
#include "Headers/outputs.hpp"
#include <string>
using namespace std;

EdgeDetected edgeDetected;
void setup() {
  Serial.begin(9600);
  
  
}

void loop() {
  Input input2[20];
  Serial.println(edgeDetected.currentState);
  delay(2000);
  input2[0]=(Input::START_EDGE_DETECTED);
  edgeDetected.newInput(input2);
  
 

}

#endif