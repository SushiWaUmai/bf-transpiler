CFLAGS=-Wall -Wextra -pedantic -std=c11

all: ./src/main.c
	    $(CC) $(CFLAGS) "./src/main.c" -lm

