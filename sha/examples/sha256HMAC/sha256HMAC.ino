#include "sha256.h"

const char hexMap[] PROGMEM = "0123456789abcdef";
void setup(void)
{
        Serial.begin(115200);

        // this is actually the RFC4231 4.3 test

        Sha256.initHmac((uint8_t * ) "Jefe", 4);
        Sha256.print("what do ya want for nothing?");
        uint8_t * result = Sha256.resultHmac();

        Serial.println("Expect: 5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843");
        Serial.print(  "Got   : ");
        for (int i = 0; i < 32; i++) {
                Serial.print((char)pgm_read_byte(hexMap + (result[i] >> 4)));
                Serial.print((char)pgm_read_byte(hexMap + (result[i] & 0xf)));
        }
        Serial.print("\n");
}


void loop(void)
{}
