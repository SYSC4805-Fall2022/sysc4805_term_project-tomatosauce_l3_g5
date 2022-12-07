#ifndef Line_Detection_Control_HPP
#define Line_Detection_Control_HPP
#include "constants.h"
#include "MotorControl.hpp"
#include <Arduino.h>

bool previousTurnLeft = false;	
int lane = 0;	//The current lane of the robot
/**
	The logic for when an edge is detected
**/
void onEdgeDetected(){
	backwards(17,1);	//go backwards briefly, before stoping
	stop();
  Serial.println(lane);
  if(lane > 12){	//If in last lane stop
    stop();
    while(true){
      Serial.println("Ended");
    }
  }
	if(previousTurnLeft){	
		right(17, 1);
		delay(TURN_TIME);	//Turn 90 degrees right
		stop();
	}else{
		left(17, 1);
		delay(TURN_TIME);	//Turn 90 degrees left
		stop();
	}
	forward(17, 1);	
	delay(500);
	stop();	// go forward into next lane
	if(previousTurnLeft){
		right(17, 1);
		delay(TURN_TIME);	//Turn in same direction as previous turn
		previousTurnLeft = false;
		stop();
	}else{
		left(17, 1);
		delay(TURN_TIME);	//Turn in same direction as previous turn
		stop();
		previousTurnLeft = true;
		
	}
  lane += 1;	//now in new lane
  
}

#endif