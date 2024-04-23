/***
 *  This example shows LoRaWan protocol joining the network in OTAA mode, class A, region EU868.
 *  Device will send uplink every 20 seconds.
***/


#include <CayenneLPP.h>

#define OTAA_PERIOD   (120000)

/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

CayenneLPP lpp(51);










void setup()
{
    Serial.begin(115200, RAK_AT_MODE);
    delay(5000);
    Serial.println("wait 15 s connect serial monitor");
    delay(5000);
    Serial.println("wait 10 s");
    delay(5000);
    Serial.println("wait 5 s"); 
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
        delay(10000);
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

  


    
    uint8_t *bufPtr;
    uint8_t data_len = 0;


  lpp.reset();
  float x = rand() / 10000000.0; //analogRead(A0)
  lpp.addTemperature(1, x); 

    bufPtr = lpp.getBuffer();
    data_len = lpp.getSize();
    memcpy(collected_data , bufPtr  , data_len);


    Serial.println();
    Serial.println("Sending:" + String(x, 1));

    if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, false, 1)) {
    

        Serial.println("Sending is requested");
    } else {
        Serial.println("Sending failed");
    }
}

void show_at()
{

    // A WORK IN PROGRESS
    Serial.println("General LoRaWan Data from AT commands");


//   Serial.printf("DevEui: %s\r\n", api.lorawan.deui.get());
  //  Serial.printf("AppEui: %s\r\n", api.lorawan.appeui.get() );
  //  Serial.printf("AppKey: %s\r\n", api.lorawan.appkey.get() );

    Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF"); // Check Duty Cycle status
    Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");  // Check Confirm status





    
   
}
