#include "Headers/MotorControl.h"
#include "Headers/LineDetector.h"
#include "Headers/ObstacleDetecter.h"
void setup() {
  setupMotorControl();
  setupObstacleDetecter();
  forward(17, 0.8);
}

void loop() {
  if(checkObstacle()==1){
    stop();
    while(true){

    }
    
  }

}
