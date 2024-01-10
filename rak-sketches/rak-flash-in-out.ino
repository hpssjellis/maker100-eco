void setup()
{
  Serial.begin(115200);
  delay(2000);
  uint8_t flash_value[4] = {0};
  bool wr_result = false;
  uint32_t data_to_save = 12345678;
  flash_value[0] = (uint8_t)(data_to_save >> 0);
  flash_value[1] = (uint8_t)(data_to_save >> 8);
  flash_value[2] = (uint8_t)(data_to_save >> 16);
  flash_value[3] = (uint8_t)(data_to_save >> 24);

  wr_result = api.system.flash.set(0, flash_value, 4);
}

void loop()
{
  uint8_t flash_read[4] = {0};
  uint32_t flash_data = 0;

  if (api.system.flash.get(0, flash_read, 4))
  {
    flash_data |= flash_read[0] << 0;
    flash_data |= flash_read[1] << 8;
    flash_data |= flash_read[2] << 16;
    flash_data |= flash_read[3] << 24;
    Serial.println(flash_data);
  }
  else
  {
    Serial.println("Failed to read data from Flash");
  }

  delay(2000);
}
