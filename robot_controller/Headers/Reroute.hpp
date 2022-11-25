#ifndef REROUTE_HPP
#define REROUTE_HPP

#include <string>
#include <stack>

#include "inputs.hpp"
#include "outputs.hpp"
#include "AvoidObstacle.hpp"
class Reroute{
	public:
	enum State{IDLE = 0, WAIT_FOR_OBSTACLE_AVOIDANCE, WAIT_TO_TURN, TURN_RIGHT, TURN_LEFT };
	State currentState;
	Outputs output;
	AvoidObstacle avoidObstacle;
	Reroute(){
		currentState = State::IDLE;
		output = Outputs::NONE;
	}
	void newInput(std::list<Input> input){
		switch(currentState){
			case State::IDLE:
				output = Outputs::NONE;
				if(contains(input, Input::START_REROUTE)){
					avoidObstacle.newInput({Input::START_OBSTACLE_AVOIDANCE});
					currentState = State::WAIT_FOR_OBSTACLE_AVOIDANCE;
				}
				break;
			case State::WAIT_FOR_OBSTACLE_AVOIDANCE:
				avoidObstacle.newInput(input);
				if(avoidObstacle.output == Outputs::TURN_LEFT){
					turns.push(false);
				}else if(avoidObstacle.output == Outputs::TURN_RIGHT){
					turns.push(true);
				}else if(avoidObstacle.output == Outputs::OBSTACLE_AVOIDED){
					output = Outputs::FORWARD;
					currentState = State::WAIT_TO_TURN;
				}
				break;
			case State::WAIT_TO_TURN:
				
				nextTurnLeft = turns.top();
				if(nextTurnLeft && !contains(input, Input::LEFT_OBSTACLE) && !contains(input, Input::FORWARD_OBSTACLE)){
					turns.pop();
					output = Outputs::TURN_LEFT;
					currentState = State::TURN_LEFT;
					
				}else if(!nextTurnLeft && !contains(input, Input::RIGHT_OBSTACLE) && !contains(input, Input::FORWARD_OBSTACLE)){
					turns.pop();
					output = Outputs::TURN_RIGHT;
					currentState = State::TURN_RIGHT;
				}else if(contains(input, Input::FORWARD_OBSTACLE)){
					avoidObstacle.newInput({Input::START_OBSTACLE_AVOIDANCE});
					currentState = State::WAIT_FOR_OBSTACLE_AVOIDANCE;
				}
				break;
			
			case State::TURN_RIGHT:
			case State::TURN_LEFT:
				if(contains(input, Input::TURN_COMPLETE)){
					if(!turns.empty()){
						output = Outputs::FORWARD;
						currentState = State::WAIT_TO_TURN;
					}else{
						output = Outputs::REROUTE_COMPLETE;
						currentState = State::IDLE;
					}
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
				case State::WAIT_FOR_OBSTACLE_AVOIDANCE: return "WAIT_FOR_OBSTACLE_AVOIDANCE";
				case State::WAIT_TO_TURN: return "WAIT_TO_TURN";
				case State::TURN_RIGHT: return "TURN_RIGHT";
				case State::TURN_LEFT: return "TURN_LEFT";
				default: return "INVALID";
			}
		}
	private:
	std::stack<bool> turns;
	bool nextTurnLeft;
};

#endif