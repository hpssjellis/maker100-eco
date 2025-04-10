#include <Arduino.h>

void setup() {
  Serial.begin(115200);

#if ARDUINO_ESP32_MAJOR_VERSION >= 3
  Serial.println("Running code for ESP32 board version 3.x");
  // Run version 3.x specific code
#else
  Serial.println("Running code for ESP32 board version 2.x");
  // Run version 2.x specific code
#endif
}

void loop() {
  // Common or version-specific loop code here
}
