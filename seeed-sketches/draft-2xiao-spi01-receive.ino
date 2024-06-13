#include <SPI.h>

//const int mySSPin = D7;
// Note default SS pin is D4

//#define SS D4

volatile byte myReceivedData;

void setup() {
  pinMode(SS, INPUT_PULLUP);
  SPI.begin();
  //SPI.setDataMode(SPI_MODE0); // Set the SPI mode to match the transmitter
  //SPI.setClockDivider(SPI_CLOCK_DIV8); // Adjust the clock divider if necessary
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(SS) == LOW) {
    delay(1);
    myReceivedData = SPI.transfer(0); // Read data from the transmitter
    Serial.print("myReceivedData:");    
    Serial.println(myReceivedData);
    //Serial.write(myReceivedData);
    Serial.print("MISO:"+String(MISO)+", MOSI:"+String(MOSI));
    Serial.println("SCK:"+String(SCK)+", SS:"+String(SS));
    Serial.println("D0:"+String(D0) + ", D2:" + String(D2) + ", D4:" + String(D4) + ", D7:"+String(D7));
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

*/
