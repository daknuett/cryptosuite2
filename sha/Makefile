
CC=gcc
CFLAG= -O
sha256_objects= sha256/types.o sha256/hash.o sha256/constants.o sha256/sha256.o

all: $(sha256_objects)

%.o: %.c
	$(CC) $< $(CFLAG) -c -o $@

test_sha256: $(sha256_objects) test_sha256.c
	$(CC) test_sha256.c $(CFLAG) -I. $(sha256_objects) -o test_sha256

clean:
	-rm $(sha256_objects)
	-rm test_sha256

