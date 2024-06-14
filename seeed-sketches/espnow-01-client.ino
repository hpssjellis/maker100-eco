#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  char myMessage[32];
  int myCount;
} struct_message;

struct_message myData;

void onReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print(myData.myMessage);
  Serial.print(", ");
  Serial.println(myData.myCount);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    return;
  }
  esp_now_register_recv_cb(onReceive);
}

void loop() {
  
}
