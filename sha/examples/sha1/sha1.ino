#include "sha1.h"

// read data from the serial interface and print the
// hash to the serial

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
        Sha1.init();

        Sha1.print(Serial.read());

        uint8_t * result = Sha1.result();

        Serial.print("Hash:\n");

        for (int i = 0; i < 20; i++) {
                Serial.print("0123456789abcdef"[result[i] >> 4]);
                Serial.print("0123456789abcdef"[result[i] & 0xf]);
        }
        Serial.print("\n");
}
