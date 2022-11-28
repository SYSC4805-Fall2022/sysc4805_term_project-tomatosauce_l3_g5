#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <algorithm>

enum class Input{START_NAVIGATION=0, START_OBSTACLE_AVOIDANCE, START_REROUTE, START_EDGE_DETECTED, FORWARD_OBSTACLE, RIGHT_OBSTACLE, LEFT_OBSTACLE, OBSTACLE_AVOIDED, EDGE_DETECTED, REROUTE_COMPLETE, TURN_COMPLETE, NONE, PREFERRED_DIRECTION_RIGHT, PREFERRED_DIRECTION_LEFT, DELAY_COMPLETE};
//std::vector<Input> inputs;
bool contains(Input inputs [], Input input){
	int length = sizeof(Input)/sizeof(Input);
    for(int i = 0; i<15; i++){
		if(inputs[i] == input){
			return true;
		}
	}
    return false;
}

const char* inputToString(Input input){
	switch(input){
		case Input::START_NAVIGATION: return "START_NAVIGATION";
		case Input::START_OBSTACLE_AVOIDANCE: return "START_OBSTACLE_AVOIDANCE";
		case Input::START_REROUTE: return "START_REROUTE";
		case Input::START_EDGE_DETECTED: return "START_EDGE_DETECTED";
		case Input::FORWARD_OBSTACLE: return "START_FORWARD_OBSTACLE";
		case Input::RIGHT_OBSTACLE: return "RIGHT_OBSTACLE";
		case Input::LEFT_OBSTACLE: return "LEFT_OBSTACLE";
		case Input::OBSTACLE_AVOIDED: return "OBSTACLE_AVOIDED";
		case Input::EDGE_DETECTED: return "EDGE_DETECTED";
		case Input::REROUTE_COMPLETE: return "REROUTE_COMPLETE";
		case Input::TURN_COMPLETE: return "TURN_COMPLETE";
		case Input::NONE: return "NONE";
		case Input::PREFERRED_DIRECTION_LEFT: return "PREFERRED_DIRECTION_LEFT";
		case Input::PREFERRED_DIRECTION_RIGHT: return "PREFERRED_DIRECTION_RIGHT";
		case Input::DELAY_COMPLETE: return "DELAY_COMPLETE";
		default: return "INVALID_INPUT";
	}
}
#endif