#include "sha1.h"

void setup(void)
{
        Serial.begin(9600);

        // this is actually the RFC4231 4.3 test

        Sha1.initHmac((uint8_t * ) "Jefe", 4);
        Sha1.print("what do ya want for nothing?");
        uint8_t * result = Sha1.resultHmac();

        Serial.println("Expect: effcdf6ae5eb2fa2d27416d5f184df9c259a7c79");
        Serial.print(  "Got   : ");
        for (int i = 0; i < 20; i++) {
                Serial.print("0123456789abcdef"[result[i] >> 4]);
                Serial.print("0123456789abcdef"[result[i] & 0xf]);
        }
        Serial.print("\n");
}


void loop(void)
{}
