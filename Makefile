CC=gcc
CFLAGS=-I.

.PHONY: clean all

# The default target that gets executed when you run `make` without arguments
all: main.o

# Rule to create the object file from the source code
main.o: main.c
	$(CC) -c main.c $(CFLAGS)

# Clean up the generated object file
clean:
	rm -f *.o
