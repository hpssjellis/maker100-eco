function Decoder(payload, port) {
    if(port === 2) {
        return [
            {
                field: "X",
                value: payload[0] / 100
            }
        ];
    }
}
