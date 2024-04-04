/*************************************
 *
 * Rak Hack made to print the important RAK "AT" commands for both LoRaWan and LoRa P2P settings
 * Documentation of AT and RUI3 API at https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content
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
    Serial.printf("AT+HWMODEL=? Hardware ID: %s\r\n",        api.system.chipId.get().c_str());
    Serial.printf("AT+HWID=?    Model ID: %s\r\n",           api.system.modelId.get().c_str());
    Serial.printf("AT+APIVER=?  RUI API Version: %s\r\n",    api.system.apiVersion.get().c_str());
    Serial.printf("AT+VER=?     Firmware Version: %s\r\n",   api.system.firmwareVersion.get().c_str());
    Serial.printf("AT+CLIVER=?  AT Command Version: %s\r\n", api.system.cliVersion.get().c_str());
    Serial.println();
    Serial.println("At Commands: AT? for help, ATE for echo , ATZ for reset, AT+DEBUG=1 for debug mode");
    Serial.println("At Commands: AT+BOOT to upload code, AT+RUN reset after boot mode");
    Serial.println("At Commands: AT+P2P=?  gives most of the P2P settings");
    Serial.println("At Commands: AT+PSEND=61624142203132      P2P send data   'abAB 12' ");    
    Serial.println("At Commands: AT+PRECV=?   Codes for P2P received data:  try 0= only send, 30000=receive for 30 s, 65533 can receive and send, 65534=wait for one receive then can send, 65535 = only receive");    
   // Serial.println("At Commands: AT+ENCRY=?   P2P mode encryption. 0 default no encryption, 1 encryption");    
    Serial.println();
    
    Serial.printf("AT+NWM=?     network working mode (0 = P2P_LORA, 1 = LoRaWAN, 2 = P2P_FSK)  %d\r\n", api.lorawan.nwm.get());


    Serial.printf("AT+PFREQ=?   P2P mode frequency   AT+PFREQ=915000000: %d\r\n", api.lorawan.pfreq.get());
    Serial.printf("AT+PSF=?     P2P mode spreading factor  5-12: %d\r\n", api.lorawan.psf.get());
    Serial.printf("AT+PBW=?     P2P mode bandwidth      (LORA: 0 = 125, 1 = 250, 2 = 500, 3 = 7.8, 4 = 10.4, 5 = 15.63, 6 = 20.83, 7 = 31.25, 8 = 41.67, 9 = 62.5 FSK: 4800-467000): %d\r\n", api.lorawan.pbw.get());
    Serial.printf("AT+PCR=?     P2P mode code rate     (0=4/5, 1=4/6, 2=4/7, 3=4/8): %d\r\n", api.lorawan.pcr.get());
    Serial.printf("AT+PPL=?     P2P mode preamble length     (5-65535)   default = 8: %d\r\n", api.lorawan.ppl.get());
  //  Serial.printf("AT+PRECV=?   Codes for P2P received data: %d\r\n", api.lorawan.precv());
    Serial.printf("AT+ENCRY=?   P2P mode encryption. 0 default no encryption, 1 encryption: %d\r\n", api.lorawan.encry.get());
    //  Serial.printf("AT+PSEND=61624142203132      P2P send data   'abAB 12' %d\r\n", api.lorawan.psend(sizeof(61624142203132),61624142203132 ));





    Serial.println();
    Serial.println("Switch to LoRaWan mode and resetting in 30s");
    delay(30000);
    api.lorawan.nwm.set(1);
    api.system.reboot();
}




void myLoRaWanPrint(){
    uint8_t buff[8];
    uint8_t buffBig[16];

    Serial.println();
    Serial.println("LoRaWan Information RAK HACK");
    Serial.println("------------------------------------------------------");
    Serial.printf("AT+HWMODEL=? Hardware ID: %s\r\n",        api.system.chipId.get().c_str());
    Serial.printf("AT+HWID=?    Model ID: %s\r\n",           api.system.modelId.get().c_str());
    Serial.printf("AT+APIVER=?  RUI API Version: %s\r\n",    api.system.apiVersion.get().c_str());
    Serial.printf("AT+VER=?     Firmware Version: %s\r\n",   api.system.firmwareVersion.get().c_str());
    Serial.printf("AT+CLIVER=?  AT Command Version: %s\r\n", api.system.cliVersion.get().c_str());
    Serial.println();
    Serial.println("At Commands: AT? for help, ATE for echo , ATZ for reset, AT+DEBUG=1 for debug mode");
    Serial.println("At Commands: AT+BOOT to upload code, AT+RUN reset after boot mode, AT+JOIN attempts to join");
    Serial.println("At Commands: AT+SEND=12:61624142203132     send data   'abAB 12'   11 byte or less send");
    Serial.println("At Commands: AT+LPSEND=2:0:03683C0467067C07730010080200C8   long send     ");
    Serial.println();

    Serial.printf("AT+NWM=?     network working mode (0 = P2P_LORA, 1 = LoRaWAN, 2 = P2P_FSK):   %d\r\n", api.lorawan.nwm.get());





    api.lorawan.deui.get(buff, 8);
    Serial.print("AT+DEVEUI=?  device EUI 8 bytes       ");
    myBuffPrint(buff, 8);
    Serial.println();

    api.lorawan.appeui.get(buff, 8);
    Serial.print("AT+APPEUI=?  application EUI 8 bytes  ");
    myBuffPrint(buff, 8);
    Serial.println();

    api.lorawan.appkey.get(buffBig, 16);
    Serial.print("AT+APPKEY=?  application key 16 bytes ");
    myBuffPrint(buffBig, 16);
    Serial.println();

    uint16_t maskBuff;
    api.lorawan.mask.get(&maskBuff);
    Serial.printf("AT+MASK=?    Channel mask = %04X\r\n", maskBuff);
    Serial.println();


    Serial.printf("AT+NJM=?     network join mode (0 = ABP, 1 = OTAA):   %d\r\n", api.lorawan.njm.get());
    Serial.printf("AT+NJS=?     network join status (0 = not joined, 1 = joined): %d\r\n", api.lorawan.njs.get());




    
    Serial.printf("AT+DR=?      get the data rate US915 0-4: %d\r\n", api.lorawan.dr.get());
    Serial.printf("AT+JOIN      Join to the network through a gateway: %d\r\n", api.lorawan.join());
  //  Serial.printf("AT+SEND=12:112233 Send data in port: hex format (make sure no space at the end, 11 byte limit) %d\r\n", api.lorawan.send(sizeof(112233), 112233, 12););
 //   Serial.printf("AT+LPSEND=2:0:03683C0467067C07730010080200C8 Long send allows more bytes, might have issues %d\r\n", api.lorawan.lpsend(2, 0, 03683C0467067C07730010080200C, sizeof(03683C0467067C07730010080200C)););
    Serial.printf("AT+CLASS=?   Description: LoRa Class 0=A, 1=B, 2=C: %d\r\n", api.lorawan.deviceClass.get());
    Serial.printf("AT+TXP=?     Transmitting power (0 = default highest TX power, 1 - 14 =  TX power): %d\r\n", api.lorawan.txp.get());
    Serial.printf("AT+RSSI=?    Gives the RSSI strength of the last connection: %d\r\n", api.lorawan.rssi.get());
  //  Serial.printf("AT+ARSSI=? Description: Inquire all channel RSSI: %d\r\n", api.lorawan.arssi.get());
  
    Serial.printf("AT+BAND=?    Description: Active region (1 = CN470, 4 = EU868, 5 = US915, 6 = AU915): %d\r\n", api.lorawan.band.get());
    Serial.printf("AT+CFS=?     status of last send command: %d\r\n", api.lorawan.cfs.get());
   // Serial.printf("AT+DR=?    get the data rate: %d\r\n", api.lorawan.dr.get());
  //  Serial.printf("AT+RECV=?  Last received data in hex mode (make sure no space at the end) %d\r\n", api.lorawan.dr.get());

   






    Serial.println();
    Serial.println("Switch to LoRa mode and resetting in 30s");
    delay(30000);
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
  // nothing useful here
}
