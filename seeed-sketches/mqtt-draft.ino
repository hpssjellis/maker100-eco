#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

// WiFi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// MQTT Broker
const char* mqtt_broker = "broker.hivemq.com";
const char* mqtt_topic = "esp32/test";
const int mqtt_port = 8883; // Common port for MQTT over SSL

WiFiClientSecure myEspSecureClient;
PubSubClient myClient(myEspSecureClient);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set up secure client
  myEspSecureClient.setInsecure(); // Use this only for testing, in production use proper certificate verification

  // Set up MQTT client
  myClient.setServer(mqtt_broker, mqtt_port);

  // Connect to MQTT Broker
  while (!myClient.connected()) {
    Serial.println("Connecting to MQTT Broker...");
    if (myClient.connect("ESP32Client")) {
      Serial.println("Connected to MQTT Broker");
    } else {
      Serial.print("Failed with state ");
      Serial.print(myClient.state());
      delay(2000);
    }
  }

  // Publish a message
  myClient.publish(mqtt_topic, "Hello from ESP32 over SSL");
}

void loop() {
  myClient.loop();
}
