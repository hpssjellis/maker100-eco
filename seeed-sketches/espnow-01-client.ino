#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  char myMessage[32];
  int myCount;
} struct_message;

struct_message myData;

void onReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  
  // Print the MAC address of the sender
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Serial.print("Received from: ");
  Serial.println(macStr);

  // Print the received message and count
  Serial.print(myData.myMessage);
  Serial.print(", ");
  Serial.println(myData.myCount);
  Serial.println(); 
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    return;
  }
  esp_now_register_recv_cb(onReceive);
  delay(3000);
  Serial.println("Ready to receive");
}

void loop() {
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH);
}
