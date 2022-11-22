#include <string>
#include <stack>

#include "inputs.hpp"
#include "outputs.hpp"
#include "AvoidObstacle.hpp"
class Reroute{
	public:
	enum State{IDLE = 0, START_OBSTACLE_AVOIDANCE, WAIT_FOR_OBSTACLE_AVOIDANCE, WAIT_TO_TURN, TURN_RIGHT, TURN_LEFT };
	State currentState;
	Output output;
	Reroute(){
		currentState = State::IDLE;
		output = Outputs::NONE;
	}
	void newInput(Inputs input){
		switch(currentState){
			case State::IDLE:
				if(input == Inputs::START_REROUTE){
					avoidObstacle.newInput(Inputs::START_OBSTACLE_AVOIDANCE);
					currentState = State::START_OBSTACLE_AVOIDANCE;
				}
				break;
			case State::WAIT_FOR_OBSTACLE_AVOIDANCE:
				avoidObstacle.newInput(input);
				if(avoidObstacle.output == Outputs::TURN_LEFT || avoidObstacle.output == Outputs::TURN_RIGHT){
					turns.push(avoidObstacle.output);
				}
				else if(avoidObstacle.output == Outputs::STOP){
					output = Outputs::FORWARD;
					currentState = State::WAIT_TO_TURN;
				}
				break;
			case State::WAIT_TO_TURN:
				nextTurn = turns.pop();
				if(nextTurn == Outputs::TURN_LEFT && input != Inputs::LEFT_OBSTACLE){
					output = Outputs::TURN_LEFT;
					currentState = State::TURN_LEFT;
				}else if(nextTurn == Outputs::TURN_RIGHT && input != Inputs::RIGHT_OBSTACLE){
					output = Output::TURN_RIGHT;
					currentState = State::TURN_RIGHT;
				}else if(input == Inputs::FORWARD_OBSTACLE){
					avoidObstacle.newInput(Inputs::START_OBSTACLE_AVOIDANCE);
					currentState = State::START_OBSTACLE_AVOIDANCE;
				}
				break;
			
			case State::TURN_RIGHT:
			case State::TURN_LEFT:
				if(input == Inputs::TURN_COMPLETE){
					if(turns.size()>0){
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
	
	private:
	stack<Outputs> turns;
	AvoidObstacle avoidObstacle;
	Outputs nextTurn;
}