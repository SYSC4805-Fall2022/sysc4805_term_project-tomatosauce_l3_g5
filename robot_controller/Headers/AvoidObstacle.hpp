#ifndef AVOID_OBSTACLE_HPP
#define AVOID_OBSTACLE_HPP

#include "inputs.hpp"
#include "outputs.hpp"


class AvoidObstacle{
	public:
		enum State{IDLE = 0, CHOOSE_DIRECTION, TURN_RIGHT, TURN_LEFT};
		State currentState;
		Outputs output;
		AvoidObstacle(){
			currentState = State::IDLE;
			output = Outputs::NONE;
		}
		
		void newInput(Input inputs[]){
			switch(currentState){
				case State::IDLE:
					if(contains(inputs, Input::START_OBSTACLE_AVOIDANCE)){
						currentState = State::CHOOSE_DIRECTION;
					}
					break;
				case State::CHOOSE_DIRECTION:
					if(!contains(inputs,Input::LEFT_OBSTACLE)){
						currentState = State::TURN_LEFT;
						output = Outputs::TURN_LEFT;
					}else if(contains(inputs, Input::LEFT_OBSTACLE)){
						currentState = State::TURN_RIGHT;
						output = Outputs::TURN_RIGHT;
					}
					break;
				case State::TURN_LEFT:
					if(contains(inputs, Input::TURN_COMPLETE)){
						currentState = State::IDLE;
						output = Outputs::OBSTACLE_AVOIDED;
					}
					break;
				case State::TURN_RIGHT:
					if(contains(inputs, Input::TURN_COMPLETE)){
						currentState = State::IDLE;
						output = Outputs::OBSTACLE_AVOIDED;
					}
					break;
					
			    default:break;
			}
		}
		const char* stateToString(){
			switch(currentState){
				case State::IDLE: return "IDLE";
				case State::CHOOSE_DIRECTION: return "CHOOSE_DIRECTION";
				case State::TURN_RIGHT: return "TURN_RIGHT";
				case State::TURN_LEFT: return "TURN_LEFT";
				default: return "INVALID";
			}
		}
};
#endif