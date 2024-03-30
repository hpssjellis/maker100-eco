/******************************************************************************
*
* Rak-IMU Simple RAK2270 acceleration example
*
* Note: Serial speed is important 115200 is the best to use.
******************************************************************************/

#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"

LIS3DH myIMU(I2C_MODE, 0x19); //Default constructor is I2C, addr 0x19.

void setup() {

  Serial.begin(115200);
  delay(1000); //relax...
  Serial.println("Processor came out of reset.");

  myIMU.settings.adcEnabled = 1;
  myIMU.settings.tempEnabled = 1;
  myIMU.settings.accelSampleRate = 50;  // Hz.  Can be: 0, 1, 10, 25, 50, 100, 200, 400, 1600, 5000 Hz
  myIMU.settings.accelRange = 4;        // Max G force readable.  Can be: 2, 4, 8, 16
  myIMU.settings.xAccelEnabled = 1;
  myIMU.settings.yAccelEnabled = 1;
  myIMU.settings.zAccelEnabled = 1;

  myIMU.begin();

}


void loop(){
  float myX, myY, myZ;
  
  // do math conversions here if you want
  myX = myIMU.readFloatAccelX()*9.8 + 0.0;
  myY = myIMU.readFloatAccelY()*9.8 + 0.0;
  myZ = myIMU.readFloatAccelZ()*9.8 + 0.0;

 Serial.println("x; " + String(myX, 2) + ", y; " + String(myY, 2) + ",z; " + String(myZ, 2) );

  delay(3000);
}
