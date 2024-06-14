#include <WiFi.h>

void setup() {
  Serial.begin(115200);
 
}

void loop() {
  
  // Print MAC address from WiFi library
  String mac = WiFi.macAddress();
  Serial.println("MAC Address:");
  Serial.println(mac);
  
  // Convert the MAC address to a byte array format
  byte macBytes[6];
  sscanf(mac.c_str(), "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &macBytes[0], &macBytes[1], &macBytes[2], &macBytes[3], &macBytes[4], &macBytes[5]);

  // Print the MAC address in Arduino byte array format
  Serial.println("MAC Address in byte array format: ");
  Serial.print("uint8_t broadcastAddress[] = { ");
  for (int i = 0; i < 6; i++) {
    Serial.print("0x");
    if (macBytes[i] < 0x10) {
      Serial.print("0");
    }
    Serial.print(macBytes[i], HEX);
    if (i < 5) {
      Serial.print(", ");
    }
  }
  Serial.println(" };");
  Serial.println();
  delay(5000); // Ensure serial monitor is ready

}
