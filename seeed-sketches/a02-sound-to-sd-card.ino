// I assume needs board version 3.0.0 I have tested it on board version 3.0.7 which vision also works on.


/*
  Must enable OPI PSRAM, and USB CDC on Boot (Tools menu at top)

  Most code taken from the ESP_I2S example Record_to_WAV.ino (https://github.com/Seeed-Studio/wiki-documents/blob/docusaurus-version/docs/Sensor/SeeedStudio_XIAO/SeeedStudio_XIAO_ESP32S3_Sense/XIAO_ESP32S3_Sense_mic.md)
*/

#include "ESP_I2S.h"
#include "FS.h"
#include "SD.h"

#define RECORD_TIME 5
#define FILE_NAME "sample.wav"

void setup() {
  // Create an instance of the I2SClass
  I2SClass i2s;

  // Create variables to store the audio data
  uint8_t *wav_buffer;
  size_t wav_size;

  // Initialize the serial port
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  Serial.println("Initializing I2S bus...");

  // Set up the pins used for audio input
  i2s.setPinsPdmRx(42, 41);

  // start I2S at 16 kHz with 16-bits per sample
  if (!i2s.begin(I2S_MODE_PDM_RX, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO)) {
    Serial.println("Failed to initialize I2S!");
    while (1); // do nothing
  }

  Serial.println("I2S bus initialized.");
  Serial.println("Initializing SD card...");

  // Set up the pins used for SD card access
  if(!SD.begin(21)){
    Serial.println("Failed to mount SD Card!");
    while (1) ;
  }
  Serial.println("SD card initialized.");
  Serial.printf("Recording %d seconds of audio data...\n", RECORD_TIME);

  wav_buffer = i2s.recordWAV(RECORD_TIME, &wav_size); // record and save raw file data to buffer

  // Create a file on the SD card
  File file = SD.open(("/" + String(FILE_NAME)).c_str(), FILE_WRITE);
  if (!file) {
    Serial.printf("Unable to open %s for writing.\n", FILE_NAME);
    return;
  }

  Serial.println("Writing audio data to file...");

  // Write the audio data to the file
  if (file.write(wav_buffer, wav_size) != wav_size) {
    Serial.println("Failed to write audio data to file!");
    return;
  }

  // Close the file
  file.close();

  Serial.println("Program completed without error");
}

void loop() {
  Serial.printf(".");
  delay(1000);
}
