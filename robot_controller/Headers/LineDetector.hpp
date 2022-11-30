#ifndef LINE_DETECTOR_HPP
#define LINE_DETECTOR_HPP

#include <Arduino.h>
int Left = A9;
int Middle = A10;
int Right = A11;

void setupLineDetector() {
pinMode(Left, INPUT);
pinMode(Middle, INPUT);
pinMode(Right, INPUT);
Serial.begin(9600);
}

bool checkLine(){
  int lVal= analogRead(Left);  
  int mVal= analogRead(Middle);
  int rVal= analogRead(Right);
  // Serial.print(lVal);
 // Serial.print(" ");
 // Serial.print(mVal);
 // Serial.print(" ");
 // Serial.print(rVal);
 // Serial.println();
  return ((lVal>550 && rVal >550) && (mVal > 550 && rVal >550) && (lVal  > 550 && mVal >550 ));
  
  
}
#endif