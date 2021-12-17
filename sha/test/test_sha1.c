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

#include "../sha1/sha1.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void print_hash(uint8_t * result)
{
	int i;
	for(i = 0; i < SHA1_HASH_LEN; i++)
	{
		printf("%02x", result[i]);
	}
	printf("\n");
}

int main(void)
{
	sha1_hasher_t hasher = sha1_hasher_new();
	uint8_t * result;
	int i;



    uint8_t expect_test1[SHA1_HASH_LEN] = {0xa9, 0x99, 0x3e, 0x36, 0x47, 0x06, 0x81, 0x6a, 0xba,
                                            0x3e, 0x25, 0x71, 0x78, 0x50, 0xc2, 0x6c, 0x9c, 0xd0,
                                            0xd8, 0x9d} ;

	sha1_hasher_init(hasher);
	sha1_hasher_write(hasher, "abc", 3);
	result = sha1_hasher_gethash(hasher);
	printf("EXPECT: a9993e364706816aba3e25717850c26c9cd0d89d\n");
	printf("GOT:    ");
	print_hash(result);

    for(i=0; i < SHA1_HASH_LEN; i++)
    {
        assert(result[i] == expect_test1[i]);
    }



    uint8_t expect_test2[SHA1_HASH_LEN] = {0xda, 0x39, 0xa3, 0xee, 0x5e, 0x6b, 0x4b, 0x0d,
                                            0x32, 0x55, 0xbf, 0xef, 0x95, 0x60, 0x18, 0x90,
                                            0xaf, 0xd8, 0x07, 0x09};
	sha1_hasher_init(hasher);
	result = sha1_hasher_gethash(hasher);
	printf("EXPECT: da39a3ee5e6b4b0d3255bfef95601890afd80709\n");
	printf("GOT:    ");
	print_hash(result);

    for(i=0; i < SHA1_HASH_LEN; i++)
    {
        assert(result[i] == expect_test2[i]);
    }


	sha1_hasher_del(hasher);
	return 0;
}

