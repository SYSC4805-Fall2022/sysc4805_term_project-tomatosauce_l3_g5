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

void setup(){
  Serial.begin(9600);
  setupMotorControl();
  setupLineDetector();
  ultaobssetup();
  LRObsSensorssetup();
	
}
void loop(){
  // Serial.println(sensors[0].read());
  // Serial.println(sensors[1].read());
  forward(17,1);
 
  //Serial.print("obs2: ");
  //Serial.println(obscheck2());
  Serial.print("obs1: ");
  Serial.println(obscheck());
  //Serial.print("ir: ");
  //Serial.println(checkObstacleIR());
  if(obscheck2()||obscheck()||checkObstacleIR()){
    //Serial.println("detected");
    stop();

    //onObstacleDetected();
    obsDetected2();
  }
  
  // if(checkObstacleIR()){
  //   // backwards(17, 1);
  //   // stop();
  //   // while(true);
  // }
  
  // int cl = checkLine();
  
  // Serial.print("Left: ");
  // Serial.println(leftSensor());
  // Serial.print("Right: ");
  // Serial.println(rightSensor());
  
  //Serial.println(getVoltage());
  //Serial.println(checkObstacleIR());

  // if(cl == 1){
  //  Serial.println("onLine");
	//  onEdgeDetected();
  //  }

}
void obsDetected2(){
  int l =1;
  int r=0;

  l=sensors[0].read();
  r=sensors[1].read(); 
 
  if(r>l){
    
    right(17,0.8);
    delay(1000);
    //counter = counter + 1;
 
    //counter++; c1

     l=sensors[0].read();
     Serial.print("sensor 0");
     Serial.println(sensors[0].read());
     Serial.print("sensor 1");
     Serial.println(sensors[1].read());
     while(l<100){
      //  Serial.println(sensors[0].read());
      //   Serial.println(sensors[1].read());
       forward(17, 0.8);
       stop();
       l=sensors[0].read();
        Serial.println("sensor:");
  Serial.println(l);
     }

     forward(17, 0.8);
     delay(2000);
     stop();

     left(17,0.8);
     //counter = counter - 1;
     }

     else{
       left(17,0.8);
      // counter = counter - 1;
       r=sensors[1].read();
       while(r<100){
       forward(17, 0.8);
       stop();
       r=sensors[1].read();
       Serial.print("sensor 0");
       Serial.println(sensors[0].read());
       Serial.print("sensor 1");
       Serial.println(sensors[1].read());

     }

     forward(17, 0.8);
     delay(2000);
     stop();

     right(17,0.8);
    // counter = counter - 1;
       }


}

#endif