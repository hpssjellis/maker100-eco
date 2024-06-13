#include <SPI.h>

//const int mySSPin = D7;
// Note default SS pin is D4

//#define SS D4

void setup() {
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);
  SPI.begin();
}

void loop() {
  digitalWrite(SS, LOW);
  SPI.transfer(42);
  digitalWrite(SS, HIGH);
  delay(1000);
}
