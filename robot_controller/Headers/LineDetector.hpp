#ifndef LINE_DETECTOR_HPP
#define LINE_DETECTOR_HPP

#include <Arduino.h>
int Left = 49;
int Middle = 51;
int Right = 53;

void setupLineDetector() {
pinMode(Left, INPUT);
pinMode(Middle, INPUT);
pinMode(Right, INPUT);
}

bool checkLine(){
  int count = 0;
  int lVal= digitalRead(Left);  
  int mVal= digitalRead(Middle);
  int rVal= digitalRead(Right);
  
  count = lVal+mVal+rVal;
  return count>1;
  
}
#endif