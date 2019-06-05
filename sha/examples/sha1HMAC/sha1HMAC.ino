#include "sha1.h"

void setup(void)
{
        Serial.begin(9600);

        // this is actually the RFC4231 4.3 test

        Sha1.initHmac((uint8_t * ) "Jefe", 4);
        Sha1.print("what do ya want for nothing?");
        uint8_t * result = Sha1.resultHmac();

        Serial.println("Expect: b0344c61d8db38535ca8afceaf0bf12b881dc200c9833da726e9376c2e32cff7");
        Serial.print(  "Got   : ");
        for (int i = 0; i < 10; i++) {
                Serial.print("0123456789abcdef"[result[i] >> 4]);
                Serial.print("0123456789abcdef"[result[i] & 0xf]);
        }
        Serial.print("\n");
}


void loop(void)
{}
