/*************************************
This example is from https://github.com/Kongduino/RUI3_LoRa_P2P_PING_PONG
This example needs two devices, a device will send LoRa P2P package after receiving LoRa P2P package.

RAKDAP1   Color Wire  RAK2270 Board and RakClip
3V3       RED         VCC
GND       Black       GND
U_RX      Brown       TX
U_TX      Orange      RX


AT+NWM=0
AT+P2P=?
AT+PFREQ=915000000 

AT+PRECV=?
AT+PRECV=0
AT+PRECV=65533              For both send and receive   

AT+PSEND=616241422031327A      P2P send data   'abAB 12z' 


 *************************************/

long startTime;
bool rx_done = false;
double myFreq = 915000000;  // Europe =  868000000;  North America = 915000000;   
//uint16_t sf = 12, bw = 0, cr = 0, preamble = 8, txPower = 22;




void recv_cb(rui_lora_p2p_recv_t data){
  rx_done = true;
  if (data.BufferSize == 0) {
      Serial.println("Empty buffer.");
      return;
  }
  char buff[92];
  sprintf(buff, "Incoming message, length: %d, RSSI: %d, SNR: %d", data.BufferSize, data.Rssi, data.Snr);
  Serial.println(); 
  Serial.print("Sent Command  AT+PSEND=");
  for (int i = 0; i < data.BufferSize; i++) {
    if (data.Buffer[i] < 0x10) {
      Serial.print("0"); // Print a leading zero for values less than 0x10
    }
    Serial.print(data.Buffer[i], HEX);
  }
  Serial.println();
    
  Serial.write(data.Buffer, data.BufferSize);
  Serial.println(); 
}

void send_cb(void){
   // possibly useful
}

void setup()
{
    Serial.begin(115200);
    Serial.println("RAKwireless LoRa P2P Example");
    Serial.println("Startup delay for emergency AT commands"); // nice, gives you some time to fix dead AT commands
    Serial.println("Start in 5s");
    delay(1000);    
    Serial.println("Start in 4s");
    delay(1000);  
    Serial.println("Start in 3s");
    delay(1000);  
    Serial.println("Start in 2s");
    delay(1000);  
    Serial.println("Start in 1s");
    delay(1000);   
    
    Serial.println("------------------------------------------------------");
    startTime = millis();
    
    if(api.lorawan.nwm.get() != 0)
    {
        Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
        api.system.reboot();
    }

    Serial.println("P2P Start");
    api.lorawan.registerPRecvCallback(recv_cb);
    api.lorawan.registerPSendCallback(send_cb);
    Serial.printf("P2P set Rx mode %s\r\n", api.lorawan.precv(65533) ? "Success" : "Fail");  // set send and receive
    Serial.printf("Set P2P mode frequency %3.3f: %s\r\n", (myFreq / 1e6),api.lorawan.pfreq.set(myFreq) ? "Success" : "Fail");
        


    
}

void loop(){

        if (Serial.available()) {
        String myInput = Serial.readStringUntil('\n');

        if (  ( myInput[0] == 'A'  ||  myInput[0] == 'a' )  &&  ( myInput[1] == 'T'   || myInput[1] == 't' ) )  {
           Serial.println("Delay 5 s for an AT command");
           Serial.write(myInput);   // attempt to send the AT command
           delay(5000); // for AT commands if the above does not work
           Serial.println();
           Serial.println("AT delay over");
        } else {
            Serial.print("Sending: ");
            Serial.println(myInput);
            // Convert the input string to a byte array
            uint8_t myPayload[myInput.length()];
            for (size_t i = 0; i < myInput.length(); i++) {
                myPayload[i] = myInput[i];
            }
            api.lorawan.psend(myInput.length(), myPayload, 0);

        }
    }



}
