#ifndef OUTPUTS_HPP
#define OUTPUTS_HPP
#include <string>
enum class Outputs{START_NAVIGATION=0, START_OBSTACLE_AVOIDANCE, START_REROUTE, START_EDGE_DETECTED, TURN_LEFT, TURN_RIGHT, STOP, FORWARD, REROUTE_COMPLETE, OBSTACLE_AVOIDED, NONE};

std::string outputToString(Outputs output){
	switch(output){
		case Outputs::START_NAVIGATION: return "START_NAVIGATION";
		case Outputs::START_OBSTACLE_AVOIDANCE: return "START_OBSTACLE_AVOIDANCE";
		case Outputs::START_REROUTE: return "START_REROUTE";
		case Outputs::START_EDGE_DETECTED: return "START_EDGE_DETECTED";
		case Outputs::TURN_LEFT: return "TURN_LEFT";
		case Outputs::TURN_RIGHT: return "TURN_RIGHT";
		case Outputs::STOP: return "STOP";
		case Outputs::OBSTACLE_AVOIDED: return "OBSTACLE_AVOIDED";
		case Outputs::NONE: return "NONE";
		default: return "INVALID";
	}
}
#endif