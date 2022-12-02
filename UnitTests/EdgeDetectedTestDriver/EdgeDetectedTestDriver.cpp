#include "../../robot_controller/Headers/EdgeDetected.hpp"
#include "../../robot_controller/Headers/Inputs.hpp"
#include "../../robot_controller/Headers/Outputs.hpp"

#include <iostream>

using namespace std;
int main(){
	cout << "Unit Test for EdgeDetected";
	EdgeDetected edgeDetected;
	cout << endl << "Starting State: " << edgeDetected.stateToString() << endl;
	
	cout << endl << "Input: START_EDGE_DETECTED";
	edgeDetected.newInput({Input::START_EDGE_DETECTED});
	cout << " Output: " << outputToString(edgeDetected.output) <<" State: " << edgeDetected.stateToString();
	
	cout << endl << "Input: PREFERRED_DIRECTION_RIGHT";
	edgeDetected.newInput({Input::PREFERRED_DIRECTION_RIGHT});
	cout << " Output: " << outputToString(edgeDetected.output) <<" State: " << edgeDetected.stateToString();
	
	cout << endl << "Input: TURN_COMPLETE";
	edgeDetected.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(edgeDetected.output) <<" State: " << edgeDetected.stateToString();
	
	cout << endl << "Input: DELAY_COMPLETE";
	edgeDetected.newInput({Input::DELAY_COMPLETE});
	cout << " Output: " << outputToString(edgeDetected.output) <<" State: " << edgeDetected.stateToString();
	
	cout << endl << "Input: TURN_COMPLETE";
	edgeDetected.newInput({Input::TURN_COMPLETE});
	cout << " Output: " << outputToString(edgeDetected.output) <<" State: " << edgeDetected.stateToString();
	
	
}