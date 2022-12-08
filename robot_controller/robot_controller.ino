#ifndef ROBOT_CONTROLLER_INO
#define ROBOT_CONTROLLER_INO


#include "Headers/LRObsSensors.hpp"
#include "Headers/MotorControl.hpp"
#include "Headers/ObstacleDetecter.hpp"
#include "Headers/LineDetector.hpp"
#include "Headers/ObstacleDetected.hpp"
#include "Headers/constants.h"
#include "LineDetectionControl.hpp"
#include "Headers/IR_Avoidance.hpp"

bool headingNorth = true;	//Direction robot is currently heading
void setup(){
  Serial.begin(9600);
  setupMotorControl();	//enable motor control
  setupLineDetector();	//enable line detection
  ultaobssetup();	//enable ultrasonic sensors
	
}
/**
Main loop where control flow for robot is located
**/
void loop(){
  
  forward(17,1);	
	//Poll obstacle avoidance sensors
  if(obscheck2()||obscheck()||checkObstacleIR()){	//if obstacle
    stop();
    avoidOBS();	//obstacle avoidance logic
  }
   int cl = checkLine();

  if(cl == 1){	//poll line detection
   Serial.println("onLine");
	 onEdgeDetected();	//edge detected logic
	 headingNorth = !headingNorth;	//now going other direction
   }


 }
void avoidOBS(){

	if(headingNorth){	//Turn left and go forward until past object then turn right
		
	  left(17,1);
	  delay(TURN_TIME);

	  forward(17,1);
	  delay(FORWARD);

	  right(17,1);
	  delay(TURN_TIME);
	}else{	//Turn right and go forward until past object then turn left

	  right(17,1);
	  delay(TURN_TIME);

	  forward(17,0.8);
	  delay(FORWARD);

	  left(17,0.8);
	  delay(TURN_TIME);
	}


}


#endif