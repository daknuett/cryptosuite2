CC=gcc
clflag= -g -c

lib_objects=../sha1/constants.o \
			../sha1/hash.o \
			../sha1/sha1.o \
			../sha1/types.o \
			../sha256/constants.o \
			../sha256/hash.o \
			../sha256/sha256.o \
			../sha256/types.o 

test_objects= test_sha1.o test_sha256.o
tests=test_sha1 test_sha256

all: clean $(tests)
	echo "############# ALL TESTS PASSED ##############"

%.o:%.c
	$(CC) $(clflag) -o $@ $<

test_sha1: $(test_objects) $(lib_objects)
	$(CC) $(cflag) $(lib_objects) test_sha1.o -o test_sha1
	./test_sha1
	rm test_sha1

test_sha256: $(test_objects) $(lib_objects)
	$(CC) $(cflag) $(lib_objects) test_sha256.o -o test_sha256
	./test_sha256
	rm test_sha256

clean:
	-rm $(lib_objects)
	-rm $(test_objects)
