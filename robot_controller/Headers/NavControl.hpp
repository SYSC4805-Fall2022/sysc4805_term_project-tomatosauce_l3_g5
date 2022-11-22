#ifndef NAV_CONTROL_HPP
#define NAV_CONTROL_HPP

#include <string>
#include "inputs.h"
enum State{IDLE=0, NAVIGATE, AVOID_OBSTACLE, REROUTE, AT_EDGE, INVALID};

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
			return INVALID;
		
	}
	
}
std::string stateToString(State state){
	switch(state){
		case State::IDLE: return "IDLE";
		case State::NAVIGATE: return "NAVIGATE";
		case State::AVOID_OBSTACLE: return "AVOID_OBSTACLE";
		case State::AT_EDGE: return "AT_EDGE";
		case State::REROUTE: return "REROUTE";
		default: return "INVALID";
	}
}
std::string inputToString(Inputs input){
	switch(input){
		case Inputs::START: return "START";
		case Inputs::FORWARD_OBSTACLE: return "FORWARD_OBSTACLE";
		case Inputs::RIGHT_OBSTACLE: return "RIGHT_OBSTACLE";
		case Inputs::LEFT_OBSTACLE: return "LEFT_OBSTACLE";
		case Inputs::OBSTACLE_AVOIDED: return "OBSTACLE_AVOIDED";
		case Inputs::EDGE_DETECTED: return "EDGE_DETECTED";
		case Inputs::REROUTE_COMPLETE: return "REROUTE_COMPLETE";
		default: return "INVALID";
	}
}
#endif