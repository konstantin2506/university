CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -O2

all: main.o options.o arrays.o string.o sorts.o
	$(CC) $(CFLAGS) main.o options.o arrays.o string.o sorts.o -o a
test: test.o arrays.o sorts.o
	$(CC) $(CFLAGS) test.o arrays.o sorts.o -o test
test1: test1.o arrays.o sorts.o
	$(CC) $(CFLAGS) test1.o arrays.o sorts.o -o test1
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
options.o: options.c
	$(CC) $(CFLAGS) -c options.c
arrays.o: arrays.c
	$(CC) $(CFLAGS) -c arrays.c
string.o: string.c
	$(CC) $(CFLAGS) -c string.c
sorts.o: sorts.c
	$(CC) $(CFLAGS) -c sorts.c
test.o: test.c
	$(CC) $(CFLAGS) -c test.c
test1.o: test1.c
	$(CC) $(CFLAGS) -c test1.c
