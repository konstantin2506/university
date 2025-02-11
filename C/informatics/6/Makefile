CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99

all: main.o list.o
	$(CC) $(CFLAGS) main.o list.o -o a
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
list.o: list.c
	$(CC) $(CFLAGS) -c list.c
