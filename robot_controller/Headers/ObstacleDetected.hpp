#ifndef ON_OBSTACLE_DETECTED
#define ON_OBSTACLE_DETECTED

#include "LRObsSensors.hpp"
#include "ObstacleDetected.hpp"
#include "MotorControl.hpp"
#include "constants.h"
bool turnLeft = true;

void onObstacleDetected(bool headingNorth){
  Serial.println("Obstacle Avoidance Started");
  
  do{
	  stop();
	  if(!headingNorth){

		  Serial.println("Turn Right");
		  right(17, 1);
		  delay(TURN_TIME);
		  
		  
		  turnLeft = false;
	  }else{
		  
		  Serial.println("Turn Left");
		  left(17, 1);
		  delay(TURN_TIME);
		  turnLeft = true;
	  }
	 
	  forward(17, 1);
	  delay(1000);
	 
	  stop();
	  if(turnLeft){
		right(17, 1);
		delay(TURN_TIME);
		Serial.println("Turned Right");
	}else{
		left(17, 1);
		delay(TURN_TIME);
		Serial.println("Turned Left");
	}
	stop();
	Serial.println("Stopped");
  }while(obscheck() || obscheck2());
  if(turnLeft){
	right(17, 1);
	delay(TURN_TIME);
	Serial.println("Turned Right");
  }else{
	left(17, 1);
	delay(TURN_TIME);
	Serial.println("Turned Left");
	}
  
 }

 
 #endif