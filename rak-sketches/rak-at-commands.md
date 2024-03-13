Important API commands here

https://staging.rui-api-docs.rakwireless.com/v3/LoRaWAN/#send







based on my post here on the rak forum   

https://forum.rakwireless.com/t/rak2270-sticker-tracker-nov-2023-update/10800/9


using the RAK documentation for RUI3 


https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content


Note: ? is for help
= set (be very careful)
=? get or show the value

AT? is very useful all the commands

ATE Description: AT Command Echo

ATZ Description: MCU Reset

AT+BOOT Description: Bootloader mode

AT+RUN will reset from bootloader mode. (similar to AT+RESET)

AT+DEVEUI=? Description: Device EUI

AT+APPEUI=? Description: Application identifier

AT+APPKEY=? Description: Application Key




.




.



AT+DR=?   set the DATA rate for US915 can be from 0 to 14  default is 0

AT+JOIN Description: Join LoRaWAN Network (wait a few seconds after the OK. )

AT+NJM=? Description: Network Join Mode (0 = ABP, 1 = OTAA)|

AT+NJS=? Description: LoRa Network Join status(0 = not joined, 1 = joined)|

AT+RECV=? Description: Last received data in hex mode (make sure no space at the end)

AT+SEND=12:112233   Send data in port: hex format (make sure no space at the end  11 byte limit)


AT+LPSEND=2:0:03683C0467067C07730010080200C8    (This works)

AT+CLASS=? Description: LoRa Class A B or C

AT+TXP=?: transmitting power (0 = highest TX power, 14 = lowest TX power) lowest is different

AT+RSSI=?  Gives the RSSI strength of the last connection

AT+ARSSI=? Description: Inquire all channel RSSI

AT+MASK=? Description: Set the channel mask, close or open the channel



AT+BAND=?	Description: Active region
(0 = EU433, 1 = CN470, 2 = RU864, 3 = IN865, 4 = EU868,
5 = US915, 6 = AU915, 7 = KR920, 8 = AS923-1, 9 = AS923-2, 10 = AS923-3, 11 = AS923-4, 12 = LA915)


There are a ton more AT commands. Does anyone else know about any that are really useful.

The P2P AT commands also look interesting.

AT+NWM=?  Description: LoRa network work mode[0:Point-to-point, 1:LoRaWAN].
