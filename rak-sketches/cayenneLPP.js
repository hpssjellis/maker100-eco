function convertToSignedInt(payload) {
    var sign = payload[0] & (1 << 7);
    var x = (((payload[0] & 0xFF) << 8) | (payload[1] & 0xFF));
    if (sign) {
       x = 0xFFFF0000 | x;  // fill in most significant bits with 1's
    }		    
    return x/10;
}



function Decoder(payload, port) {
    
    var decoded = [];
	
	var sensor_types = {
		0  : {'size': 1, 'name': 'DIGITAL_INPUT_'},
		1  : {'size': 1, 'name': 'DIGITAL_OUTPUT_'},
		2  : {'size': 2, 'name': 'ANALOG_INPUT_'},
		3  : {'size': 2, 'name': 'ANALOG_OUTPUT_'},
		101: {'size': 2, 'name': 'ILLUMINANCE_'},
		102: {'size': 1, 'name': 'PRESENCE_'},
		103: {'size': 2, 'name': 'TEMPERATURE_'},
		104: {'size': 1, 'name': 'HUMIDITY_'},
		113: {'size': 6, 'name': 'ACCELEROMETER_'},
		115: {'size': 2, 'name': 'BAROMETER_'},
		134: {'size': 6, 'name': 'GYROMETER_'},
		136: {'size': 9, 'name': 'GPS_'}
	};    
	
    var i = 0;
    
    while(i < payload.length) { 
        
		s_ch = payload[i++]; 	//Channel
		s_type = payload[i++];	//Message Type
		s_size = sensor_types[s_type].size; //Data length        

		switch (s_type) {
		case 0  :  // Digital Input
		case 1  :  // Digital Output
		case 102:  // Presence 
		    decoded.push({
		        field: sensor_types[s_type].name+s_ch,
		        value: payload[i]<<8 ? 1 : 0
		    });
		    break;			
		case 2  :  // Analog Input
		case 3  :  // Analog Output
		    decoded.push({
		        field: sensor_types[s_type].name+s_ch,
		        value: ((payload[i]<<8 | payload[i+1]))/100
		    });
		    break;				
		case 101:  // Illuminance Sensor
		    decoded.push({field: sensor_types[s_type].name+s_ch, value: ((payload[i]<<8 | payload[i+1]))});
		    break;		
		case 103:  // Temperature Sensor
		    var temp_value = convertToSignedInt(payload.slice(i, i+2));
		    decoded.push({field: sensor_types[s_type].name+s_ch, value: temp_value});
		    break;
		case 104:  // Humidity Sensor
		    decoded.push({field: sensor_types[s_type].name+s_ch, value: payload[i] * 0.5 });
		    break;				
		case 113:  // Accelerometer
		case 134:  // Gyrometer
            axes = ["_X", "_Y", "_Z"];
            var div = s_type === 113 ? 1000 : 100;
            for (var j = 0; j < 3; j++) {
                index = i + (j*2);
                var axis = (((payload[index] & 0xFF) << 8) | (payload[index+1] & 0xFF)); // Get Value
                axis = payload[index] & (1 << 7) ? axis = 0xFFFF0000 | axis : axis; // Get Sign as this is Signed INT
    		    decoded.push({field: sensor_types[s_type].name+s_ch+axes[j],value: axis/div});                
            }
		    break;				
		case 115:  // Barometer
		    decoded.push({field: sensor_types[s_type].name+s_ch, value: ((payload[i]<<8 | payload[i+1])) * 0.1});
		    break;				
		case 136:
			var lat = (payload[6]<<24>>8 | payload[7]<<8 | payload[8])/10000;
			var long = (payload[9]<<24>>8 | payload[10]<<8 | payload[11])/10000;
			var altitude = ((payload[12]<<16 | payload[13]<<8 | payload[14])/100);
			break;
		}        
        i += s_size;
    }
    
    return decoded;
}
