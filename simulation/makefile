# Definitions for constants
CC = gcc
CFLAGS = -I. -g

# This will create your final output using .o compiled files
main.out: main.o simulate.o
	$(CC) $(CFLAGS) -o main.out main.o 

# This will compile main.c with its dependency
main.o: main.c globals.h simulate.h
	$(CC) $(CFLAGS) -c main.c 

simulate.o: simulate.c simulate.h globals.h
	$(CC) $(CFLAGS) -c simulate.c

# This will clean or remove compiled files so you can start fresh
.PHONY: clean
clean:
	rm -f *.o *.out
