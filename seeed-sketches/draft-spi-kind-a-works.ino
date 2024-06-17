7 /*
Connect all wires the same on both XIAO's

GND      to GND
3V3      to 3V3
MOSI D10 to MOSI D10
MISO D9  to MISO D9
SCK  D8  to SCK  D8
SS  D0   to SS   D0



// Define the pin connections for both master and slave
#define mySS D0   // Slave Select pin
#define myMOSI D10 // Master Out Slave In
#define myMISO D9  // Master In Slave Out
#define mySCK D8   // Serial Clock

void setup() {
  // Set the SPI pins for slave
 // pinMode(myMOSI, INPUT);
 // pinMode(myMISO, OUTPUT);
 // pinMode(mySCK, INPUT);
  pinMode(mySS, OUTPUT);

*/



#include <SPI.h>

// Note: XIAO-ESP32C3  SS is D7

#define SS D0      // Slave Select pin
#define myMOSI D10 // Master Out Slave In
#define myMISO D9  // Master In Slave Out
#define mySCK D8   // Serial Clock

const int mySS = SS;  // SS is D7 on XIAO-ESP
 

void setup() {
  pinMode(mySS, OUTPUT);
  digitalWrite(mySS, HIGH); 
  SPI.begin();
}

void loop() {
  digitalWrite(mySS, LOW);
  //SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); 
  SPI.transfer(42);
  //SPI.endTransaction();
  digitalWrite(mySS, HIGH);
  delay(1000);
}



//then the master

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

 // SPI.setClockDivider(SPI_CLOCK_DIV128); // Adjust the clock divider if necessary
  Serial.begin(115200);
}

void loop() {

  if (digitalRead(mySS) == LOW) {
   // delay(1);

   // SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0)); 
    myReceivedData = SPI.transfer(0); // Read data from the transmitter
    
   // SPI.endTransaction();
    Serial.print("myReceivedData:");    
    Serial.println(myReceivedData);
    Serial.print("MOSI:"+String(MOSI) + ", MISO:"+String(MISO));
    Serial.println(", SCK:"+String(SCK)+", SS:"+String(SS));
    Serial.println("mySS:"+String(mySS) +", D0:"+String(D0) + ", D2:" + String(D2) + ", D4:" + String(D4) + ", D7:"+String(D7));
    Serial.println("SPI_MODE0:"+String(SPI_MODE0));
    Serial.println("----------------");
   // delay(1);
  }
}


// new better slave may work




#include <SPI.h>

#define SS_PIN D0      // Slave Select pin
#define MOSI_PIN D10   // Master Out Slave In
#define MISO_PIN D9    // Master In Slave Out
#define SCK_PIN D8     // Serial Clock

volatile byte myReceivedData = 0;

void setup() {
  pinMode(SS_PIN, INPUT_PULLUP);  // Set SS pin as input with pull-up resistor
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN);  // Initialize as SPI slave

  // Attach interrupt to the SPI slave select pin
  attachInterrupt(digitalPinToInterrupt(SS_PIN), onReceive, FALLING);

  Serial.begin(115200); // Initialize serial communication for debugging
}

void loop() {
  // Print the received data
  Serial.print("Slave received: ");
  Serial.println(myReceivedData);

  delay(1000);
}

void onReceive() {
  // Receive data from the master
  SPIClass *spi = &SPI;
  myReceivedData = spi->transfer(0);
}




master


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

#define SS_PIN D0      // Slave Select pin
#define MOSI_PIN D10   // Master Out Slave In
#define MISO_PIN D9    // Master In Slave Out
#define SCK_PIN D8     // Serial Clock

void setup() {
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH); 
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SS_PIN);

  Serial.begin(115200); // Initialize serial communication for debugging
}

void loop() {
  digitalWrite(SS_PIN, LOW);  // Select the slave device by pulling chip select low
  //delayMicroseconds(2);

  byte dataToSend = 42; // Data to send to the slave
  byte receivedData = SPI.transfer(dataToSend); // Send data and receive response

 // delayMicroseconds(2);
  digitalWrite(SS_PIN, HIGH);  // Deselect the slave device

  Serial.print("Master sent: ");
  Serial.print(dataToSend);
  Serial.print(", Master received: ");
  Serial.println(receivedData);

  delay(1000); // Wait for 1 second before sending the next data
}





// june 17, 2024  almost working slave


#include <SPI.h>

#define SS_PIN D0      // Slave Select pin
#define MOSI_PIN D10   // Master Out Slave In
#define MISO_PIN D9    // Master In Slave Out
#define SCK_PIN D8     // Serial Clock

volatile byte myReceivedData = 0;

void setup() {
  pinMode(SS_PIN, INPUT_PULLUP);  // Set SS pin as input with pull-up resistor
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN);  // Initialize as SPI slave

  // Attach interrupt to the SPI slave select pin
  attachInterrupt(digitalPinToInterrupt(SS_PIN), onReceive, FALLING);

  Serial.begin(115200); // Initialize serial communication for debugging
}

void loop() {
  // Print the received data
 // Serial.print("Slave received: ");
 // Serial.println(myReceivedData);

  //delay(1000);
}

void onReceive() {
  // Receive data from the master
  SPIClass *spi = &SPI;
  myReceivedData = spi->transfer(56);
}







// almost master

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

#define SS_PIN D0      // Slave Select pin
#define MOSI_PIN D10   // Master Out Slave In
#define MISO_PIN D9    // Master In Slave Out
#define SCK_PIN D8     // Serial Clock

void setup() {
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH); 
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SS_PIN);

  Serial.begin(115200); // Initialize serial communication for debugging
}

void loop() {
  digitalWrite(SS_PIN, LOW);  // Select the slave device by pulling chip select low
  //delayMicroseconds(2);

  byte dataToSend = 42; // Data to send to the slave
  byte receivedData = SPI.transfer(dataToSend); // Send data and receive response

 // delayMicroseconds(2);
  digitalWrite(SS_PIN, HIGH);  // Deselect the slave device

  Serial.print("Master sent: ");
  Serial.print(dataToSend);
  Serial.print(", Master received: ");
  Serial.println(receivedData);

  delay(1000); // Wait for 1 second before sending the next data
}
