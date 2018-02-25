#ifndef SHA256_HASH_H_
#define SHA256_HASH_H_


#include "default.h"
#include "constants.h"
#include "types.h"
#include "basic.h"

void sha256_hash_block(sha256_hasher_t hasher);

void sha256_hasher_add_byte(sha256_hasher_t hasher, uint8_t byte);

/**
 * NOTE: once the block has been pad'ed the hasher will
 * produce nonsense data. Therefore putc will return EOF
 * once the hasher has been pad'ed (this happens, when 
 * sha256_hasher_gethash or sha256_hasher_gethmac are invoced).
 * */
int sha256_hasher_putc(sha256_hasher_t hasher, uint8_t byte);

void sha256_hasher_pad(sha256_hasher_t hasher);

/**
 * NOTE: this will NOT return a copy of the data but
 * a REFERENCE! One MUST NOT free the result.
 *
 * Also this modifies the state of the hasher. The
 * hasher has an internal lock ensuring that writing
 * to the hasher fails after this operation.
 * */
uint8_t * sha256_hasher_gethash(sha256_hasher_t hasher);

#ifdef SHA256_ENABLE_HMAC
void sha256_hasher_init_hmac(sha256_hasher_t hasher, const uint8_t * key, size_t key_len);
uint8_t * sha256_hasher_gethmac(sha256_hasher_t hasher);
#endif

#endif
