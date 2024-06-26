
/*
 *  
 *  seeed-i2c-2xiao-transmitter.ino
 *  
 *   Instructions: 
 *   IMPORTANT: Connect Arduino 1 receiver 3V3 TO 4.7 kOHM RESISTOR TO SDA (on XIAO SDA D4)
 *   IMPORTANT: Connect Arduino 1 receiver 3V3 TO 4.7 kOHM RESISTOR TO SCL (on XIAO SCL D5)
 *   Connect Arduino 1 receiver GND to Arduino 2 transmitter GND
 *   Connect Arduino 1 receiver 3V3 to Arduino 2 transmitter 3V3 
 *   Connect Arduino 1 receiver SDA to Arduino 2 transmitter SDA  (on XIAO SDA D4)
 *   Connect Arduino 1 receiver SCL to Arduino 2 transmitter SCL  (on XIAO SCL D5)
 *   Upload seeed-i2c-2xiao-receiver.ino to Arduino 1 
 *   Upload seeed-i2c-2xiao-transmitter.ino to Arduino 2 
 *   Watch Serial Monitor on Arduino 1 receiver
 * 
*/


#include <Wire.h> 

#define receiverAddress 9 

uint8_t counter = 0; 

void setup() { 
  Serial.begin(115200); 
  Wire.begin(); 
} 

 

void loop() { 
  counter++; 
  if (counter > 255) { 
    counter = 0; 
  } 

  Wire.beginTransmission(receiverAddress); 
  Wire.write(counter); 
  Wire.endTransmission(); 
  Serial.println("Sent "+String(counter)); 
  delay(500); 

} 

 
