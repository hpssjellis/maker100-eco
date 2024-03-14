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


at+DEBUG=1    set debug mode

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
















## The P2P AT commands also look interesting.

https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#at-nwm



AT+NWM=?  Description: LoRa network work mode[0:LoRa Point-to-point, 1:LoRaWAN].

For p2p must switch to p2p mode AT+NWM=0


AT+P2P=?     View P2P all parameters     <Frequency>:<Spreading Factor>:<Bandwidth>:<Code Rate>:<Preamble Length>:<TX Power>


AT+PFREQ=?     P2P mode frequency       AT+PFREQ=915000000


AT+PSF=?     P2P mode spreading factor     5-12

AT+PBW=?     P2P mode bandwidth      (LORA: 0 = 125, 1 = 250, 2 = 500, 3 = 7.8, 4 = 10.4, 5 = 15.63, 6 = 20.83, 7 = 31.25, 8 = 41.67, 9 = 62.5 FSK: 4800-467000)

AT+PCR=?    P2P mode code rate     (0=4/5, 1=4/6, 2=4/7, 3=4/8)

AT+PPL=?     P2P mode preamble length     (5-65535)   default = 8         AT+PPL=8

AT+PTP=?       P2P mode TX power    TX power (5-22)



AT+PSEND=112233      P2P send data  

AT+SYNCWORD=?    P2P Syncword in P2P Mode

AT+PRECV=?       codes for P2P received data   
AT+PRECV=0    only transmit mode
AT+PRECV=30000   read data for 30 seconds

AT+PRECV=65534   continuously read incoming data never switch to outgoing
AT+PRECV=65535   wait for data without timeout but switch to transmit when it receives anything



AT+ENCRY=?   P2P mode encryption.     0 default no encryption    1 encryption

AT+ENCKEY=?    P2P Encryption Key
AT+ENCKEY=01020304050607080102030405060708   (you make your own 16 hex key, but all nodes need the same key)



AT+PCRYPT=?   P2P crypt status


AT+RFFREQUENCY=?   Frequency in P2P Mode       AT+RFFREQUENCY=915000000

lots more commands





```
AT?


AT+HWMODEL=? Hardware ID: stm32wle5xx
AT+HWID=?    Model ID: rak3172-sip
AT+APIVER=?  RUI API Version: 3.2.8
AT+VER=?     Firmware Version: RUI_4.1.0_RAK3272-SiP
AT+CLIVER=?  AT Command Version: 1.5.12

At Commands: AT? for help, ATE for echo , ATZ for reset, AT+DEBUG=1 for debug mode
At Commands: AT+BOOT to upload code, AT+RUN another way to reset, AT+JOIN attempts to join
At Commands: AT+P2P=?  gives most of the P2P settings
AT+NWM=? network working mode (0 = P2P_LORA, 1 = LoRaWAN, 2 = P2P_FSK)  0
Switch to LoRaWan mode and resetting in 10s

AT+<CMD>?: help on <CMD>
AT+<CMD>: run <CMD>
AT+<CMD>=<value>: set the value
AT+<CMD>=?: get the value

AT+BOOT,R: enter bootloader mode for firmware upgrade
AT+BOOTVER,R: get the version of RUI Bootloader
ATZ,R: triggers a reset of the MCU
ATR,R: restore default parameters
AT+DEBUG,RW: set debug log
ATE,R: show or hide the AT command input
AT+SN,R: get the serial number of the device (max 18 char)
AT+BAT,R: get the battery level (volt)
AT+BUILDTIME,R: get the build time of the firmware
AT+REPOINFO,R: get the commit ID of the firmware
AT+VER,R: get the version of the firmware
AT+FIRMWAREVER,R: get the Customized version of the firmware
AT+CLIVER,R: get the version of the AT command
AT+APIVER,R: get the version of the RUI API
AT+HWMODEL,R: get the string of the hardware model
AT+HWID,R: get the string of the hardware id
AT+ALIAS,RW: add an alias name to the device
AT+SYSV,R: get the System Voltage
AT+SLEEP,W: enter sleep mode for a period of time (ms)
AT+LPM,RW: get or set the low power mode (0 = off, 1 = on)
AT+LPMLVL,RW: get or set the low power mode level
AT+LOCK,R: lock the serial port
AT+PWORD,RW: set the serial port locking password (max 8 char)
AT+BAUD,RW: get or set the serial port baudrate
AT+ATM,R: switch to AT command mode
AT+APPEUI,RW: get or set the application EUI (8 bytes in hex)
AT+APPKEY,RW: get or set the application key (16 bytes in hex)
AT+APPSKEY,RW: get or set the application session key (16 bytes in hex)
AT+DEVADDR,RW: get or set the device address (4 bytes in hex)
AT+DEVEUI,RW: get or set the device EUI (8 bytes in hex)
AT+NETID,RW: get the network identifier (NetID) (3 bytes in hex)
AT+NWKSKEY,RW: get or set the network session key (16 bytes in hex)
AT+MCROOTKEY,RW: get the Mc Root key (16 bytes in hex)
AT+CFM,RW: get or set the confirm mode (0 = off, 1 = on)
AT+CFS,R: get the confirmation status of the last AT+SEND (0 = failure, 1 = success)
AT+JOIN,RW: join network
AT+NJM,RW: get or set the network join mode (0 = ABP, 1 = OTAA)
AT+NJS,R: get the join status (0 = not joined, 1 = joined)
AT+RECV,R: print the last received data in hex format
AT+SEND,W: send data along with the application port
AT+LPSEND,W: send long packet data (max 1000 bytes)
AT+RETY,RW: get or set the number of retransmission of confirm packet data
AT+ADR,RW: get or set the adaptive data rate setting (0 = off, 1 = on)
AT+CLASS,RW: get or set the device class (A = class A, B = class B, C = class C)
AT+DCS,RW: get the ETSI duty cycle setting (0 = disabled, 1 = enabled)
AT+DR,RW: get or set the data rate
AT+JN1DL,RW: get or set the join accept delay between the end of TX and the join RX window 1 in seconds
AT+JN2DL,RW: get or set the join accept delay between the end of TX and the join RX window 2 in seconds
AT+PNM,RW: get or set the public network mode (0 = off, 1 = on)
AT+RX1DL,RW: get or set the delay between the end of TX and the RX window 1 in seconds (1-15)
AT+RX2DL,RW: get or set the delay between the end of TX and the RX window 2 in seconds (2-16)
AT+RX2DR,RW: get or set the RX2 window data rate
AT+RX2FQ,RW: get the RX2 window frequency (Hz)
AT+TXP,RW: get or set the transmitting power
AT+LINKCHECK,RW: get or set the link check setting (0 = disabled, 1 = once, 2 = everytime)
AT+TIMEREQ,RW: request the current date and time (0 = disabled, 1 = enabled)
AT+LBT,RW: get or set the LoRaWAN LBT (support Korea Japan)
AT+LBTRSSI,RW: get or set the LoRaWAN LBT rssi (support Korea Japan)
AT+LBTSCANTIME,RW: get or set the LoRaWAN LBT scantime (support Korea Japan)
AT+PGSLOT,RW: get or set the unicast ping slot periodicity (0-7)
AT+BFREQ,R: get the data rate and beacon frequency (MHz)
AT+BTIME,R: get the beacon time (seconds since GPS Epoch time)
AT+BGW,R: get the gateway GPS coordinate, NetID and GwID
AT+LTIME,R: get the local time
AT+RSSI,R: get the RSSI of the last received packet
AT+ARSSI,R: access all open channel RSSI
AT+SNR,R: get the SNR of the last received packet
AT+MASK,RW: get or set the channel mask to close or open the channel (only for US915, AU915, CN470)
AT+CHE,RW: get or set eight channels mode (only for US915 AU915 CN470)
AT+CHS,RW: get or set single channels mode (only for US915 AU915 CN470)
AT+BAND,RW: get or set the active region (0 = EU433, 1 = CN470, 2 = RU864, 3 = IN865, 4 = EU868, 5 = US915, 6 = AU915, 7 = KR920, 8 = AS923-1 , 9 = AS923-2 , 10 = AS923-3 , 11 = AS923-4 , 12 = LA915)
AT+ADDMULC,W: add a new multicast group
AT+RMVMULC,W: delete a multicast group
AT+LSTMULC,R: view multicast group information
AT+TRSSI,RW: start RF RSSI tone test
AT+TTONE,RW: start RF tone test
AT+TTX,RW: set number of packets to be sent for PER RF TX test
AT+TRX,RW: set number of packets to be received for PER RF RX test
AT+TCONF,RW: configure LoRa RF test
AT+TTH,RW: start RF TX hopping test from Fstart to Fstop, with Fdelta steps
AT+TRTH,RW: start RF TX hopping test from Fstart to Fstop, with Fdelta interval in random sequence
AT+TOFF,RW: stop ongoing RF test
AT+CERTIF,RW: set the module in LoraWAN certification mode (0 = normal mode, 1 = certification mode)
AT+CW,RW: start continuous wave
AT+NWM,RW: get or set the network working mode (0 = P2P_LORA, 1 = LoRaWAN, 2 = P2P_FSK)
AT+PFREQ,RW: configure P2P Frequency (Note:This command will be deleted in the future)
AT+PSF,RW: configure P2P Spreading Factor (5-12)(Note:This command will be deleted in the future)
AT+PBW,RW: configure P2P Bandwidth(LORA: 0 = 125, 1 = 250, 2 = 500, 3 = 7.8, 4 = 10.4, 5 = 15.63, 6 = 20.83, 7 = 31.25, 8 = 41.67, 9 = 62.5  FSK:4800-467000)(Note:This command will be deleted in the future)
AT+PCR,RW: configure P2P Code Rate(0=4/5, 1=4/6, 2=4/7, 3=4/8)(Note:This command will be deleted in the future)
AT+PPL,RW: configure P2P Preamble Length (5-65535)(Note:This command will be deleted in the future)
AT+PTP,RW: configure P2P TX Power(5-22)(Note:This command will be deleted in the future)
AT+PSEND,W: send data in P2P mode
AT+PRECV,RW: enter P2P RX mode for a period of time (ms)
AT+ENCRY,RW: get or set the encryption status of P2P mode
AT+CAD,RW: get or set the Channel Activity Detection status of P2P mode
AT+ENCKEY,RW: get or set the encryption key of P2P mode (16 bytes in hex)
AT+CRYPIV,RW: get or set the encryption IV of P2P mode (16 bytes in hex)
AT+P2P,RW: get or set all P2P parameters
AT+PBR,RW: get or set the P2P FSK modem bitrate (600-300000 b/s)
AT+PFDEV,RW: get or set the P2P FSK modem frequency deviation (600-200000 hz)
AT+IQINVER,RW: get or set P2P IQ inversion (1 = on, 0 = off)
AT+SYNCWORD,RW: get or set P2P syncword (0x0000 - 0xffff)
AT+RFFREQUENCY,RW: get or set P2P Frequency
AT+TXOUTPUTPOWER,RW: get or set P2P Tx Power(5-22)
AT+BANDWIDTH,RW: get or set P2P Bandwidth(LORA: 0 = 125, 1 = 250, 2 = 500, 3 = 7.8, 4 = 10.4, 5 = 15.63, 6 = 20.83, 7 = 31.25, 8 = 41.67, 9 = 62.5  FSK:4800-467000)
AT+SPREADINGFACTOR,RW: get or set P2P Spreading Factor (5-12)
AT+CODINGRATE,RW: get or set P2P Code Rate(0=4/5, 1=4/6, 2=4/7, 3=4/8)
AT+PREAMBLELENGTH,RW: get or set P2P Preamble Length (5-65535)
AT+FIXLENGTHPAYLOAD,RW: get or set P2P fix length payload on/off ( 1 = on, 0 = off)





```
