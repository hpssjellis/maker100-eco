/* 
*  
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
************************************************ Important stuff if needed ****************************************
*
*
*
********************************************************** end ****************************************************
*
*  Turns on the onboard LED on for one second, then off for three seconds, repeatedly.
*  also checks if Serial Print is working
*  July 22nd, 2020
*  Update Jan 2024
*  by Jeremy Ellis
*  LinkedIn  https://ca.linkedin.com/in/jeremy-ellis-4237a9bb
*  Website https://www.rocksetta.com
*/

#include <Arduino.h> // Only needed by https://platformio.org/

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);   
}

void loop() {
  Serial.println("Serial print works on the XIAO esp32s3 Core 1. The A0 reading is: " + String(analogRead(A0)) );
  digitalWrite(LED_BUILTIN, LOW);   // internal LED LOW = on for onboard LED
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(3000);               
}


