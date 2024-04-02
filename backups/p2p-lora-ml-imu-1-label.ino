

// RAK2270 Sticker Tracker Motion machine learning with P2P sending

/*
* RocksettaTinyML by Jeremy Ellis,keyfreemusic@gmail.com
*
* Based on the Arduino Library
* EloquentTinyML by Simone Salerno,eloquentarduino@gmail.com
* https://github.com/eloquentarduino/EloquentTinyML
* 
* Passed from the main program
* #define NUMBER_OF_INPUTS 8
* #define TYPE_OF_INPUTS int32             // uint8_t | int32 | float | bool | double | String 
* 
* #define NUMBER_OF_OUTPUTS 4
* #define TYPE_OF_OUTPUTS float            // uint8_t |int32 | float | bool | double | String 
* 
* #define RETURN_TYPE_FROM_PREDICT float    // void | uint8_t | int32 | float | bool | double | String 
* 
*/



#include <Arduino.h> // Only needed for https://platformio.org/
#include <RocksettaTinyML.h>
#include "rak2270-motion-2-label.h"


#include "SparkFunLIS3DH.h"  // for RAK2270 Sticker Tracker
#include <service_lora_p2p.h>



// GLOBAL VAERIABLES

LIS3DH myIMU(I2C_MODE, 0x19); //Default constructor is I2C, addr 0x19.


#define NUMBER_OF_INPUTS 108    //  3 senses x 36 readings each input array has 25 integer readings
#define NUMBER_OF_OUTPUTS 3    // one float output
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

// GLOBAL VARIABLES
Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;
float myInput[NUMBER_OF_INPUTS];
float myOutput[NUMBER_OF_OUTPUTS];
int myCurrentIndex = 0;



/*

void recv_cb(rui_lora_p2p_recv_t data)
{
    //rx_done = true;
    if (data.BufferSize == 0) 
    {
      Serial.println("Empty buffer.");
    }
    else
    {
    char buff[92];
    sprintf(buff, "Incoming message, length: %d, RSSI: %d, SNR: %d",data.BufferSize, data.Rssi, data.Snr);
    Serial.println(buff);
    }
   // Serial.printf("P2P set Rx mode %s\r\n", api.lorawan.precv(30000) ? "Success" : "Fail");
}

void send_cb()
{

}

*/


void setup() {
  Serial.begin(115200);  
  delay(2000);
  Serial.println("You got 10 seconds to AT+BOOT if things screw up");
  delay(10000);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait

  ml.begin(model_files_model_tflite);   // standard c-header name inside the include file


  //myStart = millis();   // set delay
 // randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles


  // initialize buffer to zeros
  for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
    myInput[i] = 0.0;
  }




  // Now the RAK2270 Accelerometer
  
    myIMU.settings.adcEnabled = 1;
    myIMU.settings.tempEnabled = 1;
    myIMU.settings.accelSampleRate = 50;  //Hz.  Can be: 0,1,10,25,50,100,200,400,1600,5000 Hz
    myIMU.settings.accelRange = 16;      //Max G force readable.  Can be: 2, 4, 8, 16
    myIMU.settings.xAccelEnabled = 1;
    myIMU.settings.yAccelEnabled = 1;
    myIMU.settings.zAccelEnabled = 1;


     //Call .begin() to configure the IMU
    myIMU.begin();

// Now check P2P on the RAK2270 Sticker Tracker

// no room to do that
// expecting all variables to be set up using AT commands such as 

/*


sending api.lorawan.nwm.get(): 0              AT+NWM=?   AT+NWM=0  
sending api.lorawan.pfreq.get(): 915000000    AT+PFREQ=?      AT+PFREQ=915000000
sending api.lorawan.psf.get(): 7              AT+PSF=?        AT+PSF=7
sending api.lorawan.pbw.get(): 0              AT+PBW=?        AT+PBW=0
sending api.lorawan.pcr.get(): 0              AT+PCR=?        AT+PCR=0
sending api.lorawan.ppl.get(): 8              AT+PPL=?        AT+PPL=8   
sending api.lorawan.ptp.get(): 14             AT+PTP=?        AT+PTP=14  

 Test your setup by tring AT+PSEND=112233445566778899AABB


*/




  //  api.lorawan.registerPRecvCallback(recv_cb);
  //  api.lorawan.registerPSendCallback(send_cb); 



    // Initialize LoRa P2P service
  service_lora_p2p_init();
}

void loop() {


//delay(300);


float myX, myY, myZ;

     myX = (myIMU.readFloatAccelX() * 9.8) - 0.50;
     myY = (myIMU.readFloatAccelY() * 9.8) + 0.50;
     myZ = (myIMU.readFloatAccelZ() * -9.8) + 0.50;

 /* 
     Serial.println( String(myX) + "," + String(myY) + "," +  String(myZ)  );
     delay(50);  // careful here what should be the delay ????? Should it be none blocking with a timer??
*/

  myInput[myCurrentIndex] = myX;
  myInput[myCurrentIndex+1] = myY;
  myInput[myCurrentIndex+2] = myZ;

  // this could be done easier
  myCurrentIndex = (myCurrentIndex + 3) % NUMBER_OF_INPUTS; // Wrap around to the beginning when the end is reached.

if (myCurrentIndex % NUMBER_OF_INPUTS == 0) {   // slows down showing the results



  float myPredict = ml.predict(myInput, myOutput); // make the proximity prediction on the last 36 samples

  Serial.print("Predicted: "+String(myPredict)  );  // output with minimal formating
 // Serial.println(String(ml.output[0]) );  
 // Serial.println("--" );  
  Serial.println(", same as Label[0]=1flat:"+String(myOutput[0]) + ", label[1]=2side::" + String(myOutput[1])  );  // output for plotter minimal formating
  
  if (myPredict > 0.50) {  
    digitalWrite(LED_BUILTIN, LOW);    // on for portenta, off for Nano33BleSense, Send for RAK2270-sticker-tracker
    mySendLoRaP2P();
}
else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(40);  // just to slow it a bit
}

}


void mySendLoRaP2P() {
  // Define the payload
  uint8_t payload[] = {0x31, 0x34, 0x31, 0x36, 0x31}; // Hex representation of "314161"

  // Send the payload using the service_lora_p2p_send function
  service_lora_p2p_send(payload, sizeof(payload), false);

  // Add a delay to avoid continuously sending data
  delay(5000); // 5-second delay
}





/*

Sketch uses 177920 bytes (88%) of program storage space. Maximum is 200704 bytes.
Global variables use 37248 bytes (76%) of dynamic memory, leaving 11392 bytes for local variables. Maximum is 48640 bytes.
Low memory available, stability problems may occur.


 */
 
