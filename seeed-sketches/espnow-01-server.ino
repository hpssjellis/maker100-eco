#include <esp_now.h>
#include <WiFi.h>
int myNum = 0;


// No Need to change this
uint8_t broadcastAddress[] ={0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char myMessage[32];
  int myCount;

} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  Serial.println();
 
}
 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
 
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
 
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  delay(3000);
  Serial.println("Broadcasting information ....");
}
 
void loop() {
  myNum++;
  // sprintf(myData.myMessage, "Number Received: %d", myNum);
  sprintf(myData.myMessage, "Hello");
  myData.myCount = myNum;

 
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    digitalWrite(LED_BUILTIN, LOW);
    String mac = WiFi.macAddress();
    Serial.print("Sent from: ");
    Serial.println(mac);
    Serial.print("Sent: ");
    Serial.print(myData.myMessage);
    Serial.print(", ");
    Serial.println(myData.myCount);
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(5000);
  digitalWrite(LED_BUILTIN, HIGH);
}
