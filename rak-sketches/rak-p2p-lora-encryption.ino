long startTime;
uint8_t node_encrypt_key[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};  // obviously change this to your key
uint8_t encrypt_buff[16];

void setup()
{
    Serial.begin(115200);
    startTime = millis();

    Serial.println("P2P Start");

    Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
    Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
    Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
    Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
    Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
    Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
    Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
    Serial.printf("Set P2P mode encryption status %s\r\n", api.lorawan.encry.set(1) ? "Success" : "Fail");
    Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lorawan.enckey.set(node_encrypt_key, 16) ? "Success" : "Fail");

    Serial.printf("P2P encryption status = %s\r\n", api.lorawan.encry.get() ? "Enable" : "Disable");

    api.lorawan.enckey.get(encrypt_buff, 16);
    Serial.printf("P2P encryption Key = 0x");
        for (int i = 0 ; i < 16 ; i++) {
            Serial.printf("%02X", encrypt_buff[i]);
        }
    Serial.println("");

    randomSeed(millis());
}

void loop()
{
    uint8_t payload[] = "payload";

    int rxDelay = random(3000, 5000);

    // Receive P2P data every 10 seconds
    if(millis() - startTime >= 10*1000) {
      Serial.printf("P2P Rx start for %d millisSeconds\r\n", rxDelay);
      startTime = millis();
      Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
      delay(rxDelay);
    } else {

      Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
      delay(1000);
    }

}
