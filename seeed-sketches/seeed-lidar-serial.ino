
#ifndef LD06_FOR_ARDUINO
#define LD06_FOR_ARDUINO
#include <vector>

class LD06forArduino
{
  private:
    // note: 12 data *3 Byte
    const int DATA_BYTE = 36;
    // note: 1(Start)+2(Datalen)+2(Speed)+2(SAngle)+36(DataByte)+2(EAngle)+2(TimeStamp)+1(CRC)
    const int TOTAL_DATA_BYTE = 48;

    void calc_lidar_data(std::vector<char> &values);
  public:
    std::vector<float> angles;
    std::vector<float> distances;
    std::vector<int> confidences;

    char start_byte;
    char data_length;
    float Speed;
    float FSA;
    float LSA;
    int time_stamp;
    int CS;
    float angle_step;

    void Init(const int pin);
    void read_lidar_data();
};

#endif



LD06forArduino ld06;

void setup() {
 // M5.begin(true, false, true);
  delay(10);
  Serial.begin(115200);
  ld06.Init(19);  // pin not used 
}

void loop() {
  // put your main code here, to run repeatedly:
 // M5.update();

  //Serial.println("data start");
  ld06.read_lidar_data();

 // Serial.printf("start_bytet:%d, data_length:%d, Speed:%f, FSA:%f, LSA:%f, time_stamp:%d, CS:%d",  ld06.start_byte, ld06.data_length, ld06.Speed, ld06.FSA, ld06.LSA, ld06.time_stamp, ld06.CS);
   
  Serial.print(ld06.data_length,HEX);
  Serial.print(", ");
  Serial.print(ld06.Speed,HEX);
  Serial.print(", ");
  Serial.print(ld06.start_byte,HEX);
  Serial.print(", ");

  for (int i = 0; i < ld06.data_length; i++) {
    if (ld06.angles[i] > -3 && ld06.angles[i] < 3 && ld06.distances[i] < 300)
      Serial.print("Hit!");
  }


  delay(200);
}





void LD06forArduino::Init(const int pin) {
 // Serial2.begin(230400, SERIAL_8N1, pin);
  //Serial2.begin(230400);
  //Serial2.begin(230400);
  Serial1.begin(115200, SERIAL_8N1, D7, D6); //  XIAO Rx=D7, Tx=D6, others Rx = 4, Tx = 5 will work for ESP32, S2, S3 and C3
 // Serial1.begin(115200); // NOPE!  
 
 // Serial1.begin(230400, SERIAL_8N1, D7, D6); // NOPE! 
}

void LD06forArduino::calc_lidar_data(std::vector<char> &values) {

  start_byte = values[0];
  data_length = 0x1F & values[1];
  Speed = float(values[3] << 8 | values[2]) / 100;
  FSA = float(values[5] << 8 | values[4]) / 100;
  LSA = float(values[values.size() - 4] << 8 | values[values.size() - 5]) / 100;
  time_stamp = int(values[values.size() - 2] << 8 | values[values.size() - 3]);
  CS = int(values[values.size() - 1]);

  if (LSA - FSA > 0) {
    angle_step = (LSA - FSA) / (data_length - 1);
  } else {
    angle_step = (LSA + (360 - FSA)) / (data_length - 1);
  }

  // note: 刻み幅の異常を検知
  if (angle_step > 20) {
    return;
  }

  // note: 過去のデータを初期化
  angles.clear();
  confidences.clear();
  distances.clear();

  for (int i = 0; i < data_length; i++) {
    float raw_deg = FSA + i * angle_step;
    angles.push_back(raw_deg <= 360 ? raw_deg : raw_deg - 360);
    confidences.push_back(values[8 + i * 3]);
    distances.push_back(int(values[8 + i * 3 - 1] << 8 | values[8 + i * 3 - 2]));

  }
}

std::vector<char> tmpChars;

void LD06forArduino::read_lidar_data() {

  // note: Serial２が機能していない場合はスキップ
  if (!Serial1.available()) {
    return;
  }

  bool loopFlag = true;
  char tmpInt;

  while (loopFlag) {
    tmpInt = Serial1.read();

    if (tmpInt == 0x54 && tmpChars.empty()) {
      tmpChars.push_back(tmpInt);
      continue;
    } else if (tmpChars.size() == TOTAL_DATA_BYTE - 1 ) {

      loopFlag = false;
      calc_lidar_data(tmpChars);
      tmpChars.clear();
      continue;

    } else if (tmpChars.size() > 0) {
      if (tmpChars[0] == 0x54) {
        tmpChars.push_back(tmpInt);
      }
      if (tmpChars.size() > 1) {
        if (tmpChars[1] != 0x2C) {
          tmpChars.clear();
        }
      }
    }
  }
}



