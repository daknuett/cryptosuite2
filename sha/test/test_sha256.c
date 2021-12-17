// This file is part of cryptosuite2.                                    //
//                                                                       //
// cryptosuite2 is free software: you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation, either version 3 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// cryptosuite2 is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details.                          //
//                                                                       //
// You should have received a copy of the GNU General Public License     //
// along with cryptosuite2.  If not, see <http://www.gnu.org/licenses/>. //
//                                                                       //

#include "../sha256/sha256.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void print_hash(uint8_t * result)
{
	int i;
	for(i = 0; i < SHA256_HASH_LEN; i++)
	{
		printf("%02x", result[i]);
	}
	printf("\n");
}

int main(void)
{
	sha256_hasher_t hasher = sha256_hasher_new();
	uint8_t * result;
	int i;



    uint8_t expected_test1[SHA256_HASH_LEN] = {0xba, 0x78, 0x16, 0xbf, 0x8f, 0x01, 0xcf, 0xea,
                                                0x41, 0x41, 0x40, 0xde, 0x5d, 0xae, 0x22, 0x23,
                                                0xb0, 0x03, 0x61, 0xa3, 0x96, 0x17, 0x7a, 0x9c,
                                                0xb4, 0x10, 0xff, 0x61, 0xf2, 0x00, 0x15, 0xad};

	sha256_hasher_init(hasher);
	sha256_hasher_write(hasher, "abc", 3);
	result = sha256_hasher_gethash(hasher);
	printf("EXPECT: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad\n");
	printf("GOT:    ");
	print_hash(result);

    for(i = 0; i < SHA256_HASH_LEN; i++)
    {
        assert(result[i] == expected_test1[i]);
    }


    uint8_t expected_test2[SHA256_HASH_LEN] = {0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14,
                                                0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24,
                                                0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
                                                0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55};

	sha256_hasher_init(hasher);
	result = sha256_hasher_gethash(hasher);
	printf("EXPECT: e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\n");
	printf("GOT:    ");
	print_hash(result);

    for(i = 0; i < SHA256_HASH_LEN; i++)
    {
        assert(result[i] == expected_test2[i]);
    }


	sha256_hasher_del(hasher);
	return 0;
}
