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


#define SS D0         // Needed for XIAO-SAMD
const int mySS = SS;  // SS is D7 on XIAO-ESP
 
volatile byte myReceivedData;

void setup() {
  pinMode(mySS, INPUT_PULLUP);
  SPI.begin();
  //SPI.setDataMode(SPI_MODE0); // Set the SPI mode to match the transmitter
  // SPI.setDataMode(SPI_MODE3); // Set the SPI mode to match the transmitter
  //SPI.setClockDivider(SPI_CLOCK_DIV8); // Adjust the clock divider if necessary
  SPI.setClockDivider(SPI_CLOCK_DIV128); // Adjust the clock divider if necessary
  Serial.begin(115200);
}

void loop() {

  if (digitalRead(mySS) == LOW) {
    delay(1);
    // SPI.beginTransaction(SPISettings(1000000, LSBFIRST, SPI_MODE0));
    SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0)); 
    myReceivedData = SPI.transfer(0); // Read data from the transmitter
    
    SPI.endTransaction();
    Serial.print("myReceivedData:");    
    Serial.println(myReceivedData);
    Serial.print("MOSI:"+String(MOSI) + ", MISO:"+String(MISO));
    Serial.println(", SCK:"+String(SCK)+", SS:"+String(SS));
    Serial.println("mySS:"+String(mySS) +", D0:"+String(D0) + ", D2:" + String(D2) + ", D4:" + String(D4) + ", D7:"+String(D7));
    Serial.println("SPI_MODE0:"+String(SPI_MODE0)+", SPI_CLOCK_DIV8:"+String(SPI_CLOCK_DIV8));
    Serial.println("----------------");
    delay(1);
  }
}


/*
 * SPI Data Mode: Determines the clock polarity (CPOL) and clock phase (CPHA). There are four possible modes:

SPI_MODE0 (CPOL = 0, CPHA = 0)
SPI_MODE1 (CPOL = 0, CPHA = 1)
SPI_MODE2 (CPOL = 1, CPHA = 0)
SPI_MODE3 (CPOL = 1, CPHA = 1)
Example: SPI.setDataMode(SPI_MODE0);

Clock Divider: Sets the SPI clock frequency relative to the system clock frequency. Possible dividers are:

SPI_CLOCK_DIV2
SPI_CLOCK_DIV4
SPI_CLOCK_DIV8
SPI_CLOCK_DIV16
SPI_CLOCK_DIV32
SPI_CLOCK_DIV64
SPI_CLOCK_DIV128
Example: SPI.setClockDivider(SPI_CLOCK_DIV8);

Bit Order: Defines whether the most significant bit (MSB) or least significant bit (LSB) is sent first.

MSBFIRST
LSBFIRST
Example: SPI.setBitOrder(MSBFIRST);

Clock Speed: Specifies the desired SPI clock frequency in Hz. This setting is used when more fine-grained control of the SPI clock frequency is required.

Example: SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); (where 1000000 is the clock speed in Hz)






DATA:

XIAO-ESP32C3
myReceivedData:255
MOSI:10, MISO:9, SCK:8, SS:2
mySS:2, D0:2, D2:4, D4:6, D7:20
SPI_MODE0:0, SPI_CLOCK_DIV8:4984833
----------------


XIAO-ESP32S3-Sense
myReceivedData:0
MOSI:9, MISO:8, SCK:7, SS:1
mySS:1, D0:1, D2:3, D4:5, D7:44
SPI_MODE0:0, SPI_CLOCK_DIV8:4984833
----------------




XIAO-SAMD

myReceivedData:255
MOSI:10, MISO:9, SCK:8, SS:0
mySS:0, D0:0, D2:2, D4:4, D7:7
SPI_MODE0:2, SPI_CLOCK_DIV8:12
----------------



From SPI.h
  // Default speed set to 4MHz, SPI mode set to MODE 0 and Bit order set to MSB first.
  SPISettings() { init_AlwaysInline(4000000, MSBFIRST, SPI_MODE0); }

*/
