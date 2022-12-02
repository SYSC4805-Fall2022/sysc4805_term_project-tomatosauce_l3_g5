#include "../../robot_controller/Headers/NavControl.hpp"
#include <iostream>

using namespace std;

int main(){
	cout << "Unit Test for NavControl" << endl;
	
	State currentState = State::IDLE;
	cout << stateToString(currentState) << endl;
	
	cout << "Input: " << "START";
	currentState = updateState(currentState, Inputs::START);
	cout << " State: " << stateToString(currentState) << endl ;
	
	cout << "Input: " << "FORWARD_OBSTACLE";
	currentState = updateState(currentState, Inputs::FORWARD_OBSTACLE);
	cout << " State: " << stateToString(currentState) << endl;
	
	cout << "Input: " << "OBSTACLE_AVOIDED";
	currentState = updateState(currentState, Inputs::OBSTACLE_AVOIDED);
	cout << " State: " <<stateToString(currentState) << endl;
	
	cout << "Input: " << "REROUTE_COMPLETE";
	currentState = updateState(currentState, Inputs::REROUTE_COMPLETE);
	cout << "State: "<<stateToString(currentState) << endl;
	
	

}