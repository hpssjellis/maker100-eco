void hexDump(uint8_t * buf, uint16_t len)
{
    char alphabet[17] = "0123456789abcdef";
    Serial.print(F("   +------------------------------------------------+ +----------------+\r\n"));
    Serial.print(F("   |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |\r\n"));
    for (uint16_t i = 0; i < len; i += 16) {
        if (i % 128 == 0)
            Serial.print(F("   +------------------------------------------------+ +----------------+\r\n"));
        char s[] = "|                                                | |                |\r\n";
        uint8_t ix = 1, iy = 52;
        for (uint8_t j = 0; j < 16; j++) {
            if (i + j < len) {
                uint8_t c = buf[i + j];
                s[ix++] = alphabet[(c >> 4) & 0x0F];
                s[ix++] = alphabet[c & 0x0F];
                ix++;
                if (c > 31 && c < 128)
                    s[iy++] = c;
                else
                    s[iy++] = '.';
            }
        }
        uint8_t index = i / 16;
        if (i < 256)
            Serial.write(' ');
        Serial.print(index, HEX);
        Serial.write('.');
        Serial.print(s);
    }
    Serial.print(F("   +------------------------------------------------+ +----------------+\r\n"));
}


void recv_cb(rui_lora_p2p_recv_t data)
{
   // rx_done = true;

    /*
    if (data.BufferSize == 0) {
        Serial.println("Empty buffer.");
        return;
    }
    char buff[92];
    sprintf(buff, "Incoming message, length: %d, RSSI: %d, SNR: %d",
        data.BufferSize, data.Rssi, data.Snr);
    Serial.println(buff);
    hexDump(data.Buffer, data.BufferSize);

    */

    Serial.write(data.Buffer, data.BufferSize);

   // api.lorawan.precv(65535);  // back into receive mode

}

void send_cb(void)
{
   // Serial.printf("P2P set Rx mode %s\r\n",
   // api.lorawan.precv(65534) ? "Success" : "Fail");
}

void setup()
{
  
    Serial.begin(115200,RAK_AT_MODE);
    delay(500);
    Serial.println("RAKwireless LoRaWan P2P Example");
    Serial.println("------------------------------------------------------");
   
    api.lorawan.registerPRecvCallback(recv_cb);
    api.lorawan.registerPSendCallback(send_cb);
    Serial.printf("P2P set permament receive RX mode %s\r\n",api.lorawan.precv(65534) ? "Success" : "Fail");
    // api.lorawan.precv(65534);  // permanent receive
}

void loop(){



/*
  
    uint8_t payload[] = "payload";
    bool send_result = false;
    if (rx_done) {
        rx_done = false;
        while (!send_result) {
            send_result = api.lorawan.psend(sizeof(payload), payload);
            Serial.printf("P2P send %s\r\n", send_result ? "Success" : "Fail");
            if (!send_result) {
                Serial.printf("P2P finish Rx mode %s\r\n", api.lorawan.precv(0) ? "Success" : "Fail");
                delay(1000);
            }
        }
    }
    delay(500);


    */
}

