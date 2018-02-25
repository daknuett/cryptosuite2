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
