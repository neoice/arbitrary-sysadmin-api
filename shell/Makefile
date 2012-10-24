OBJS = shell.o make_cmd.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -Wno-write-strings
LFLAGS = -Wall $(DEBUG)
hw1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hw1
shell.o : shell.cpp
	$(CC) $(CFLAGS) shell.cpp
make_cmd.o : make_cmd.h make_cmd.cpp
	$(CC) $(CFLAGS) make_cmd.cpp

clean:
	\rm *.o hw1
