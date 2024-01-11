/***
 *  This example shows LoRaWan protocol joining the network in OTAA mode, class A, region EU868.
 *  Device will send uplink every 20 seconds.
***/


#include <CayenneLPP.h>

#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"

LIS3DH myIMU(I2C_MODE, 0x19); //Default constructor is I2C, addr 0x19.

#define OTAA_PERIOD   (70000)    // 5min 300000

/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

CayenneLPP lpp(51);






void setup()
{
    Serial.begin(115200, RAK_AT_MODE);
    delay(5000);
    Serial.println("wait 15 s so you can connect the serial monitor");
    delay(5000);
    Serial.println("wait 10 s so you can connect the serial monitor");
    delay(5000);
    Serial.println("wait 5 s so you can connect the serial monitor");
    delay(5000);
     
    Serial.println("RAKwireless LoRaWan OTAA Example");
    Serial.println("------------------------------------------------------");



    
    if (!api.lorawan.join())  // Join to Gateway
    {
        Serial.printf("LoRaWan OTAA - join fail! \r\n");
        return;
    }
  
    /** Wait for Join success */
    while (api.lorawan.njs.get() == 0) {
        Serial.print("Wait for LoRaWAN join...");
        api.lorawan.join();
        delay(20000);
    }

    show_at();

/*

    Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF"); // Check Duty Cycle status
    Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");  // Check Confirm status
    
    uint8_t assigned_dev_addr[4] = { 0 };
    api.lorawan.daddr.get(assigned_dev_addr, 4);
    Serial.printf("Device Address is %02X%02X%02X%02X\r\n", assigned_dev_addr[0], assigned_dev_addr[1], assigned_dev_addr[2], assigned_dev_addr[3]);  // Check Device Address
    Serial.printf("Uplink period is %ums\r\n", OTAA_PERIOD);
    Serial.println("");
*/


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

    
    api.lorawan.registerRecvCallback(recvCallback);
    api.lorawan.registerJoinCallback(joinCallback);
    api.lorawan.registerSendCallback(sendCallback);
}




void loop()
{
    static uint64_t last = 0;
    static uint64_t elapsed;
  
    if ((elapsed = millis() - last) > OTAA_PERIOD) {
        Serial.println("Wakeup..");

        
        uplink_routine(); 
        last = millis();        
        Serial.printf("Try sleep %ums..", OTAA_PERIOD);
    }

    api.system.sleep.all(OTAA_PERIOD);

}





void recvCallback(SERVICE_LORA_RECEIVE_T * data)
{
    if (data->BufferSize > 0) {
        Serial.println("Something received!");
        for (int i = 0; i < data->BufferSize; i++) {
            Serial.printf("%x", data->Buffer[i]);
        }
        Serial.print("\r\n");
    }
}

void joinCallback(int32_t status)
{
    Serial.printf("Join status: %d\r\n", status);
}

void sendCallback(int32_t status)
{
    if (status == RAK_LORAMAC_STATUS_OK) {
        Serial.println("Successfully sent");
    } else {
        Serial.println("Sending failed");
    }
}



void uplink_routine()
{


  int myX, myY, myZ;
  byte myX1, myY1, myZ1;
  
  myX = (int)(myIMU.readFloatAccelX() * 1023.0 / 4.0);
  
  myX1 =  (byte)map(myX, 0, 1023, 0, 255);
  
  myY = (int)(myIMU.readFloatAccelY() * 1023.0 / 4.0);
  myY1 = (byte)map(myY, 0, 1023, 0, 255);
  
  myZ = (int)(myIMU.readFloatAccelZ() * 1023.0 / 4.0);
  myZ1 = (byte)map(myZ, 0, 1023, 0, 255);

  
  //Get all parameters
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X = ");
  Serial.println(myX);
  Serial.print(" Y = ");
  Serial.println(myY);
  Serial.print(" Z = ");
  Serial.println(myZ);

    
    uint8_t *bufPtr;
    uint8_t data_len = 0;


  lpp.reset();
  // float x = rand() / 10000000.0; //analogRead(A0)
  //  lpp.addTemperature(1, x); 


    // then test the proper way, but it is more than 11 bytes!
   //   lpp.addAccelerometer(9, myX, myY, myZ);


     lpp.addDigitalOutput(1, myX1);
     lpp.addDigitalOutput(2, myY1);
     lpp.addDigitalOutput(3, myZ1);



  Serial.println();
  Serial.print(F("Size of data packet is: "));

  Serial.println(lpp.getSize());
  if (lpp.getSize() >= 11) {     // might be 12 have to test
    Serial.print("AT+LPSEND=2:0:");
  } else {

    Serial.print("AT+SEND=2:");
  
  }
  for (uint8_t i=0; i< lpp.getSize(); i++) {
      if(lpp.getBuffer()[i] < 0X10 ) { Serial.print("0");  }
      Serial.print( lpp.getBuffer()[i], HEX);
    }
  
  Serial.println();


   

    bufPtr = lpp.getBuffer();
    data_len = lpp.getSize();
    memcpy(collected_data , bufPtr  , data_len);


    Serial.println();
    Serial.println("Sending X:" + String(myX1)+ " = "+ String(myX1, HEX));
    Serial.println("Sending Y:" + String(myY1)+  " = "+ String(myY1, HEX));
    Serial.println("Sending Z:" + String(myZ1)+  " = "+ String(myZ1, HEX));
    Serial.println();




    
   if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, false, 1)) {
   // if (api.lorawan.lpsend( 4, 0, (uint8_t *) & collected_data,  data_len )) {
    

        Serial.println("Sending is requested");
    } else {
        Serial.println("Sending failed");
    }
}

void show_at()
{

    // A WORK IN PROGRESS
    Serial.println("General LoRaWan Data from AT commands");


    Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF"); // Check Duty Cycle status
    Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");  // Check Confirm status



   
}





      /*
      // Can do any of these
      // The first number is the channel set to any small int
      lpp.reset();
      lpp.addDigitalInput(1, 0);
      lpp.addDigitalOutput(2, 1);
      lpp.addAnalogInput(3, 1.23f);
      lpp.addAnalogOutput(4, 3.45f);
      lpp.addLuminosity(5, 20304);
      lpp.addPresence(6, 1);
      lpp.addTemperature(7, 26.5f);
      lpp.addRelativeHumidity(8, 86.6f);
      lpp.addAccelerometer(9, 1.234f, -1.234f, 0.567f);
      lpp.addBarometricPressure(10, 1023.4f);
      lpp.addGyrometer(1, -12.34f, 45.56f, 89.01f);
      lpp.addGPS(1, -12.34f, 45.56f, 9.01f);
    
      lpp.addUnixTime(1, 135005160);
      
      lpp.addGenericSensor(1, 4294967295);
      lpp.addVoltage(1, 3.35);
      lpp.addCurrent(1, 0.321);
      lpp.addFrequency(1, 50);
      lpp.addPercentage(1, 100);
      lpp.addAltitude(1 , 50);
      lpp.addPower(1 , 50000);
      lpp.addDistance(1 , 10.555);
      lpp.addEnergy(1 , 19.055);
      lpp.addDirection(1 , 90);
      lpp.addSwitch(1 , 0);
      
      lpp.addConcentration(1 , 512);
      lpp.addColour(1 , 64, 128, 255);
      
      */
    
