
// Expecting all AT P2P commands to be checked or set using AT command entry
/*

sending api.lorawan.nwm.get(): 0
sending api.lorawan.pfreq.get(): 915000000
sending api.lorawan.psf.get(): 7
sending api.lorawan.pbw.get(): 0
sending api.lorawan.pcr.get(): 0
sending api.lorawan.ppl.get(): 8
sending api.lorawan.ptp.get(): 14

 
 */

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

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("RAKwireless LoRaWan P2P Example");
    Serial.println("AT+BOOT for boot mode. You got 5 Seconds if issues in your code");
    delay(5000);

    Serial.println("P2P Start");
  
    Serial.printf("Hardware ID: %s\r\n", api.system.chipId.get().c_str());
    Serial.printf("Model ID: %s\r\n", api.system.modelId.get().c_str());
    Serial.printf("RUI API Version: %s\r\n",api.system.apiVersion.get().c_str());
    Serial.printf("Firmware Version: %s\r\n",api.system.firmwareVersion.get().c_str());
    Serial.printf("AT Command Version: %s\r\n",api.system.cliVersion.get().c_str());


    Serial.print("sending api.lorawan.nwm.get(): ");
    Serial.println(api.lorawan.nwm.get());

    Serial.print("sending api.lorawan.pfreq.get(): ");
    Serial.println(api.lorawan.pfreq.get());
    
    Serial.print("sending api.lorawan.psf.get(): ");
    Serial.println(api.lorawan.psf.get());
  
    Serial.print("sending api.lorawan.pbw.get(): ");
    Serial.println(api.lorawan.pbw.get());
    
    Serial.print("sending api.lorawan.pcr.get(): ");
    Serial.println(api.lorawan.pcr.get());
   
    Serial.print("sending api.lorawan.ppl.get(): ");
    Serial.println(api.lorawan.ppl.get());
    
    Serial.print("sending api.lorawan.ptp.get(): ");
    Serial.println(api.lorawan.ptp.get());

    api.lorawan.registerPRecvCallback(recv_cb);
    api.lorawan.registerPSendCallback(send_cb);   // why?

}

void loop() 
{ 
  uint8_t payload[] = "payload";
  bool send_result = false;
  send_result = api.lorawan.psend(sizeof(payload), payload);
  Serial.printf("P2P send %s\r\n", send_result ? "Success" : "Fail");
  api.lorawan.precv(5000); 
  delay(10000);  //wait for a reply
  api.lorawan.precv(0); // back to send mode

}
