// Instructions:
// Connect Arduino 1's SDA to Arduino 2's SDA
// Connect Arduino 1's SCL to Arduino 2's SCL
// Upload seeed-i2c-2xiao-receiver.ino to Arduino 1
// Upload seeed-i2c-2xiao-transmitter.ino to Arduino 2
// Watch Serial Monitor on Arduino 1

#include <Wire.h>

#define receiverAddress 9

int counter = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  counter++;
  Wire.beginTransmission(receiverAddress);
  Wire.write(counter);
  Wire.endTransmission();
  delay(500);
}
