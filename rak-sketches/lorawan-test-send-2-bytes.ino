
/***
 *  This example shows LoRaWan protocol joining the network in OTAA mode, class A, region EU868.
 *  Device will send uplink every 20 seconds.
***/

#define OTAA_PERIOD   (20000)

/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

void recvCallback(SERVICE_LORA_RECEIVE_T * data){
    if (data->BufferSize > 0) {
        Serial.println("Something received!");
        for (int i = 0; i < data->BufferSize; i++) {
            Serial.printf("%x", data->Buffer[i]);
        }
        Serial.print("\r\n");
    }
}

void joinCallback(int32_t status){
    Serial.printf("Join status: %d\r\n", status);
}


void sendCallback(int32_t status){
    if (status == RAK_LORAMAC_STATUS_OK) {
        Serial.println("Successfully sent");
    } else {
        Serial.println("Sending failed");
    }
}

void setup(){
    Serial.begin(115200, RAK_AT_MODE);
    delay(1000);
    Serial.println("wait 15s to connect serial monitor");
    delay(5000);
    Serial.println("wait 10s to connect serial monitor");
    delay(5000);
    Serial.println("wait 5s to connect serial monitor");
    delay(5000);
  
    Serial.println("RAKwireless LoRaWan OTAA Example");
    Serial.println("------------------------------------------------------");
  
    if(api.lorawan.nwm.get() != 1)
    {
        Serial.printf("Set Node device work mode %s\r\n",
            api.lorawan.nwm.set(1) ? "Success" : "Fail");
        api.system.reboot();
    }

  
 
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
  
    api.lorawan.registerRecvCallback(recvCallback);
    api.lorawan.registerJoinCallback(joinCallback);
    api.lorawan.registerSendCallback(sendCallback);
}

void uplink_routine()
{
    /** Payload of Uplink */
   // uint8_t data_len = 0;                            // rand() / 10000000.0;  or   //  rand() % 10;
   // collected_data[data_len++] = (uint8_t) (rand() % 10);    // sending 23 should be the numbers
   // collected_data[data_len++] = (uint8_t) (rand() % 10);

    String myInput = "23";

   // uint8_t collected_data[myInput.length()];
    for (size_t i = 0; i < myInput.length(); i++) {
       collected_data[i] = myInput[i];
    }

    
    Serial.println("Data Packet:");
    for (int i = 0; i < myInput.length(); i++) {
        Serial.printf("0x%02X ", collected_data[i]);
    }
    Serial.println("");
  
    /** Send the data package */
    if (api.lorawan.send(myInput.length(), (uint8_t *) & collected_data, 2, true, 1)) {
        Serial.println("Sending is requested");
    } else {
        Serial.println("Sending failed");
    }
}

void loop()
{
    static uint64_t last = 0;
    static uint64_t elapsed;
  
    if ((elapsed = millis() - last) > OTAA_PERIOD) {
        uplink_routine();
  
        last = millis();
    }
    //Serial.printf("Try sleep %ums..", OTAA_PERIOD);
    api.system.sleep.all(OTAA_PERIOD);
    //Serial.println("Wakeup..");
}
