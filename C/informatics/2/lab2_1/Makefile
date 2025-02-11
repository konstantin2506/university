CC = clang 
CFLAGS = -Wall -Wextra -Wpedantic -Werror


all: main.o input.o mylog.o error.o
	$(CC) $(CFLAGS)  main.o input.o mylog.o error.o -o lab2_1 -lm
	
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
input.o: input.c
	$(CC) $(CFLAGS) -c input.c
mylog.o: mylog.c
	$(CC) $(CFLAGS) -c mylog.c
error.o: error.c
	$(CC) $(CFLAGS) -c error.c


