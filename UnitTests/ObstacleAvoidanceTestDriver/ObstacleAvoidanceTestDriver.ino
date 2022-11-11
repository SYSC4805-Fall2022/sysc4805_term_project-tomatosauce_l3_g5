#include <Gyro.h>
#include <LineDetector.h>
#include <MotorControl.h>
#include <ObstacleDetecter.h>

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
