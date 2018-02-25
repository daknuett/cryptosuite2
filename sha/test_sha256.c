#include <sha256/sha256.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

void print_hash(uint8_t * result)
{
	int i;
	for(i = 0; i < SHA256_HASH_LEN; i++)
	{
		printf("%2x", result[i]);
	}
	printf("\n");
}

int main(void)
{
	sha256_hasher_t hasher = sha256_hasher_new();
	uint8_t * result;
	int i;




	sha256_hasher_init(hasher);
	sha256_hasher_write(hasher, "abc", 3);
	result = sha256_hasher_gethash(hasher);
	printf("EXPECT: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad\n");
	printf("GOT:    ");
	print_hash(result);



	sha256_hasher_init(hasher);
	result = sha256_hasher_gethash(hasher);
	printf("EXPECT: e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\n");
	printf("GOT:    ");
	print_hash(result);



	sha256_hasher_del(hasher);
	return 0;
}
