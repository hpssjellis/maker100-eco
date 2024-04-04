Most of the orginal sketches were from the Arduino Library [Portenta Pro Community Solutions](https://github.com/hpssjellis/portenta-pro-community-solutions/tree/main/examples) that used a complex dot#### system to code each example.

Not sure yet if I will maintain the dot#'s or not, but code for the RakWireless RAK2270 Sticker Tracker Developer  should be in this folder until moved to a proper Arduino library.



All these examples were first worked out at 

https://github.com/hpssjellis/mcu-stable-edu-launch/tree/main/rak2270-sticker-tracker


Note: The machine learning code is from this github Arduino Library    https://github.com/hpssjellis/RocksettaTinyML

|RAKDAP1 |Color Wire  |RAK2270 Board and RakClip | 
|:---|:---|:---|:---|
|:---|:---|:---|:---|
|:---|:---|:---|:---|
|:---|:---|:---|:---|



## Wires to RAK270 AStcker Tracker RAKDAP1 with RAKCLIP


| RAKDAP1     |  Color Wire  |  RAK2270 Board and RakClip | 
|:---|:---|:---|:---|
| 3V3        | RED          | VCC  |  
| GND        | Black        | GND  | 
| U_RX       | Brown        | TX   | 
| U_TX       |  Orange      | RX   | 




## For LoRaWan


AT command reminders

ATZ       restarts
AT+BOOT   into boot mode
AT+RUN    out of boot mode
AT+?      AT command help
ATE       Toggle echo AT commands



AT+NWM=1        Activate LoRaWan
AT+BAND=?       Description: Active region (1 = CN470, 4 = EU868, 5 = US915, 6 = AU915)

AT+DEVEUI=?     LoRaWan Device EUI (8 byte)
AT+APPEUI=?     LoRaWan Aplication EUI   (8 byte)
AT+APPKEY=?     LoRaWan Aplication Key   (16 Byte)
AT+JOIN         Join Network
AT+NWS          Network Status







## FOR LoRa P2P

AT+NWM=0
AT+P2P=?
AT+PFREQ=915000000      
AT+PSEND=4142207A


AT+PSEND=616241422031327A      P2P send data   'abAB 12z' 



NOTE: to make the board constantly receive you need to set RX on=
AT+PRECV=?   Codes for P2P received data:  try 0= only send, 30000=receive for 30 s, 65533 can receive and send, 65534=wait for one receive then can send, 65535 = only receive");    

AT+PRECV=65535 


