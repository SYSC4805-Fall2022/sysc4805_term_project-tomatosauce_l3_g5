#include <string>
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
		
		void newInput(Inputs input){
			switch(currentState){
				case State::IDLE:
					if(input == Inputs::START_OBSTACLE_AVOIDANCE){
						currentState = State::CHOOSE_DIRECTION;
					}
					break;
				case State::CHOOSE_DIRECTION:
					if(input != Inputs::LEFT_OBSTACLE){
						currentState = State::TURN_LEFT;
						output = Outputs::TURN_LEFT;
					}else if(input == Inputs::LEFT_OBSTACLE){
						currentState = State::TURN_RIGHT;
						output = Outputs::TURN_RIGHT;
					}
					break;
				case State::TURN_LEFT:
					if(input == Inputs::TURN_COMPLETE){
						currentState = State::IDLE;
						output = Outputs::OBSTACLE_AVOIDED;
					}
					break;
				case State::TURN_RIGHT:
					if(input == Inputs::TURN_COMPLETE){
						currentState = State::IDLE;
						output = Outputs::OBSTACLE_AVOIDED;
					}
					break;
					
			    default:break;
			}
		}
		std::string stateToString(){
			switch(currentState){
				case State::IDLE: return "IDLE";
				case State::CHOOSE_DIRECTION: return "CHOOSE_DIRECTION";
				case State::TURN_RIGHT: return "TURN_RIGHT";
				case State::TURN_LEFT: return "TURN_LEFT";
				default: return "INVALID";
			}
		}
};