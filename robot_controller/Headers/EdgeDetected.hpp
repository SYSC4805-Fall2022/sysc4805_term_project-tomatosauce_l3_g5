#ifndef EDGE_DETECTED_HPP
#define EDGE_DETECTED_HPP

#include <string>
#include <stack>

#include "inputs.hpp"
#include "outputs.hpp"

class EdgeDetected{
	public:
	enum State{IDLE=0, CHOOSE_DIRECTION, TURN_LEFT, TURN_RIGHT, FORWARD_ONE_STEP, TURN_LEFT_AGAIN, TURN_RIGHT_AGAIN};
	State currentState;
	Outputs output;
	EdgeDetected(){
		currentState = State::IDLE;
		output = Outputs::NONE;
	}
	void newInput(Input inputs []){
		switch(currentState){
			case State::IDLE:
				if(contains(inputs, Input::START_EDGE_DETECTED)){
					output = Outputs::CHOOSE_DIRECTION;
					currentState = State::CHOOSE_DIRECTION;
				}
				break;
			case State::CHOOSE_DIRECTION:
				if(contains(inputs, Input::PREFERRED_DIRECTION_RIGHT) && !contains(inputs,Input::RIGHT_OBSTACLE)){
					turnLeft = false;
					output = Outputs::TURN_RIGHT;
					currentState = State::TURN_RIGHT;
				}else{
					turnLeft = true;
					output = Outputs::TURN_LEFT;
					currentState = State::TURN_LEFT;
				}
				break;	
			case State::TURN_LEFT:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = Outputs::FORWARD_ONE_STEP;
					currentState = State::FORWARD_ONE_STEP;
				}
				break;
			case State::TURN_RIGHT:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = Outputs::FORWARD_ONE_STEP;
					currentState = State::FORWARD_ONE_STEP;
				}
				break;
			case State::FORWARD_ONE_STEP:
				if(contains(inputs, Input::DELAY_COMPLETE)){
					if(turnLeft){
						output = Outputs::TURN_LEFT;
						currentState = State::TURN_LEFT_AGAIN;
					}else{
						output = Outputs::TURN_RIGHT;
						currentState = State::TURN_RIGHT_AGAIN;
					}
				}
				break;
			case State::TURN_LEFT_AGAIN:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = Outputs::EDGE_DETECTED_COMPLETE;
					currentState = State::IDLE;
				}
				break;
			case State::TURN_RIGHT_AGAIN:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = Outputs::EDGE_DETECTED_COMPLETE;
					currentState = State::IDLE;
				}
				break;
			default:
				output = Outputs::NONE;
				break;
				
		}
	}
	const char* stateToString(){
			switch(currentState){
				case State::IDLE: return "IDLE";
				case State::CHOOSE_DIRECTION: return "CHOOSE_DIRECTION";
				case State::TURN_RIGHT: return "TURN_RIGHT";
				case State::TURN_LEFT: return "TURN_LEFT";
				case State::FORWARD_ONE_STEP: return "FORWARD_ONE_STEP";
				case State::TURN_RIGHT_AGAIN: return "TURN_RIGHT_AGAIN";
				case State::TURN_LEFT_AGAIN: return "TURN_LEFT_AGAIN";
				default: return "INVALID";
			}
	}
	private:
		bool turnLeft;
};
#endif