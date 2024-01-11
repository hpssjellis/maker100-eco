
// Connect the ADXL362 breakout: 

// For the XIAO ESP32S3 Sense 

// VIN: 3V3 
// GND: GND 
// SCL: D8 (SCK) 
// SDA: D10 (MOSI) 
// SDO: D9 (MISO) 
// CS: D7 (SS) 


// or
// D10  MOSI
// D9 MISO
// D8 SCK
// D7 SS

// INT1: no connection 

// INT1: no connection 

 
#include <ADXL362.h>

ADXL362 xl;

int16_t temp;
int16_t XValue, YValue, ZValue, Temperature;

void setup(){
  
  Serial.begin(115200);
  xl.begin(D7);                   // Setup SPI protocol, issue device soft reset
  xl.beginMeasure();              // Switch ADXL362 to measure mode  
	
  Serial.println("Start Demo: Simple Read");
}

void loop(){
    
  // read all three axis in burst to ensure all measurements correspond to same sample time
  xl.readXYZTData(XValue, YValue, ZValue, Temperature);  
  Serial.println("m/s^2 --> x: " + String(XValue * 0.0098, 3) + "\t, y: "  + String(YValue * 0.0098, 3) + "\t, z: " + String(ZValue * 0.0098, 3) );
  
  delay(500);                // Arbitrary delay to make serial monitor easier to observe
}
