#ifndef SHA256_TYPES_H_
#define SHA256_TYPES_H_

#include "default.h"
#include <inttypes.h>
#include "constants.h"

typedef union 
{
	uint8_t bytes[SHA256_HASH_LEN];
	uint32_t words[SHA256_HASH_LEN / 4];
	
} sha256_state_t;

typedef union
{
	uint8_t bytes[SHA256_BLOCK_LEN];
	uint32_t words[SHA256_BLOCK_LEN / 4];

} sha256_block_t;

typedef struct sha256_hasher_s
{
	sha256_state_t state;
	sha256_block_t buffer;

	uint8_t block_offset;
	uint64_t total_bytes;
	uint8_t _lock;
#ifdef SHA256_ENABLE_HMAC
	uint8_t hmac_key_buffer[SHA256_BLOCK_LEN];
	uint8_t hmac_inner_hash[SHA256_HASH_LEN];
#endif
} * sha256_hasher_t;

sha256_hasher_t sha256_hasher_new(void);
void sha256_hasher_del(sha256_hasher_t hasher);
void sha256_hasher_init(sha256_hasher_t hasher);


#endif
