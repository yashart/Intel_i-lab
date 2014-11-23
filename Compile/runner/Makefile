CC=g++

CFLAGS=-c

all: runner

runner: main.o runner.o errors.o fileworking.o My_stack.o My_calk.o commands.o
	$(CC) main.o runner.o errors.o fileworking.o My_stack.o My_calk.o commands.o -o runner

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

runner.o: runner.cpp
	$(CC) $(CFLAGS) runner.cpp

errors.o: ../errors.cpp
	$(CC) $(CFLAGS) ../errors.cpp

fileworking.o: ../fileworking.cpp
	$(CC) $(CFLAGS) ../fileworking.cpp

My_stack.o: ../stack/My_stack.cpp
	$(CC) $(CFLAGS) ../stack/My_stack.cpp

My_calk.o: ../stack/My_calk.cpp
	$(CC) $(CFLAGS) ../stack/My_calk.cpp

commands.o: ../commands.cpp
	$(CC) $(CFLAGS) ../commands.cpp

clean:
	rm -rf *.o runner
