/*
 * 
 * Must use portenta with Vision Shield Camera and Waveform 128x128 grayscale OLED 
 * Until then needs the 2 main library folders Portenta_Camera and Himax_HM01B0
 * 
 * 
 *
 * Purchase here https://www.waveshare.com/1.5inch-OLED-Module.htm about $29 USD
 *


 *  FOR the GRAYSCALE Waveshare OLED
 *   black GND 
 *   red 3v3  on Portenta  must be 5V on XIAO esp32S3   
 *   blue  DIN (mosi) D8 on Portenta  // D10 on XIAO esp32S3 
 *   yellow (sck) D9 on Portenta     // D8 on XIAO esp32S3 
 *   orange (cs) D7
 *   green (dc)  D6
 *   white (reset) not needed but D14 if you did
 *
 * another reference here 
 * https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
 *
 */

/*

NOTE: Must have compile setting 
PSRAM: OPI PSRAM 

typedef enum {
    FRAMESIZE_96X96,    // 96x96
    FRAMESIZE_QQVGA,    // 160x120
    FRAMESIZE_QCIF,     // 176x144
    FRAMESIZE_HQVGA,    // 240x176
    FRAMESIZE_240X240,  // 240x240
    FRAMESIZE_QVGA,     // 320x240
    FRAMESIZE_CIF,      // 400x296
    FRAMESIZE_HVGA,     // 480x320
    FRAMESIZE_VGA,      // 640x480
    FRAMESIZE_SVGA,     // 800x600
    FRAMESIZE_XGA,      // 1024x768
    FRAMESIZE_HD,       // 1280x720
    FRAMESIZE_SXGA,     // 1280x1024
    FRAMESIZE_UXGA,     // 1600x1200
    // 3MP Sensors
    FRAMESIZE_FHD,      // 1920x1080
    FRAMESIZE_P_HD,     //  720x1280
    FRAMESIZE_P_3MP,    //  864x1536
    FRAMESIZE_QXGA,     // 2048x1536
    // 5MP Sensors
    FRAMESIZE_QHD,      // 2560x1440
    FRAMESIZE_WQXGA,    // 2560x1600
    FRAMESIZE_P_FHD,    // 1080x1920
    FRAMESIZE_QSXGA,    // 2560x1920
    FRAMESIZE_INVALID
} framesize_t;
*
*
*
typedef enum {
    PIXFORMAT_RGB565,    // 2BPP/RGB565
    PIXFORMAT_YUV422,    // 2BPP/YUV422
    PIXFORMAT_YUV420,    // 1.5BPP/YUV420
    PIXFORMAT_GRAYSCALE, // 1BPP/GRAYSCALE
    PIXFORMAT_JPEG,      // JPEG/COMPRESSED
    PIXFORMAT_RGB888,    // 3BPP/RGB888
    PIXFORMAT_RAW,       // RAW
    PIXFORMAT_RGB444,    // 3BP2P/RGB444
    PIXFORMAT_RGB555,    // 3BP2P/RGB555
} pixformat_t;

*

*/

#include "esp_camera.h"



//#if defined(CAMERA_MODEL_XIAO_ESP32S3)
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


#include <Adafruit_SSD1327.h>

// Used for software SPI
#define OLED_CLK D8     // on XIAO
#define OLED_MOSI D10   // on XIAO

// Used for software or hardware SPI
#define OLED_CS D7
#define OLED_DC D6

// Used for I2C or SPI
#define OLED_RESET -1

// software SPI
//Adafruit_SSD1305 display(128, 64, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
// hardware SPI
Adafruit_SSD1327 display(128, 128, &SPI, OLED_DC, OLED_RESET, OLED_CS);

// I2C
//Adafruit_SSD1327 display(128, 128, &Wire, OLED_RESET, 1000000);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2




void setup()   {                
  Serial.begin(115200);
  //while (! Serial) delay(100);



  if ( ! display.begin(0x3D) ) {
     Serial.println("Unable to initialize OLED");
     while (1) yield();
  }    
  display.setTextSize(1);
  display.setTextColor(SSD1327_WHITE);

  display.setRotation(0);
  display.setCursor(0,0);

Serial.begin(115200);
  randomSeed(analogRead(0));  // Seed the random number generator
  //imageCount = random(100000);
  // while(!Serial); // When the serial monitor is turned on, the program starts to execute
  //delay(10000);  // to plug in serial monitor

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


  config.frame_size = FRAMESIZE_96X96;   // FRAMESIZE_240X240;
  config.pixel_format = PIXFORMAT_GRAYSCALE;   //  PIXFORMAT_RAW; 

  //config.frame_size = FRAMESIZE_UXGA;
  //config.pixel_format = PIXFORMAT_JPEG; // for streaming

  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  //config.fb_count = 1;
  config.fb_count = 2;
  



/*

  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if(config.pixel_format == PIXFORMAT_JPEG){
    if(psramFound()){
      config.jpeg_quality = 10;
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // Limit the frame size when PSRAM is not available
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // Best option for face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }



  */

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  

}


void loop() {
  display.clearDisplay();                 // clear the internal memory

  
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Failed to get camera frame buffer");
    return;
  } 
  
  //else {Serial.println("Image taken");}
  //delay(1000);



  //if (cam.grabFrame(fb, 3000) == 0) {
     // Serial.write(fb.getBuffer(), cam.frameSize());

    uint8_t* myBuf = fb->buf;
    uint32_t myLen = fb->len;
    for (int x=0; x < 96; x++){     // FRAME_BUFFER_COLS = 320
       for (int y=0; y < 96; y++){       //FRAME_BUFFER_ROWS = 320
          uint8_t myGRAY = myBuf[(y * 96) + x];  

          int myGrayMap = map( myGRAY, 0, 255, 0, 15);  
          int xMap = map(x, 0, 96, 0, 127);
          int yMap = map(y, 0, 96, 0, 127);
          display.drawPixel(xMap, yMap, myGrayMap );        //  XIAO GRAYSCALE 96x96      grayscale 0-255, 128x128  //128 x 64
          display.drawPixel(xMap+1, yMap, myGrayMap );      //  trick to fill in missing pixels
          display.drawPixel(xMap, yMap+1, myGrayMap );      //  trick to fill in missing pixels
          display.drawPixel(xMap+1, yMap+1, myGrayMap );    //  trick to fill in missing pixels
      } 
    }     
  //}



  display.drawRect(0,0,128,128, SSD1327_WHITE ); // border around the screen
  display.setCursor(3,3);
  display.println("Rocksetta");
    
  display.display();
  //Serial.println("working");
  esp_camera_fb_return(fb);
}
