#ifndef IR_AVOIDANCE
#define IR_AVOIDANCE

#include <Arduino.h>
//The max distance is 8cm

int inPin = A1;
/**
	setup logic for IR Sensor
**/
void setupObstacleDetecter(){
  pinMode(inPin, INPUT);
  Serial.begin(9600);

}
/**
	get voltage of IR Sensor output pin
**/
int getVoltage(){
	int voltage = analogRead(inPin);
	return voltage;
}	
/**
	check if obstacle in front of IR Sensor
**/
bool checkObstacleIR(){

  int voltage = getVoltage();

  if (voltage > 100){
    
    return false;

  }else{
    return true;
  }


}
#endif