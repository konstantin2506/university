CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror 

all: main.o input.o arrays.o task2.o
	$(CC) $(CFLAGS)  main.o input.o arrays.o task2.o -o a
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
input.o: input.c
	$(CC) $(CFLAGS) -c input.c
arrays.o: arrays.c
	$(CC) $(CFLAGS) -c arrays.c
task2.o: task2.c
	$(CC) $(CFLAGS) -c task2.c
