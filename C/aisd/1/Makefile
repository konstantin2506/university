CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror 

all: main.o input.o matrix.o
	$(CC) $(CFLAGS) main.o input.o matrix.o -o a 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
matrix.o: matrix.c
	$(CC) $(CFLAGS) -c matrix.c
input.o: input.c
	$(CC) $(CFLAGS) -c input.c
