/*
| Sensor Type           | IPSO  | LPP   | Hex | Data Size (bytes) | Data Type      | Resolution               |
|-----------------------|-------|-------|-----|-------------------|----------------|--------------------------|
| Digital Input         | 3200  | 0     | 0x00| 1                 | uint8_t        | 1 bit                    |
| Digital Output        | 3201  | 1     | 0x01| 1                 | uint8_t        | 1 bit                    |
| Analog Input          | 3202  | 2     | 0x02| 2                 | int16_t        | 0.01 (signed)            |
| Analog Output         | 3203  | 3     | 0x03| 2                 | int16_t        | 0.01 (signed)            |
| Illuminance Sensor    | 3301  | 101   | 0x65| 2                 | uint16_t       | 1 lux (unsigned MSB)     |
| Presence Sensor       | 3302  | 102   | 0x66| 1                 | uint8_t        | 1 bit                    |
| Temperature Sensor    | 3303  | 103   | 0x67| 2                 | int16_t        | 0.1 °C (signed MSB)      |
| Humidity Sensor       | 3304  | 104   | 0x68| 1                 | uint8_t        | 0.5% (unsigned)          |
| Accelerometer         | 3313  | 113   | 0x71| 6                 | int16_t[3]     | 0.001 G per axis (signed)|
| Barometer             | 3315  | 115   | 0x73| 2                 | uint16_t       | 0.1 hPa (unsigned MSB)   |
| Gyrometer             | 3334  | 134   | 0x86| 6                 | int16_t[3]     | 0.01 °/s per axis (signed)|
| GPS Location          | 3336  | 136   | 0x88| 9                 | int32_t[3]     | Latitude: 0.0001° (signed), Longitude: 0.0001° (signed), Altitude: 0.01 meter (signed) |
| Counter Input         | 5501  | 4     | 0x04| 2                 | uint16_t       | 1 event (unsigned MSB)  |
| Battery Voltage       | 3202  | 255   | 0xFF| 2                 | int16_t        | 0.01 V (signed MSB)      |






*/
// Decode decodes an array of bytes into an object.
//  - fPort contains the LoRaWAN fPort number
//  - bytes is an array of payload, e.g. [225, 230, 255, 0]
// The function must return an object, e.g. {"temperature": 22.5}
function Decode(fPort, bytes) {
    /**
     * @reference https://github.com/myDevicesIoT/cayenne-docs/blob/master/docs/LORA.md
     *
     * Added types for Tektelic Sensor
     * Adapted for lora-app-server from https://gist.github.com/iPAS/e24970a91463a4a8177f9806d1ef14b8
     *
     * Type                 IPSO    LPP     Hex     Data Size   Data Resolution per bit
     *  Digital Input       3200    0       0       1           1
     *  Digital Output      3201    1       1       1           1
     *  Analog Input        3202    2       2       2           0.01 Signed
     *  Analog Output       3203    3       3       2           0.01 Signed
     *  Illuminance Sensor  3301    101     65      2           1 Lux Unsigned MSB
     *  Presence Sensor     3302    102     66      1           1
     *  Temperature Sensor  3303    103     67      2           0.1 °C Signed MSB
     *  Humidity Sensor     3304    104     68      1           0.5 % Unsigned
     *  Accelerometer       3313    113     71      6           0.001 G Signed MSB per axis
     *  Barometer           3315    115     73      2           0.1 hPa Unsigned MSB
     *  Gyrometer           3334    134     86      6           0.01 °/s Signed MSB per axis
     *  GPS Location        3336    136     88      9           Latitude  : 0.0001 ° Signed MSB
     *                                                          Longitude : 0.0001 ° Signed MSB
     *                                                          Altitude  : 0.01 meter Signed MSB
     *  Counter Input       5501    4       4       2           1 event Unsigned MSB
     *  Battery Voltage     3202    255     FF      2           0.01 V Signed MSB (Tektelic Specific)
     */
    var sensor_types = {
            0  : {'size': 1, 'name': 'digital_input', 'readable_name': 'Digital Input', 'signed': false, 'decimal_point': 0,},
            1  : {'size': 1, 'name': 'digital_output', 'readable_name': 'Digital Output', 'signed': false, 'decimal_point': 0,},
            2  : {'size': 2, 'name': 'analog_input', 'readable_name': 'Analog Input', 'signed': true , 'decimal_point': 2,},
            3  : {'size': 2, 'name': 'analog_output', 'readable_name': 'Analog Output', 'signed': true , 'decimal_point': 2,},
            4  : {'size': 2, 'name': 'counter_input', 'readable_name': 'Counter Input', 'signed': false, 'decimal_point': 0,},
            101: {'size': 2, 'name': 'illuminance_sensor', 'readable_name': 'Illuminance Sensor', 'signed': false, 'decimal_point': 0,},
            102: {'size': 1, 'name': 'presence_sensor', 'readable_name': 'Presence Sensor', 'signed': false, 'decimal_point': 0,},
            103: {'size': 2, 'name': 'temperature_sensor', 'readable_name': 'Temperature Sensor', 'signed': true , 'decimal_point': 1,},
            104: {'size': 1, 'name': 'humidity_sensor', 'readable_name': 'Humidity Sensor', 'signed': false, 'decimal_point': 1,},
            113: {'size': 6, 'name': 'accelerometer', 'readable_name': 'Accelerometer', 'signed': true , 'decimal_point': 3,},
            115: {'size': 2, 'name': 'barometer', 'readable_name': 'Barometer', 'signed': false, 'decimal_point': 1,},
            134: {'size': 6, 'name': 'gyrometer', 'readable_name': 'Gyrometer', 'signed': true , 'decimal_point': 2,},
            136: {'size': 9, 'name': 'gps_location', 'readable_name': 'GPS Location', 'signed': false, 'decimal_point': [4,4,2],},
            255: {'size': 2, 'name': 'battery_voltage', 'readable_name': 'Battery Voltage', 'signed': true,  'decimal_point': 2, },};

    function arrayToDecimal(stream, is_signed, decimal_point) {
        var value = 0;
        for (var i = 0; i < stream.length; i++) {
            if (stream[i] > 0xFF)
                throw 'Byte value overflow!';
            value = (value << 8) | stream[i];
        }

        if (is_signed) {
            var edge = 1 << (stream.length) * 8;  // 0x1000..
            var max = (edge - 1) >> 1;             // 0x0FFF.. >> 1
            value = (value > max) ? value - edge : value;
        }

        if (decimal_point) {
            value /= Math.pow(10, decimal_point);
        }

        return value;
    }

    var sensors = {};
    var i = 0;
	while (i < bytes.length) {
	    // console.log(i);
	    // console.log(typeof bytes[i])
	    // console.log(bytes[i].toString())
	    var s_no   = bytes[i++];
		var s_type = bytes[i++];
		if (typeof sensor_types[s_type] == 'undefined')
		    throw 'Sensor type error!: ' + s_type;
	    var s_size = sensor_types[s_type].size;
	    var s_name = sensor_types[s_type].name;

	    switch (s_type) {
    	    case 0  :  // Digital Input
            case 1  :  // Digital Output
            case 2  :  // Analog Input
            case 3  :  // Analog Output
            case 4  :  // Counter input
            case 101:  // Illuminance Sensor
            case 102:  // Presence Sensor
            case 103:  // Temperature Sensor
            case 104:  // Humidity Sensor
            case 113:  // Accelerometer
            case 115:  // Barometer
            case 134:  // Gyrometer
            case 255:  // Tektelic Battery Voltage
                var s_value = arrayToDecimal(bytes.slice(i, i+s_size),
                        is_signed     = sensor_types[s_type].signed,
                        decimal_point = sensor_types[s_type].decimal_point);
                //console.log(format('no:{} size:{} type:{} value:{}', s_no, s_size, s_name, s_value));
                break;
            case 136:  // GPS Location
                var s_value = {
                        'latitude':  arrayToDecimal(bytes.slice(i+0, i+3), is_signed=sensor_types[s_type].signed, decimal_point=sensor_types[s_type].decimal_point[0]),
                        'longitude': arrayToDecimal(bytes.slice(i+3, i+6), is_signed=sensor_types[s_type].signed, decimal_point=sensor_types[s_type].decimal_point[1]),
                        'altitude':  arrayToDecimal(bytes.slice(i+6, i+9), is_signed=sensor_types[s_type].signed, decimal_point=sensor_types[s_type].decimal_point[2]),};
                //console.log(format('no:{} size:{} type:{} lat:{} lon:{} alt:{}', s_no, s_size, s_name, s_value.lat, s_value.lon, s_value.alt));
                break;
        }
        if (typeof(sensors[s_name]) === "undefined") {
            sensors[s_name] = {};
        }
        sensors[s_name][s_no] = s_value;
	    // sensors[s_no] = {'type': s_type, 'type_name': s_name, 'value': s_value };
	    i += s_size;
	}

	return sensors;
}
