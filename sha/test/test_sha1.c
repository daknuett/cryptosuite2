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

#include <sha1/sha1.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

void print_hash(uint8_t * result)
{
	int i;
	for(i = 0; i < SHA1_HASH_LEN; i++)
	{
		printf("%2x", result[i]);
	}
	printf("\n");
}

int main(void)
{
	sha1_hasher_t hasher = sha1_hasher_new();
	uint8_t * result;
	int i;




	sha1_hasher_init(hasher);
	sha1_hasher_write(hasher, "abc", 3);
	result = sha1_hasher_gethash(hasher);
	printf("EXPECT: a9993e364706816aba3e25717850c26c9cd0d89d\n");
	printf("GOT:    ");
	print_hash(result);



	sha1_hasher_init(hasher);
	result = sha1_hasher_gethash(hasher);
	printf("EXPECT: da39a3ee5e6b4b0d3255bfef95601890afd80709\n");
	printf("GOT:    ");
	print_hash(result);



	sha1_hasher_del(hasher);
	return 0;
}

