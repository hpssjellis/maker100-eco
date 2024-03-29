/*************************************
 *
 * Rak Hack made to print all LoRaWan and LoRa P2P settings
 *
*************************************/

void myBuffPrint(uint8_t* myBuff, uint8_t myLen){
    for (int i = 0; i < myLen; i++) {
      if (myBuff[i] < 0x10) {
        Serial.print("0");
      }
    Serial.print(myBuff[i], HEX);
  }
}


void myLoraPrint(){

    Serial.println();
    Serial.println("LoRa P2P Information RAK HACK");
    Serial.println("------------------------------------------------------");
    Serial.printf("Hardware ID: %s\r\n",        api.system.chipId.get().c_str());
    Serial.printf("Model ID: %s\r\n",           api.system.modelId.get().c_str());
    Serial.printf("RUI API Version: %s\r\n",    api.system.apiVersion.get().c_str());
    Serial.printf("Firmware Version: %s\r\n",   api.system.firmwareVersion.get().c_str());
    Serial.printf("AT Command Version: %s\r\n", api.system.cliVersion.get().c_str());
    Serial.println();
    Serial.println("At Commands: AT? for help, ATE for echo , ATZ for reset, AT+DEBUG=1 for debug mode");
    Serial.println("At Commands: AT+BOOT to upload code, AT+RUN another way to reset, AT+JOIN attempts to join");
    Serial.println("At Commands: AT+P2P=?  gives most of the P2P settings");

    Serial.printf("AT+NWM=?   %d\r\n", api.lorawan.nwm.get());







    Serial.println("Switch to LoRaWan mode and resetting in 10s");
    delay(10000);
    api.lorawan.nwm.set(1);
    api.system.reboot();
}

    //Serial.printf("Set P2P mode frequency  %s\r\n",api.lorawan.pfreq.get());
  
  /*
    Serial.printf("Set P2P mode spreading factor %d: %s\r\n", sf,
  		api.lorawan.psf.set(sf) ? "Success" : "Fail");
    Serial.printf("Set P2P mode bandwidth %d: %s\r\n", bw,
  		api.lorawan.pbw.set(bw) ? "Success" : "Fail");
    Serial.printf("Set P2P mode code rate 4/%d: %s\r\n", (cr + 5),
  		api.lorawan.pcr.set(cr) ? "Success" : "Fail");
    Serial.printf("Set P2P mode preamble length %d: %s\r\n", preamble,
  		api.lorawan.ppl.set(preamble) ? "Success" : "Fail");
    Serial.printf("Set P2P mode tx power %d: %s\r\n", txPower,
  		api.lorawan.ptp.set(txPower) ? "Success" : "Fail");
    api.lorawan.registerPRecvCallback(recv_cb);
    api.lorawan.registerPSendCallback(send_cb);
  
*/



void myLoRaWanPrint(){
    uint8_t buff[8];
    uint8_t buffBig[16];

    Serial.println();
    Serial.println("LoRaWan Information RAK HACK");
    Serial.println("------------------------------------------------------");
    Serial.printf("Hardware ID: %s\r\n",        api.system.chipId.get().c_str());
    Serial.printf("Model ID: %s\r\n",           api.system.modelId.get().c_str());
    Serial.printf("RUI API Version: %s\r\n",    api.system.apiVersion.get().c_str());
    Serial.printf("Firmware Version: %s\r\n",   api.system.firmwareVersion.get().c_str());
    Serial.printf("AT Command Version: %s\r\n", api.system.cliVersion.get().c_str());
    Serial.println();
    Serial.println("At Commands: AT? for help, ATE for echo , ATZ for reset, AT+DEBUG=1 for debug mode");
    Serial.println("At Commands: AT+BOOT to upload code, AT+RUN another way to reset, AT+JOIN attempts to join");


    Serial.printf("AT+NWM=?   %d\r\n", api.lorawan.nwm.get());

    api.lorawan.deui.get(buff, 8);
    Serial.print("AT+DEVEUI=?   ");
    myBuffPrint(buff, 8);
    Serial.println();

    api.lorawan.appeui.get(buff, 8);
    Serial.print("AT+APPEUI=?   ");
    myBuffPrint(buff, 8);
    Serial.println();

    api.lorawan.appkey.get(buffBig, 16);
    Serial.print("AT+APPKEY=?   ");
    myBuffPrint(buffBig, 16);
    Serial.println();



    Serial.printf("AT+NWM=?   %d\r\n", api.lorawan.nwm.get());
    Serial.printf("AT+DR=?   %d\r\n", api.lorawan.dr.get());
    Serial.printf("AT+NJM=?   %d\r\n", api.lorawan.njm.get());

   






    Serial.println("Switch to LoRa mode and resetting in 10s");
    delay(10000);
    api.lorawan.nwm.set(0);
    api.system.reboot();

}




void setup(){
    Serial.begin(115200);

 
    if(api.lorawan.nwm.get() == 0) {    // LoRa
       myLoraPrint();
     } else   {
       myLoRaWanPrint(); 
    }


}


void loop(){

}
