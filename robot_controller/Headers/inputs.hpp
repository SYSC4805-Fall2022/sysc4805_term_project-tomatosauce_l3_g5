#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <algorithm>

enum class Input{START_NAVIGATION=0, START_OBSTACLE_AVOIDANCE, START_REROUTE, START_EDGE_DETECTED, FORWARD_OBSTACLE, RIGHT_OBSTACLE, LEFT_OBSTACLE, OBSTACLE_AVOIDED, EDGE_DETECTED, REROUTE_COMPLETE, TURN_COMPLETE, NONE, PREFERRED_DIRECTION_RIGHT, PREFERRED_DIRECTION_LEFT, DELAY_COMPLETE};
//std::vector<Input> inputs;
bool contains(Input inputs [], Input input){
	bool result = false;
    for(int i = 0; i<1; i++){
		if(inputs[i] == input){
			return true;
		}
	}
    return false;
}
#endif