#ifndef LINE_DETECTOR_HPP
#define LINE_DETECTOR_HPP

#include "constants.h"
#include <Arduino.h>
int Left = A9;
int Middle = A10;
int Right = A11;

/**
	setup logic for line detector sensor
**/
void setupLineDetector() {
pinMode(Left, INPUT);
pinMode(Middle, INPUT);
pinMode(Right, INPUT);
Serial.begin(9600);
}

/**
	check if line detected by sensor
**/
bool checkLine(){
  int lVal= analogRead(Left);  
  int mVal= analogRead(Middle);
  int rVal= analogRead(Right);
  Serial.print(lVal);
  Serial.print(" ");
  Serial.print(mVal);
  Serial.print(" ");
  Serial.print(rVal);
  Serial.println();
  return ((lVal>LINE_VALUE && rVal >LINE_VALUE) && (mVal > LINE_VALUE && rVal >LINE_VALUE) && (lVal  > LINE_VALUE && mVal >LINE_VALUE ));	//If two input readings are giving values higher than threshold edge detected
  
  
}
#endif