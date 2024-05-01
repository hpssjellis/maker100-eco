





/***
 *  This example shows LoRaWan protocol joining the network in OTAA mode, class A, region EU868.
 *  Device will send uplink every 20 seconds.
***/


#include <CayenneLPP.h>

#define OTAA_PERIOD   (120000)   // 120000 = 2 minutes

/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

CayenneLPP lpp(51);




#define NTC_EN    WB_A1
#define NTC_ADC   WB_A0

/**
 * @brief Get Temperature from NTC
 * Here is a ln relationship. T = 84.987-25.18*ln(10*V/(3.3-V))
 */
float getTemperature() 
{
  float max, ref;
  
  pinMode(NTC_EN, OUTPUT);
  digitalWrite(NTC_EN, HIGH);
  delay(200);

  analogReadResolution(10);
  pinMode(NTC_EN, OUTPUT);

    switch (udrv_adc_get_resolution()) {
        case UDRV_ADC_RESOLUTION_6BIT:
        {
            max = 64.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_8BIT:
        {
            max = 256.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_10BIT:
        default:
        {
            max = 1024.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_12BIT:
        {
            max = 4096.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_14BIT:
        {
            max = 16384.0;
            break;
        }
    }

    switch (udrv_adc_get_mode()) {
        case UDRV_ADC_MODE_DEFAULT:
        default:
        {
            #ifdef rak11720
            ref = 2.0;
            #else
            ref = 3.6;
            #endif
            break;
        }
        #ifdef rak11720
        case UDRV_ADC_MODE_1_5:
        {
            ref = 1.5;
            break;
        }
        #else
        case UDRV_ADC_MODE_3_3:
        {
            ref = 3.3;
            break;
        }
        case UDRV_ADC_MODE_3_0:
        {
            ref = 3.0;
            break;
        }
        case UDRV_ADC_MODE_2_4:
        {
            ref = 2.4;
            break;
        }
        case UDRV_ADC_MODE_1_8:
        {
            ref = 1.8;
            break;
        }
        case UDRV_ADC_MODE_1_2:
        {
            ref = 1.2;
            break;
        }
        #endif
    }

  float vbat = api.system.bat.get();
  uint16_t tv = analogRead(NTC_ADC);
  float tv2 = (tv * vbat)/max;
  float tmp = 84.987 - 25.18 *log(10*tv2/(vbat-tv2));
  
  delay(100);
  digitalWrite(NTC_EN, LOW);
  
  return tmp;
}

/**
 * @brief Calibrate Temperature
 * 1st: y = (0.00312f * x^2) + (0.927f * x) - 1.2f
 * 2nd: y = (0.976f * x) - 1.11
 */
float calibrateTemperature(float temp)
{
  float temp2 = (0.00312f * temp * temp) + (0.927f * temp) - 1.2f;
  temp2 = (0.976f * temp2) - 1.11;
  return temp2;
}



void uplink_routine()
{

  


    
    uint8_t *bufPtr;
    uint8_t data_len = 0;


    float voltage = api.system.bat.get();
    Serial.printf("Battery Voltage: %2.2fV, ", voltage);
    // uint16_t intVoltage = (uint16_t)(voltage * 100);
    uint16_t intVoltage = (uint16_t)round(voltage * 100.0);

    
    float tempT = getTemperature();
    float temperature = calibrateTemperature(tempT);
    
  
    lpp.reset(); 
    lpp.addTemperature(1, temperature); 
  //  lpp.addVoltage(2, intVoltage);  // this needs to be an integer int16 so 3.45 V is 345 etc

    bufPtr = lpp.getBuffer();
    data_len = lpp.getSize();
    memcpy(collected_data , bufPtr  , data_len);




    Serial.printf("Battery Voltage: %2.2fV, ", voltage);
    Serial.printf("Sending   NTC_Temp.: %4.2f Degrees Celcius\r\n", temperature);    
    Serial.println();
    if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, false, 1)) {
    

        Serial.println("Sending is requested");
    } else {
        Serial.println("Sending failed");
    }
}



void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200, RAK_AT_MODE);
    delay(5000);
    Serial.println("wait 15 s connect serial monitor");
    delay(5000);
    Serial.println("wait 10 s");
    delay(5000);
    Serial.println("wait 5 s"); 
    delay(5000);
     
    Serial.println("RAKwireless LoRaWan OTAA Example");
    Serial.println("------------------------------------------------------");



    
    if (!api.lorawan.join())  // Join to Gateway
    {
        Serial.printf("LoRaWan OTAA - join fail! \r\n");
        return;
    }
  
    /** Wait for Join success */
    while (api.lorawan.njs.get() == 0) {
        Serial.print("Wait for LoRaWAN join...");
        api.lorawan.join();
        delay(10000);
    }

   
    
    api.lorawan.registerRecvCallback(recvCallback);
    api.lorawan.registerJoinCallback(joinCallback);
    api.lorawan.registerSendCallback(sendCallback);
}

void loop() {

/*
  float voltage = api.system.bat.get();
  Serial.printf("Battery Voltage: %2.2fV, ", voltage);
  float tempT = getTemperature();
  float temperature = calibrateTemperature(tempT);
  Serial.printf("NTC_Temp.: %4.2f Degrees Celcius\r\n", temperature);
 // delay(5000);
*/
 
    static uint64_t last = 0;
    static uint64_t elapsed;
  
    if ((elapsed = millis() - last) > OTAA_PERIOD) {
        Serial.println("Wakeup..");
        uplink_routine(); 
        last = millis();        
        Serial.printf("Try sleep %ums..", OTAA_PERIOD);
    }

    api.system.sleep.all(OTAA_PERIOD);

  

}







void recvCallback(SERVICE_LORA_RECEIVE_T * data)
{
    if (data->BufferSize > 0) {
        Serial.println("Something received!");
        for (int i = 0; i < data->BufferSize; i++) {
            Serial.printf("%x", data->Buffer[i]);
        }
        Serial.print("\r\n");
    }
}

void joinCallback(int32_t status)
{
    Serial.printf("Join status: %d\r\n", status);
}

void sendCallback(int32_t status)
{
    if (status == RAK_LORAMAC_STATUS_OK) {
        Serial.println("Successfully sent");
    } else {
        Serial.println("Sending failed");
    }
}



      /*
      // Can do any of these
      // The first number is the channel set to any small int
      lpp.reset();
      lpp.addDigitalInput(1, 0);
      lpp.addDigitalOutput(2, 1);
      lpp.addAnalogInput(3, 1.23f);
      lpp.addAnalogOutput(4, 3.45f);
      lpp.addLuminosity(5, 20304);
      lpp.addPresence(6, 1);
      lpp.addTemperature(7, 26.5f);
      lpp.addRelativeHumidity(8, 86.6f);
      lpp.addAccelerometer(9, 1.234f, -1.234f, 0.567f);
      lpp.addBarometricPressure(10, 1023.4f);
      lpp.addGyrometer(1, -12.34f, 45.56f, 89.01f);
      lpp.addGPS(1, -12.34f, 45.56f, 9.01f);
    
      lpp.addUnixTime(1, 135005160);
      
      lpp.addGenericSensor(1, 4294967295);
      lpp.addVoltage(1, 3.35);
      lpp.addCurrent(1, 0.321);
      lpp.addFrequency(1, 50);
      lpp.addPercentage(1, 100);
      lpp.addAltitude(1 , 50);
      lpp.addPower(1 , 50000);
      lpp.addDistance(1 , 10.555);
      lpp.addEnergy(1 , 19.055);
      lpp.addDirection(1 , 90);
      lpp.addSwitch(1 , 0);
      
      lpp.addConcentration(1 , 512);
      lpp.addColour(1 , 64, 128, 255);
      
      */
    
