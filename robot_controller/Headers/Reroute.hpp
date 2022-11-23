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
	void newInput(Inputs input){
		switch(currentState){
			case State::IDLE:
				if(input == Inputs::START_REROUTE){
					avoidObstacle.newInput(Inputs::START_OBSTACLE_AVOIDANCE);
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
				if(nextTurnLeft && input != Inputs::LEFT_OBSTACLE && input != Inputs::FORWARD_OBSTACLE){
					turns.pop();
					output = Outputs::TURN_LEFT;
					currentState = State::TURN_LEFT;
					
				}else if(!nextTurnLeft && input != Inputs::RIGHT_OBSTACLE && input != Inputs::FORWARD_OBSTACLE){
					turns.pop();
					output = Outputs::TURN_RIGHT;
					currentState = State::TURN_RIGHT;
				}else if(input == Inputs::FORWARD_OBSTACLE){
					avoidObstacle.newInput(Inputs::START_OBSTACLE_AVOIDANCE);
					currentState = State::WAIT_FOR_OBSTACLE_AVOIDANCE;
				}
				break;
			
			case State::TURN_RIGHT:
			case State::TURN_LEFT:
				if(input == Inputs::TURN_COMPLETE){
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