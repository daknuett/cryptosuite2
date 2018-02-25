#include "sha256.h"

ssize_t sha256_hasher_write(sha256_hasher_t hasher, const void * buf, size_t count)
{
	size_t written = 0;
	int chk_result;
	char c;
	while(written < count)
	{
		c = ((char *) buf)[written];
		chk_result = sha256_hasher_putc(hasher, c);
		if(chk_result != c)
		{
			return -1;
		}
		written++;
	}
	return written;
}
