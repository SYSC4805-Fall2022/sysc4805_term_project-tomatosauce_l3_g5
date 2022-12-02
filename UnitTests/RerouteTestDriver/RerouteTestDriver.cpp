#include "../../robot_controller/Headers/Reroute.hpp"
#include "../../robot_controller/Headers/Inputs.hpp"
#include "../../robot_controller/Headers/Outputs.hpp"

#include <iostream>

using namespace std;
int main(){
	cout << "Test Driver for Reroute" << endl;
	Reroute reroute;
	
	//Test 1
	cout << endl << "1. Test Forward Obstacle and then reroute" << endl << endl;
	cout << "Starting State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: START_REROUTE";
	reroute.newInput({Input::START_REROUTE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl<< "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	//Test 2
	cout << endl << "2. Test Obstacles and then reroute" << endl << endl;
	cout << "Starting State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: START_REROUTE";
	reroute.newInput({Input::START_REROUTE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//No Obstacle Detected on either side so turn left
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//Obstacle to right still so can't turn right
	cout << endl << "Input: RIGHT_OBSTACLE";
	reroute.newInput({Input::RIGHT_OBSTACLE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//No Obstacle detected now so turn right
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl<< "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//Test 3
	cout << endl << "3. Test Two Forward Obstacles and then reroute" << endl << endl;
	cout << "Starting State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: START_REROUTE";
	reroute.newInput({Input::START_REROUTE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl << "Input: RIGHT_OBSTACLE";
	reroute.newInput({Input::RIGHT_OBSTACLE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//Obstacle detected in front so must avoid
	cout << endl << "Input: FORWARD_OBSTACLE";
	reroute.newInput({Input::FORWARD_OBSTACLE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//turns left again
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	//Moves forwards
	cout << endl << "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	// No obstacle detected on right so begin turn
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	// Begin moving forward
	cout << endl<< "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	// No Obstacle detected on right so turn right
	cout << endl << "Input: NONE";
	reroute.newInput({Input::NONE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
	
	cout << endl<< "Input: TURN_COMPLETE";
	reroute.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(reroute.output) << " State: " << reroute.stateToString() << endl;
	cout << "AvoidObstacle State : " << reroute.avoidObstacle.stateToString() << endl;
}	

