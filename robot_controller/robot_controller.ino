#ifndef ROBOT_CONTROLLER_INO
#define ROBOT_CONTROLLER_INO


#include "Headers/LRObsSensors.hpp"
#include "Headers/MotorControl.hpp"
#include "Headers/ObstacleDetecter.hpp"
#include "Headers/LineDetector.hpp"
#include "Headers/ObstacleDetected.hpp"
#include "Headers/constants.h"
#include "LineDetectionControl.hpp"
#include "Headers/IR_Avoidance.hpp"

bool headingNorth = true;
void setup(){
  Serial.begin(9600);
  setupMotorControl();
  setupLineDetector();
  ultaobssetup();
  //LRObsSensorssetup();
	
}
void loop(){
  
  forward(17,1);
//   //delay(1000);
  if(obscheck2()||obscheck()||checkObstacleIR()){
    Serial.println("detected");
    stop();

    //onObstacleDetected(headingNorth);
    //obsDetected2();
    avoidOBS();
  }
   int cl = checkLine();

  if(cl == 1){
   Serial.println("onLine");
	 onEdgeDetected();
   headingNorth = !headingNorth;
   }


 }
void avoidOBS(){

if(headingNorth){
  //it is going to north)
  left(17,1);
  delay(TURN_TIME);

  forward(17,1);
  delay(FORWARD);

  right(17,1);
  delay(TURN_TIME);
}else{
//IF IT IS GOING SOUTH
  right(17,1);
  delay(TURN_TIME);

  forward(17,0.8);
  delay(FORWARD);

  left(17,0.8);
  delay(TURN_TIME);
}


 }
// void obsDetected2(){
//   int l =1;
//   int r=0;

//   l=sensors[0].read();
//   r=sensors[1].read(); 
 
//   if(r>l){
    
//     right(17,0.8);
//     delay(1000);
//     //counter = counter + 1;
 
//     //counter++; c1

//      l=sensors[0].read();
//      Serial.print("sensor 0");
//      Serial.println(sensors[0].read());
//      Serial.print("sensor 1");
//      Serial.println(sensors[1].read());
//      while(l<100){
//       //  Serial.println(sensors[0].read());
//       //   Serial.println(sensors[1].read());
//        forward(17, 0.8);
//        stop();
//        l=sensors[0].read();
//         Serial.println("sensor:");
//   Serial.println(l);
//      }

//      forward(17, 0.8);
//      delay(2000);
//      stop();

//      left(17,0.8);
//      //counter = counter - 1;
//      }

//      else{
//        left(17,0.8);
//       // counter = counter - 1;
//        r=sensors[1].read();
//        while(r<100){
//        forward(17, 0.8);
//        stop();
//        r=sensors[1].read();
//        Serial.print("sensor 0");
//        Serial.println(sensors[0].read());
//        Serial.print("sensor 1");
//        Serial.println(sensors[1].read());

//      }

//      forward(17, 0.8);
//      delay(2000);
//      stop();

//      right(17,0.8);
//     // counter = counter - 1;
//        }


// }

#endif