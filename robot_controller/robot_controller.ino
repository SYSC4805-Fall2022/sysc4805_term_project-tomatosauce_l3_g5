#ifndef ROBOT_CONTROLLER_INO
#define ROBOT_CONTROLLER_INO


#include "Headers/inputs.hpp"
#include "Headers/outputs.hpp"

//#include "Headers/LRObsSensors.hpp"
#include "Headers/MotorControl.hpp"
#include "Headers/ObstacleDetecter.hpp"

#include "Headers/AvoidObstacle.hpp"

#include <string>
using namespace std;

AvoidObstacle avoidObstacle;

Input inputs[15] = {Input::NONE};
void setup() {
  Serial.begin(9600);
  //setupObstacleDetecter();
  //LRObsSensorssetup();
  setupMotorControl();
  ultaobssetup();
 
}

void loop() {
  // //delay(1000);
  Serial.print("STATE: ");
  Serial.println(avoidObstacle.stateToString());
  //Poll Sensors
  // if(checkObstacle()){
	//   inputs[(int)(Input::START_OBSTACLE_AVOIDANCE)] = Input::START_OBSTACLE_AVOIDANCE;
  // }
  // Serial.println(leftSensor());
  // if(obstacleLeft()){
  //   inputs[(int)Input::LEFT_OBSTACLE] = Input::LEFT_OBSTACLE;
  // }
  // if(obstacleRight()){
  //   inputs[(int)Input::RIGHT_OBSTACLE] = Input::RIGHT_OBSTACLE;
  // }
  int val = obscheck();
  Serial.println(val);
  if(val){
    Serial.println("Obstacle Detected");
	inputs[(int)Input::START_OBSTACLE_AVOIDANCE] = Input::START_OBSTACLE_AVOIDANCE;
  }

  //Update State
  avoidObstacle.newInput(inputs);

  //Reset inputs
  
  for(int i = 0; i<15; i++){
    inputs[i] = Input::NONE;
  }
  //Get outputs and update inputs
  switch(avoidObstacle.output){
    case Outputs::TURN_RIGHT:
      right(17, 1);
      delay(1000);
      inputs[(int)(Input::TURN_COMPLETE)] = Input::TURN_COMPLETE;
      break;
    case Outputs::TURN_LEFT:
      left(17, 1);
      delay(1000);
      stop();
      inputs[(int)(Input::DELAY_COMPLETE)]= Input::TURN_COMPLETE;
      break;
    case Outputs::OBSTACLE_AVOIDED:
      break;
	  default:
		  break;
  }
  //Serial.print("Output: ");
  //Serial.println(outputToString(edgeDetected.output));
  // forward(17, 1);
  // while(obscheck()){

  //   stop();
  //   while(true);
  // }
  // Serial.println(obscheck());
 

}

#endif