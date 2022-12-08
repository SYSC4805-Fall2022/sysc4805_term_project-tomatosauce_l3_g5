#ifndef OBSTACLE_DETECTER_HPP
#define OBSTACLE_DETECTER_HPP

#include "constants.h"
#include <Arduino.h>
// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 5 //attach pin D3 Arduino to pin Trig of HC-SR04

#define echoPin2 8
#define trigPin2 9

// defines variables
long duration; // variable for the duration of sound wave travel
long duration2;
int distance; // variable for the distance measurement
int distance2;

/**
	setup pins for ultrasonic sensors
**/
void ultaobssetup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  
}
/**
	check if obstacle in front of sensor1
**/
bool obscheck() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  //digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  //digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
 // duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance = (duration * 0.034 / 2); // Speed of sound wave divided by 2 (go and back)
 // distance2 = (duration2 * 0.034/2);
  // Displays the distance on the Serial Monitor
  Serial.print("distance 1: ");
  Serial.println(distance);
  if ((distance>ULTRASONIC_LOWERBOUND)&(distance < ULTRASONIC_UPPERBOUND)){
     
     return true;

  }else{
    return false;
  }

}
/**
	check if obstacle in front of sensor2
**/
bool obscheck2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
	//Serial.print("distance 2: ");
    //Serial.println(distance2);
  if ((distance>ULTRASONIC_LOWERBOUND)&(ULTRASONIC_UPPERBOUND < 25)){
     
     return true;

  }else{
    return false;
  }
}
#endif