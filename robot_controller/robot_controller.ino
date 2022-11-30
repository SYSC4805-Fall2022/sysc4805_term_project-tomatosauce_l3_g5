#ifndef ROBOT_CONTROLLER_INO
#define ROBOT_CONTROLLER_INO


#include "Headers/LRObsSensors.hpp"
#include "Headers/MotorControl.hpp"
#include "Headers/ObstacleDetecter.hpp"
#include "Headers/LineDetector.hpp"
#include "LineDetectionControl.hpp"

void setup(){
  Serial.begin(9600);
  //setupMotorControl();
  setupLineDetector();
  ultaobssetup();
  LRObsSensorssetup();
	
}
void loop(){
  //forward(17, 1);
  delay(1000);
  int cl = checkLine();
  Serial.println(obscheck());
  Serial.println("Left: "+leftSensor());
  Serial.println("Right: "+rightSensor());
  //Serial.println(obstacleLeft());
 // Serial.println(obstacleRight());

  if(cl == 1){
    Serial.println("onLine");
	 
	  //onEdgeDetected();
    // return;
  }

  // if(obscheck()){
  //   backwards(17, 1);
  //   stop();
    
  //   Serial.println("Detected");
  //   obsDetected();
  //   while(true);
  // }else{
  //   Serial.println("Not detected");
  // }
  //Serial.println(leftSensor());
  
}

void obsDetected(){
  int l =1;
  int r=0;

  l=sensors[0].read();
 r=sensors[1].read(); 
  Serial.println(r);
  //Serial.println(r);
  // if(r>l){
  //   Serial.println("Turn Right");
  //   right(17,1);
  //   delay(1000);
    //counter = counter + 1;

    //counter++; c1

     //l=sensors[0].read();
    //  while(l<100){
    //    forward(17, 0.8);
    //    delay(1000);
    //    stop();
    //   // l=sensors[0].read();

    //  }

    //  forward(17, 0.8);
    //  delay(2000);
    //  stop();

    //  left(17,0.8);
    //  counter = counter - 1;
    //  }

    //  else{
    //    Serial.println("TURN left");
    //    left(17,1);
    //    delay(1000);
    //  }
//}
    //    //counter = counter - 1;
    //    //r=sensors[1].read();
    //    while(r<100){
    //    forward(17, 0.8);
    //    delay(1000);
    //    stop();
    //    //r=sensors[1].read();

    //  }

    //  forward(17, 0.8);
    //  delay(2000);
    //  stop();

    //  right(17,0.8);
    //  counter = counter - 1;
 }



#endif