CC=g++

CFLAGS=-c -Wall

all: list

list: main.o errors.o list.o
	$(CC) main.o errors.o list.o -o list

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

errors.o: errors.cpp
	$(CC) $(CFLAGS) errors.cpp

list.o: list.cpp
	$(CC) $(CFLAGS) list.cpp

clean:
	rm -rf *.o list
