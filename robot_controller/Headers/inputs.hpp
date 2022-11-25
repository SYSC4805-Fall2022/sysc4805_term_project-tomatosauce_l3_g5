#ifndef INPUTS_HPP
#define INPUTS_HPP
#include <list>
#include <algorithm>

enum class Input{START_NAVIGATION=0, START_OBSTACLE_AVOIDANCE, START_REROUTE, START_EDGE_DETECTED, FORWARD_OBSTACLE, RIGHT_OBSTACLE, LEFT_OBSTACLE, OBSTACLE_AVOIDED, EDGE_DETECTED, REROUTE_COMPLETE, TURN_COMPLETE, NONE, PREFERRED_DIRECTION_RIGHT, PREFERRED_DIRECTION_LEFT};
std::list<Input> inputs;
bool contains(std::list<Input> inputs, Input input){
	auto it = std::find(inputs.begin(), inputs.end(), input);
	return it != inputs.end();
}
#endif