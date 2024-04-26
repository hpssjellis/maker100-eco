
more stuff here 


   https://www.thethingsindustries.com/docs/integrations/payload-formatters/javascript/uplink/







function Decoder(bytes, port) {
    var decoded = {};
    var i = 0;

    // Check the port to customize parsing logic if needed
    // Port is typically used to indicate message type
    if (port === 2) {
        while (i < bytes.length) {
            var channel = bytes[i++];
            var type = bytes[i++];
            
            // Digital Output (0x01)
            if (type === 0x01) {
                decoded['digital_output_' + channel] = bytes[i];
                i += 1;
            }
            // Additional data types can be implemented here based on your needs
            // For example, if you send more sensor data, you can handle more types
            // such as temperature, GPS coordinates, etc.
        }
    }

    return decoded;
}
