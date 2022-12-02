#ifndef IR_AVOIDANCE
#define IR_AVOIDANCE

#include <Arduino.h>
//The max distance is 8cm

int inPin = A1;

void setupObstacleDetecter(){
  pinMode(inPin, INPUT);
  Serial.begin(9600);

}

int getVoltage(){
	int voltage = analogRead(inPin);
	return voltage;
}	
bool checkObstacleIR(){

  int voltage = getVoltage();

  if (voltage > 100){
    
    return false;

  }else{
    return true;
  }


}
#endif