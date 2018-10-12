CC=gcc
CFLAG= -O
sha256_objects= sha256/types.o sha256/hash.o sha256/constants.o sha256/sha256.o
sha1_objects= sha1/types.o sha1/hash.o sha1/constants.o sha1/sha1.o

all: $(sha256_objects) $(sha1_objects)

%.o: %.c
	$(CC) $< $(CFLAG) -c -o $@

test/test_sha256: $(sha256_objects) test/test_sha256.c
	$(CC) test/test_sha256.c $(CFLAG) -I. $(sha256_objects) -o test/test_sha256

test/test_sha1: $(sha1_objects) test/test_sha1.c
	$(CC) test/test_sha1.c $(CFLAG) -I. $(sha1_objects) -o test/test_sha1

clean:
	-rm $(sha256_objects)
	-rm $(sha1_objects)
	-rm test/test_sha256
	-rm test/test_sha1

