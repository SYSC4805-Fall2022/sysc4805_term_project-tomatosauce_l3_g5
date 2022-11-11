#include <Arduino.h>

using namespace std;

enum State{IDLE=0, NAVIGATE, AVOID_OBSTACLE, REROUTE};

State updateState(State currentState){
	switch(currentState){
		case State