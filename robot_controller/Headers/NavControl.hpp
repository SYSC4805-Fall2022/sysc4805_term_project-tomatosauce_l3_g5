#include <Arduino.h>

using namespace std;

int x;
enum State{IDLE=0, NAVIGATE, AVOID_OBSTACLE, REROUTE, AT_EDGE};
enum Inputs{START=0, FORWARD_OBSTACLE, RIGHT_OBSTACLE, LEFT_OBSTACLE, OBSTACLE_AVOIDED, EDGE_DETECTED, REROUTE_COMPLETE};
State updateState(State currentState, Inputs input){
	switch(currentState){
		case State::IDLE:
			if(input ==  Inputs::START){
				return State::NAVIGATE;
			}
		case State::NAVIGATE:
			if(input == Inputs::FORWARD_OBSTACLE){
				return State::AVOID_OBSTACLE;
			}
			else if(input == Inputs::EDGE_DETECTED){
				return State::AT_EDGE;
			}
		case State::AVOID_OBSTACLE:
			if(input == Inputs::OBSTACLE_AVOIDED){
				return State::REROUTE;
			}
		case State::REROUTE:
			if(input == Inputs::REROUTE_COMPLETE){
				return State::NAVIGATE;
			}else if(input == Inputs::FORWARD_OBSTACLE){
				return State::AVOID_OBSTACLE;
			}
				
		default:
			return -1;
		
	}
	
}