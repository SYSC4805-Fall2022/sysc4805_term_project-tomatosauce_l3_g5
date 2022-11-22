#include "../../robot_controller/Headers/AvoidObstacle.hpp"
#include <iostream>


using namespace std;
int main(){
	std::cout << "Unit Test for AvoidObstacle" << endl;
	std::cout << endl << "Test Obstacle Forward and to Left" << endl;
	AvoidObstacle avoidObstacle;
	std::cout << "Starting State: " << avoidObstacle.stateToString() << endl;
	
	std::cout << "Input: START_OBSTACLE_AVOIDANCE";
	avoidObstacle.newInput(Inputs::START_OBSTACLE_AVOIDANCE);
	std::cout << " Output: " << outputToString(avoidObstacle.output);
	std::cout << " State: " << avoidObstacle.stateToString() << endl;
	
	std::cout << "Input: LEFT_OBSTACLE";
	avoidObstacle.newInput(Inputs::LEFT_OBSTACLE);
	std::cout << " Output: " << outputToString(avoidObstacle.output);
	std::cout << " State: " << avoidObstacle.stateToString() << endl;
	
	std::cout << "Input: TURN_COMPLETE";
	avoidObstacle.newInput(Inputs::TURN_COMPLETE);
	std::cout << " Output: " << outputToString(avoidObstacle.output);
	std::cout << " State: " << avoidObstacle.stateToString() << endl;
	
	std::cout << endl << "Test Obstacle Forward" << endl;
	AvoidObstacle avoidObstacle2;
	std::cout << " Output: " << outputToString(avoidObstacle2.output);
	std::cout << "Starting State: " << avoidObstacle2.stateToString() << endl;
	
	std::cout << "Input: START_OBSTACLE_AVOIDANCE";
	avoidObstacle2.newInput(Inputs::START_OBSTACLE_AVOIDANCE);
	std::cout << " Output: " << outputToString(avoidObstacle2.output);
	std::cout << " State: " << avoidObstacle2.stateToString() << endl;
	
	std::cout << "Input: NONE";
	avoidObstacle2.newInput(Inputs::NONE);
	std::cout << " Output: " << outputToString(avoidObstacle2.output);
	std::cout << " State: " << avoidObstacle2.stateToString() << endl;
	
	std::cout << "Input: TURN_COMPLETE";
	avoidObstacle2.newInput(Inputs::TURN_COMPLETE);
	std::cout << " Output: " << outputToString(avoidObstacle2.output);
	std::cout << " State: " << avoidObstacle2.stateToString() << endl;
	
	std::cout << endl << "Test Invalid Input" << endl;
	AvoidObstacle avoidObstacle3;
	
	std::cout << "Starting State: " << avoidObstacle3.stateToString() << endl;
	
	std::cout << "Input: FORWARD_OBSTACLE";
	avoidObstacle3.newInput(Inputs::FORWARD_OBSTACLE);
	std::cout << " Output: " << outputToString(avoidObstacle3.output);
	std::cout << " State: " << avoidObstacle3.stateToString() << endl;
	
	
}