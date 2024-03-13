/* 
*  a-hello-blink.ino for the Portenta H7
*
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
************************************************ Important stuff if needed ****************************************
*
*  AT            to check serial connection
*  AT+boot       to enter boot loader mode
*  AT+run        tO RESET AND RUN THE CODE
*
********************************************************** end ****************************************************
*
*  Turns on the blue LED for one second, then off for three seconds, repeatedly.
*  also checks if Serial Printing is working
*  July 22nd, 2020
*  by Jeremy Ellis
*  Twitter @rocksetta
*  Website https://www.rocksetta.com
*/

#include <Arduino.h> // Only needed by https://platformio.org/

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Serial print works on the RAK2270. Here is pin15 PA4 reading: " + String(analogRead(PA4)) + ", Pin 16 PA5 reading: " + String(analogRead(PA5)) );
  delay(1000);                      // wait for a second       
}




