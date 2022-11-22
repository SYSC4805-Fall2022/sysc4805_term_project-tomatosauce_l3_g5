#ifndef OBSTACLE_DETECTER_HPP
#define OBSTACLE_DETECTER_HPP


#include <Arduino.h>
int ledPin = 13;
int inPin = 8;
int obs = 0;

void setupObstacleDetecter(){
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);

}

int checkObstacle(){

  obs = digitalRead(inPin);

  if (obs == HIGH){
    Serial.println("NO obstacle");
    return 0;

  }else{
    Serial.println(" Obstacle");
    return 1;
  }

  
}
#endif