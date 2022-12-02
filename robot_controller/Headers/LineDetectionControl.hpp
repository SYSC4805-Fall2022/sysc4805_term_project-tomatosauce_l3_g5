#ifndef Line_Detection_Control_HPP
#define Line_Detection_Control_HPP
#include "constants.h"
#include "MotorControl.hpp"
#include <Arduino.h>

bool previousTurnLeft = false;
int lane = 0;
void onEdgeDetected(){
	backwards(17,1);
	stop();
  Serial.println(lane);
  if(lane > 12){
    stop();
    while(true){
      Serial.println("Ended");
    }
  }
	if(previousTurnLeft){
		right(17, 1);
		delay(TURN_TIME);
		stop();
	}else{
		left(17, 1);
		delay(TURN_TIME);
		stop();
	}
	forward(17, 1);
	delay(500);
	stop();
	if(previousTurnLeft){
		right(17, 1);
		delay(TURN_TIME);
		previousTurnLeft = false;
		stop();
	}else{
		left(17, 1);
		delay(TURN_TIME);
		stop();
		previousTurnLeft = true;
		
	}
  lane += 1;
  
}

#endif