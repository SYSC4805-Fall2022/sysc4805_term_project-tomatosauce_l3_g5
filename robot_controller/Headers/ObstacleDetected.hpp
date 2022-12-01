#ifndef ON_OBSTACLE_DETECTED
#define ON_OBSTACLE_DETECTED

#include "LRObsSensors.hpp"
#include "MotorControl.hpp"
#include "constants.h"
bool turnLeft = true;

void onObstacleDetected(){
  stop();
  if(obstacleLeft()){

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
  while((obstacleLeft() && !turnLeft) || (obstacleRight() && turnLeft)){
	 Serial.print("left obstacle: ");
	 Serial.println(leftSensor());
	 Serial.print("right obstacle: ");
	 Serial.println(rightSensor());
	 Serial.println("Going Forward");
  }
  stop();
  if(turnLeft){
	  right(17, 1);
	  Serial.println("Turned Right");
  }else{
	  left(17, 1);
	  Serial.println("Turned Left");
  }
  stop();
  Serial.println("Stopped");
  
 }

 
 #endif