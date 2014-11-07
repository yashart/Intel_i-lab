CC=g++

CFLAGS=-c -Wall

all: asm

asm: main.o asm.o errors.o fileworking.o
	$(CC) main.o asm.o errors.o fileworking.o -o asm

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

asm.o: asm.cpp
	$(CC) $(CFLAGS) asm.cpp

errors.o: ../errors.cpp
	$(CC) $(CFLAGS) ../errors.cpp

fileworking.o: ../fileworking.cpp
	$(CC) $(CFLAGS) ../fileworking.cpp

clean:
	rm -rf *.o asm
