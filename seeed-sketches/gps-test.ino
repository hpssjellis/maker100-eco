// This is just proof that the GPS is connected correctly and you can get data from satellites. 


// On Portenta Serial1 UART1 (PA_9) TX on pin D14   to Grove GPS RX  they flip! on XIAO is D6 (TX)
// On Portenta Serial1 UART1 (PA_10) RX on pin D13  to Grove GPS TX    on XIAO is D7 (RX)
// Portenta 3V3 to grove GPS VCC
// Portenta GND to Grove GPS GND


// This works with Grove GPS AIR530

#include <Arduino.h> // Only needed by https://platformio.org/


unsigned char myBuffer[64]; // Buffer to store incoming GPS data
int myIndex = 0; // Index for the buffer



void setup(){ 
    Serial1.begin(9600);                 // the Sensor Serial1 baud rate
    Serial.begin(115200);                     // the Serial port of Arduino baud rate.
    delay(5000);
    Serial.println("GPS ready.");

}
 
void loop() {
  // Check if data is available from the GPS module
  while (Serial1.available()) {
    // Read a byte of data from the GPS module
    char myChar = Serial1.read();
    
    // Add the byte to the buffer if it's not the end of the line
    if (myChar != '\n' && myIndex < sizeof(myBuffer) - 1) {
      myBuffer[myIndex++] = myChar;
    } else {
      // Null-terminate the buffer
      myBuffer[myIndex] = '\0';
      
      // Parse the GPS data
      parseGpsData(myBuffer);
      
      // Reset the buffer index
      myIndex = 0;
    }
  }
}

void parseGpsData(unsigned char *myData) {
  // Look for the GPGGA sentence
  if (strncmp((char*)myData, "$GPGGA", 6) == 0) {
    // Extract latitude and longitude from the parts
    char *myPart;
    
    // Skip the first part (sentence identifier)
    myPart = strtok((char*)myData, ",");
    
    // Extract latitude
    myPart = strtok(NULL, ",");
    myPart = strtok(NULL, ",");
    char myLatitude[10];
    strncpy(myLatitude, myPart, sizeof(myLatitude));
    
    // Extract latitude direction
    myPart = strtok(NULL, ",");
    char myLatitudeDir = myPart[0];
    
    // Extract longitude
    myPart = strtok(NULL, ",");
    char myLongitude[11];
    strncpy(myLongitude, myPart, sizeof(myLongitude));
    
    // Extract longitude direction
    myPart = strtok(NULL, ",");
    char myLongitudeDir = myPart[0];
    
    // Convert latitude and longitude to decimal format
    float myLat = convertToDecimal(myLatitude, myLatitudeDir);
    float myLon = convertToDecimal(myLongitude, myLongitudeDir);
    
    // Print the latitude and longitude to the serial monitor
    Serial.print("Latitude: ");
    Serial.println(myLat, 6);
    Serial.print("Longitude: ");
    Serial.println(myLon, 6);
  }
}

float convertToDecimal(char *myCoordinate, char myDirection) {
  // Convert string to float
  char myDegrees[3];
  strncpy(myDegrees, myCoordinate, 2);
  myDegrees[2] = '\0';
  
  char myMinutes[8];
  strncpy(myMinutes, myCoordinate + 2, sizeof(myMinutes) - 1);
  myMinutes[sizeof(myMinutes) - 1] = '\0';
  
  float myDeg = atof(myDegrees);
  float myMin = atof(myMinutes);
  
  // Convert to decimal degrees
  float myDecimal = myDeg + (myMin / 60.0);
  
  // Adjust for direction
  if (myDirection == 'S' || myDirection == 'W') {
    myDecimal = -myDecimal;
  }
  
  return myDecimal;
}
