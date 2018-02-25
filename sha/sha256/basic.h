#ifndef SHA256_BASIC_H_
#define SHA256_BASIC_H_

#include <inttypes.h>

#define sha_ch(x, y, z)      (((x) & ((y) ^ (z))) ^ (z))
#define sha_maj(x, y, z)     (((x) & ((y) | (z))) | ((y) & (z)))
#define sha_parity(x, y, z)  ((x) ^ (y) ^ (z))

#define sha256_shr(bits,word)      ((word) >> (bits))
#define sha256_rotl(bits,word)     (((word) << (bits)) | ((word) >> (32 - (bits))))
#define sha256_rotr(bits,word)     (((word) >> (bits)) | ((word) << (32 - (bits))))

#define sha256_SIGMA0(word)   (sha256_rotr(2, word) ^ sha256_rotr(13, word) ^ sha256_rotr(22, word))
#define sha256_SIGMA1(word)   (sha256_rotr(6, word) ^ sha256_rotr(11, word) ^ sha256_rotr(25, word))
#define sha256_sigma0(word)   (sha256_rotr(7, word) ^ sha256_rotr(18, word) ^ sha256_shr(3, word))
#define sha256_sigma1(word)   (sha256_rotr(17, word) ^ sha256_rotr(19, word) ^ sha256_shr(10, word))

#endif
