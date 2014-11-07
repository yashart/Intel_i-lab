CC=g++

CFLAGS=-c -Wall

all: disasm

disasm: main.o disasm.o errors.o fileworking.o
	$(CC) main.o disasm.o errors.o fileworking.o -o asm

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

asm.o: disasm.cpp
	$(CC) $(CFLAGS) disasm.cpp

errors.o: ../errors.cpp
	$(CC) $(CFLAGS) ../errors.cpp

fileworking.o: ../fileworking.cpp
	$(CC) $(CFLAGS) ../fileworking.cpp

clean:
	rm -rf *.o asm
