#ifndef Line_Detection_Control_HPP
#define Line_Detection_Control_HPP

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
		delay(1350);
		stop();
	}else{
		left(17, 1);
		delay(1350);
		stop();
	}
	forward(17, 1);
	delay(500);
	stop();
	if(previousTurnLeft){
		right(17, 1);
		delay(1350);
		previousTurnLeft = false;
		stop();
	}else{
		left(17, 1);
		delay(1350);
		stop();
		previousTurnLeft = true;
		
	}
  lane += 1;
	
}

#endif