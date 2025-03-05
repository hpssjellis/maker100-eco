// dual motor driver
// By Jeremy Ellis
// MIT license


// info here until improved https://github.com/hpssjellis/particle.io-photon-high-school-robotics/tree/master/a11-dc-motor-drivers
//Note: on above A4 was changed to Portenta D5 which allows PWM


// You are suppossed to get it working using the web-app
// Draw your circuit diagram first
// This program will just tell you if  the connections are working
// See https://www.pololu.com/product/2135 for assistance

#include <Arduino.h> // Only needed by https://platformio.org/


void setup() {
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);   // PWM 0 to 256
    pinMode(D5, OUTPUT);   // digital 0 to 1
    pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
    
    digitalWrite(LED_BUILTIN, 0);    // LEDB on internal LED pulled LOW to go on
    digitalWrite(D5, 1);    // set one direction
    digitalWrite(D3, 0);   // go medium
    delay(3000);
    
    analogWrite(D4, 50);     // stop
    delay(3000); 

    analogWrite(D4, 0);     // stop
    delay(3000); 
   
    digitalWrite(D5, 0);    // set the other direction
    digitalWrite(D3, 1);   // go medium   
    delay(1000);    
    
    analogWrite(D4, 50);   // go full speed
    delay(1000);

    analogWrite(D4, 255);   // go full speed
    delay(1000);
    
    analogWrite(D4, 0);     // stop
    digitalWrite(LED_BUILTIN, 1);    // LEDB off
    delay(9000);            // wait 9 seconds
        
}
