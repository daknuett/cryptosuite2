#include "types.h"
#include <stdlib.h>
#include <string.h>
#include "constants.h"

sha256_hasher_t sha256_hasher_new(void)
{
	sha256_hasher_t hasher = malloc(sizeof(struct sha256_hasher_s));
	if(!hasher)
	{
		return NULL;
	}
	sha256_hasher_init(hasher);
	return hasher;
}

void sha256_hasher_init(sha256_hasher_t hasher)
{
#ifdef __AVR__
	int i;
	for(i = 0; i < SHA256_HASH_LEN / 4; i++)
	{
		hasher->state.words[i] = pgm_read_dword(sha256_init_state + i);
	}
#else
	memcpy(hasher->state.words, sha256_init_state, 32);
#endif
	hasher->block_offset = 0;
	hasher->total_bytes = 0;
	hasher->_lock = 0;

}


void sha256_hasher_del(sha256_hasher_t hasher)
{
	free(hasher);
}

