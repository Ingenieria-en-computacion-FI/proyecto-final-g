CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Iinclude

SRC=$(wildcard src/**/*.c src/*.c)
SRC_TEST=$(filter-out src/main.c,$(SRC))
TESTS=$(wildcard tests/*.c)

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o bin/main

run:
	./bin/main

test:
	mkdir -p bin
	$(CC) $(CFLAGS) $(TESTS) $(SRC_TEST) -o bin/tests
	./bin/tests

clean:
	rm -rf bin/*