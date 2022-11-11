#include <Arduino.h>
#include <Wire.h>
#include <LSM6.h>
LSM6 imu;

void initializa_GYRO(){
  Wire.begin();

  if (!imu.init())
    {
      Serial.println("Failed to detect and initialize IMU!");
    while (1);
    }
    imu.enableDefault();
}

float GYRO_X(){
float Gx;
imu.read();
Gx = ((int16_t)imu.g.x) * 8.75/1000;
return Gx;
}
void GYRO_Y(){
  float Gy;
  imu.read();
Gy = ((int16_t)imu.g.y) * 8.75/1000;
return Gy;
}
void GYRO_Z(){
  float Gz;
  imu.read();
Gz = ((int16_t)imu.g.z) * 8.75/1000;
return Gz;
}
