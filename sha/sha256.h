#ifndef Sha256_h
#define Sha256_h

#include <inttypes.h>
//#include "Print.h"
#include "sha256/sha256.h"

#ifndef SHA256_DISABLE_WRAPPER
class Sha256Wrapper //: public Print
{
	public:
		void init(void);
		uint8_t * result(void);
#ifdef SHA256_ENABLE_HMAC
		void initHmac(const uint8_t * secret, unsigned int secretLength);
		uint8_t * resultHmac(void);
#endif
		virtual size_t write(uint8_t);
		//using Print::write;
	private:
		struct sha256_hasher_s _hasher;

};

extern Sha256Wrapper Sha256;
#endif

#endif
