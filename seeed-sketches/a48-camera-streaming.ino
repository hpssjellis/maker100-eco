// >>>> ENABLE OPI PSRAM <<<<

#include <WiFi.h>
#include "esp_camera.h"

const char* ssid = "********";
const char* password = "********";

WiFiServer server(80); // http (default max of 4 clients)
WiFiClient activeClient;

#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     10
#define SIOD_GPIO_NUM     40
#define SIOC_GPIO_NUM     39

#define Y9_GPIO_NUM       48
#define Y8_GPIO_NUM       11
#define Y7_GPIO_NUM       12
#define Y6_GPIO_NUM       14
#define Y5_GPIO_NUM       16
#define Y4_GPIO_NUM       18
#define Y3_GPIO_NUM       17
#define Y2_GPIO_NUM       15
#define VSYNC_GPIO_NUM    38
#define HREF_GPIO_NUM     47
#define PCLK_GPIO_NUM     13

void startCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed: 0x%x", err); // :(
    while (true);
  }
}

void setup() {
  Serial.begin(115200);

  Serial.println("DC "); // wifi initialization is WEIRD and stupid sometimes
  WiFi.disconnect(true);
  Serial.println("DCED ");
  delay(5000);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) { // busy wait
    delay(200);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected: ");
  Serial.println(WiFi.localIP());

  startCamera();
  server.begin();
}

void loop() {
  if (activeClient && !activeClient.connected()) {
    Serial.println("Client disconnected.");
    activeClient.stop();
    activeClient = WiFiClient();
  }

  if (!activeClient || !activeClient.connected()) {
    activeClient = server.available();
    if (activeClient) {
      Serial.println("New client connected");
      activeClient.println("HTTP/1.1 200 OK");
      activeClient.println("Content-Type: multipart/x-mixed-replace; boundary=frame");
      activeClient.println();
    }
  }

  if (activeClient && activeClient.connected()) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) return;

    activeClient.print("--frame\r\n"); // voodoo black magic
    activeClient.print("Content-Type: image/jpeg\r\n");
    activeClient.print("Content-Length: ");
    activeClient.print(fb->len);
    activeClient.print("\r\n\r\n");
    activeClient.write(fb->buf, fb->len);
    activeClient.print("\r\n");

    esp_camera_fb_return(fb);
    delay(10); // fps
  }
}
