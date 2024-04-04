Most of the orginal sketches were from the Arduino Library [Portenta Pro Community Solutions](https://github.com/hpssjellis/portenta-pro-community-solutions/tree/main/examples) that used a complex dot#### system to code each example.

Not sure yet if I will maintain the dot#'s or not, but code for the RakWireless RAK2270 Sticker Tracker Developer  should be in this folder until moved to a proper Arduino library.



All these examples were first worked out at 

https://github.com/hpssjellis/mcu-stable-edu-launch/tree/main/rak2270-sticker-tracker


Note: The machine learning code is from this github Arduino Library    https://github.com/hpssjellis/RocksettaTinyML







## Wires to RAK270 AStcker Tracker RAKDAP1 with RAKCLIP

| RAKDAP1   |      Color Wire      |  RAK2270 Board and RakClip |
|:----------|:-------------:|:------:|
| 3V3 |  RED |VCC |
| GND |    BLACK   |   GND |
| U_RX | Brown |    TX |
| U_TX | ORANGE |    RX |




.

.


.






## General AT Commands
| AT Command  |    Description      |
|:----------|:-------------|
| ATZ | restarts  |
| AT+BOOT | into boot mode |
| AT+RUN | out of boot mode |
| AT+? | AT command help |
| ATE | Toggle echo AT commands |


.


.


.



## LoRaWan AT Commands

| AT Command  |    Description      |
|:----------|:-------------|
| AT+NWM=1 |  Activate LoRaWan  |
| AT+BAND=? | Description: Active region (1 = CN470, 4 = EU868, 5 = US915, 6 = AU915)   |
|   |   |
| AT+DEVEUI=? |  LoRaWan Device EUI (8 byte) |
| AT+APPEUI=?   |  LoRaWan Aplication EUI   (8 byte) |
| AT+APPKEY=? |  LoRaWan Aplication Key   (16 Byte) |
| AT+JOIN |  Join Network  |
| AT+NWS  | Network Status  |



.



.




.

## LoRa P2P AT Commands

| AT Command  |    Description      |
|:----------|:-------------|
| AT+NWM=0  |  Switch to LoRa P2P mode  |
|  AT+P2P=? |  What are the P2P settings   |
| AT+PFREQ=915000000  |  Set Frequency to 915 MHZ for North America   |
| AT+PRECV=?  |   Codes for P2P received data:  try 0= only send, 30000=receive for 30 s, 65533 can receive and send, 65534=wait for one receive then can send, 65535 = only receive");   |
|   |   |
| AT+PSEND=616241422031327A  | P2P send data  'abAB 12z'   |
|   |   |
| AT+PRECV=56633  |  send and receive messages |













