#ifndef SHA256_CONSTANTS_H_
#define SHA256_CONSTANTS_H_

#include <inttypes.h>

#define SHA256_BLOCK_LEN 64
#define SHA256_HASH_LEN 32

#ifdef __AVR__
#include <avr/pgmspace.h>
#endif

const uint32_t sha256_init_state[SHA256_HASH_LEN / 4]
#ifdef __AVR__
						PROGMEM
#endif
							;
const uint32_t sha256_constants[64]
#ifdef __AVR__
						PROGMEM
#endif
							;

#ifdef __AVR__
#define sha256_k(i) pgm_read_dword(sha256_constants + i)
#else
#define sha256_k(i) sha256_constants[i]
#endif


#ifdef SHA256_ENABLE_HMAC
#define SHA256_HMAC_IPAD 0x36
#define SHA256_HMAC_OPAD 0x5c
#endif

#endif
