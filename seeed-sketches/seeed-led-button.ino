/* 
*  
*
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
************************************************ Important stuff if needed ****************************************
*
* Connect a button to both D6 and the other end to 3V3 (two wires can work as a button)
*
* Must connect the short wire of an LED to a small ohm resistor
* connect the resistor to ground (GND)
* and the long wire of the LED to a digital output D5
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
  pinMode(LED_BUILTIN, OUTPUT);     // LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 
  pinMode(D5, OUTPUT);              // external LED also connected to a resisator and GND
  pinMode(D6, INPUT_PULLDOWN);      // Connect a button or switch from D6to the button to 3V3
}

void loop() {
  if (digitalRead(D6)){
      digitalWrite(LED_BUILTIN, LOW);   // Internal LED on, weird right
      digitalWrite(D5, HIGH);           // External LED on
  } else {
      digitalWrite(LED_BUILTIN, HIGH);   // Internal LED off
      digitalWrite(D5, LOW);           // External LED off  
  }  
  // no delay needed since button/switch controls the action
}



