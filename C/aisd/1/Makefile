CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g

all: main.o input.o matrix.o list.o arrays.o hashtable.o
	$(CC) $(CFLAGS) main.o input.o matrix.o arrays.o list.o hashtable.o -o a 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c
input.o: input.c
	$(CC) $(CFLAGS) -c input.c
list.o: list.c
	$(CC) $(CFLAGS) -c list.c
arrays.o: arrays.c
	$(CC) $(CFLAGS) -c arrays.c
hashtable.o: hashtable.c
	$(CC) $(CFLAGS) -c hashtable.c
