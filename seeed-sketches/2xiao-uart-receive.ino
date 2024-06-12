/*
 * This code is for the receiver
 * 
 * UART Serial connectivity between two XIAO boards
 * Connect GND to GND
 * Connect 3V3 to 3V3 to power the transmitter
 * Connect RX (D7) on Receiver to TX (D6) on Transmitter
 * 
 */



void setup() {
  Serial1.begin(9600);
  Serial.begin(115200);
}

void loop() {
  if (Serial1.available()) {
   // String receivedData = Serial1.readString();
    String receivedData = Serial1.readStringUntil('\n');
    Serial.println("Received: " + receivedData);
  }
}
