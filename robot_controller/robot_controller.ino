#ifndef ROBOT_CONTROLLER_INO
#define ROBOT_CONTROLLER_INO


#include "Headers/inputs.hpp"
#include "Headers/outputs.hpp"

#include "Headers/EdgeDetected.hpp"
#include "Headers/LRObsSensors.hpp"
#include "Headers/MotorControl.hpp"
#include "Headers/LineDetector.hpp"

#include <string>
using namespace std;

EdgeDetected edgeDetected;
Input inputs[15] = {Input::NONE};
void setup() {
  Serial.begin(9600);
  setupMotorControl();
  setupLineDetector();
 
}

void loop() {
  //delay(1000);
  Serial.print("STATE: ");
  Serial.println(edgeDetected.stateToString());
  //Poll Sensors
  if(checkLine()){
	  inputs[(int)(Input::START_EDGE_DETECTED)] = Input::START_EDGE_DETECTED;
  }
  /**if(leftSensor()){
    inputs[(int)Input::LEFT_OBSTACLE] = Input::LEFT_OBSTACLE;
  }
  if(rightSensor()){
    inputs[(int)Input::RIGHT_OBSTACLE] = Input::RIGHT_OBSTACLE;
  }**/

  //Update State
  edgeDetected.newInput(inputs);

  //Reset inputs
  *inputs = {Input::NONE};

  //Get outputs and update inputs
  switch(edgeDetected.output){
	  case Outputs::CHOOSE_DIRECTION:
      inputs[(int)(Input::PREFERRED_DIRECTION_LEFT)] = Input::PREFERRED_DIRECTION_LEFT;
      break;
    case Outputs::TURN_LEFT:
      left(17, 1);
      delay(1000);
      inputs[(int)(Input::TURN_COMPLETE)] = Input::TURN_COMPLETE;
      break;
    case Outputs::FORWARD_ONE_STEP:
      forward(17, 1);
      delay(1000);
      stop();
      inputs[(int)(Input::DELAY_COMPLETE)]= Input::DELAY_COMPLETE;
      break;
    case Outputs::EDGE_DETECTED_COMPLETE:
      while(true);
      break;
	  default:
		  break;
  }
  //Serial.print("Output: ");
  //Serial.println(outputToString(edgeDetected.output));
  
  
 

}

#endif