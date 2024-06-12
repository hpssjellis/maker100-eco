/*
 * This code is for the transmitter
 * 
 * UART Serial connectivity between two XIAO boards
 * Connect GND to GND
 * Connect 3V3 to 3V3 to power the transmitter
 * Connect RX (D7) on Receiver to TX (D6) on Transmitter
 * 
 */


void setup() {
  Serial1.begin(9600);
}

void loop() {
  Serial1.println("Hello from XIAO transmitter");
  delay(1000);
}
