/*
Connect all wires the same on both XIAO's

GND      to GND
3V3      to 3V3
MOSI D10 to MOSI D10
MISO D9  to MISO D9
SCK  D8  to SCK  D8
SS  D0   to SS   D0

*/



#include <SPI.h>

// Note: XIAO-ESP32C3  SS is D7

#define SS D0         // Needed for XIAO-SAMD
const int mySS = SS;  // SS is D7 on XIAO-ESP
 

void setup() {
  pinMode(mySS, OUTPUT);
  digitalWrite(mySS, HIGH);
  SPI.begin();
  //SPI.setDataMode(SPI_MODE3); // Set the SPI mode to match the transmitter
  SPI.setClockDivider(SPI_CLOCK_DIV128); // Adjust the clock divider if necessary

}

void loop() {
  digitalWrite(mySS, LOW);
  // SPI.beginTransaction(SPISettings(1000000, LSBFIRST, SPI_MODE0));
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0)); 
  SPI.transfer(200);
  SPI.endTransaction();
  digitalWrite(mySS, HIGH);
  delay(1000);
}
