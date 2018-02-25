#ifndef SHA256_SHA256_H_
#define SHA256_SHA256_H_

#include "default.h"
#include "types.h"
#include "hash.h"
#include <stddef.h>
#include <unistd.h>

#ifdef __AVR__
#define ssize_t long int
#endif

ssize_t sha256_hasher_write(sha256_hasher_t hasher, const void * buf, size_t count); 

#endif  
