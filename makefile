CC=gcc
CFLAGS=-Iheaders

.PHONY: all clean

# The default target is 'all', which will build 'student_manager'
all: student_manager

# This rule builds the 'student_manager' executable from 'main.o'
student_manager: main.o
	$(CC) -o student_manager main.o $(CFLAGS)

# This rule builds 'main.o' from 'main.c' and ensures the necessary headers are included
main.o: main.c
	$(CC) -c main.c $(CFLAGS)

# This rule cleans up all object files and the executable
clean:
	rm -f *.o student_manager
