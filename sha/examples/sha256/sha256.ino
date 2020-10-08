#include "sha256.h"

// read data from the serial interface and print the
// hash to the serial

const char hexMap[] PROGMEM = "0123456789abcdef";
void setup(void)
{
        Serial.begin(9600);
}

void loop(void)
{
        if(!Serial.available())
        {
                return;
        }
        Sha256.init();

        Sha256.print(Serial.read());

        uint8_t * result = Sha256.result();

        Serial.print("Hash:\n");

        for (int i = 0; i < 32; i++) {
                Serial.print((char)pgm_read_byte(hexMap + (result[i] >> 4)));
                Serial.print((char)pgm_read_byte(hexMap + (result[i] & 0xf)));
        }
        Serial.print("\n");
}
