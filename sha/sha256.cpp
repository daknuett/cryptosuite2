#include "sha256.h"

#ifndef SHA256_DISABLE_WRAPPER
void Sha256Wrapper::init(void)
{
	sha256_hasher_init(&_hasher);
}

#ifdef SHA256_ENABLE_HMAC
void Sha256Wrapper::initHmac(const uint8_t * secret, unsigned int secretLength)
{
	sha256_hasher_init_hmac(&_hasher, secret, secretLength);
}

uint8_t * Sha256Wrapper::resultHmac(void)
{
	return sha256_hasher_gethmac(&_hasher);
}
#endif


size_t Sha256Wrapper::write(uint8_t byte)
{
	if(sha256_hasher_putc(&_hasher, byte) == byte)
	{
		return 1;
	}
	return 0;
}

uint8_t * Sha256Wrapper::result(void)
{
	return sha256_hasher_gethash(&_hasher);
}

Sha256Wrapper Sha256;

#endif
