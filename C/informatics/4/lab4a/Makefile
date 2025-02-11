CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -O2 

all: main.o mstring.o
	$(CC) $(CFLAGS) main.o mstring.o -o a -lreadline
main.o: main.c
	$(CC) $(CFLAGS) -c main.c 
mstring.o: mstring.c
	$(CC) $(CFLAGS) -c mstring.c
