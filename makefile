CC = gcc
CFLAGS = -Wall -g

all: programa

programa: main.o
	$(CC) $(CFLAGS) -o programa main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o programa

