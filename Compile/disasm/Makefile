CC=g++

CFLAGS=-c

all: disasm

disasm: main.o disasm.o errors.o fileworking.o commands.o
	$(CC) main.o disasm.o errors.o fileworking.o commands.o -o disasm

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

asm.o: disasm.cpp
	$(CC) $(CFLAGS) disasm.cpp

errors.o: ../errors.cpp
	$(CC) $(CFLAGS) ../errors.cpp

fileworking.o: ../fileworking.cpp
	$(CC) $(CFLAGS) ../fileworking.cpp

commands.o: ../commands.cpp
	$(CC) $(CFLAGS) ../commands.cpp

clean:
	rm -rf *.o disasm
