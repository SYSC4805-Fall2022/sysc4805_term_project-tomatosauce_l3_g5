#ifndef EDGE_DETECTED_HPP
#define EDGE_DETECTED_HPP

#include <string>
#include <stack>

#include "inputs.hpp"
#include "outputs.hpp"

class EdgeDetected{
	public:
	enum State{IDLE=0, CHOOSE_DIRECTION, TURN_LEFT, TURN_RIGHT, FORWARD, TURN_LEFT_AGAIN, TURN_RIGHT_AGAIN};
	State currentState;
	Outputs output;
	EdgeDetected(){
		currentState = State::IDLE;
		output = Outputs::NONE;
	}
	void newInput(std::list<Inputs> inputs){
		switch(currentState){
			case State::IDLE:
				if(contains(inputs, Input::START_EDGE_DETECTED)){
					output = outputs::CHOOSE_DIRECTION;
					currentState = State::CHOOSE_DIRECTION;
				}
				break;
			case State::CHOOSE_DIRECTION:
				if(contains(inputs, Input::PREFERRED_DIRECTION_RIGHT) && !contains(Input::RIGHT_OBSTACLE)){
					turnLeft = false;
					output = outputs::TURN_RIGHT;
					currentState = State::TURN_RIGHT;
				}else if(contains(inputs, Input::PREFERRED_DIRECTION_LEFT) && !contains(Input::LEFT_OBSTACLE)){
					turnLeft = true;
					output = outputs::TURN_LEFT;
					currentState = State::TURN_LEFT;
				}
				break;	
			case State::TURN_LEFT:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = outputs::FORWARD;
					currentState = State::FORWARD;
				}
				break;
			case State::TURN_RIGHT:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = outputs::FORWARD;
					currentState = State::FORWARD;
				}
				break;
			case State::FORWARD:
				if(contains(inputs, Input::STOP){
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
					output = outputs::EDGE_DETECTED_COMPLETE;
					currentState = State::IDLE;
				}
				break;
			case State::TURN_RIGHT_AGAIN:
				if(contains(inputs, Input::TURN_COMPLETE)){
					output = outputs::EDGE_DETECTED_COMPLETE;
					currentState = State::IDLE;
				}
				break;
			default:
				output = Outputs::NONE;
				break;
				
		}
	}
	std::string stateToString(){
			switch(currentState){
				case State::IDLE: return "IDLE";
				case State::CHOOSE_DIRECTION: return "CHOOSE_DIRECTION";
				case State::TURN_RIGHT: return "TURN_RIGHT";
				case State::TURN_LEFT: return "TURN_LEFT";
				case State::FORWARD: return "FORWARD";
				case State::TURN_RIGHT_AGAIN: return "TURN_RIGHT_AGAIN";
				case State::TURN_LEFT_AGAIN: return "TURN_LEFT_AGAIN";
				default: return "INVALID";
			}
	}
	private:
		bool turnLeft;