CC=gcc
CXX=g++
RM=rm -f

SRCS=hash.cpp main.cpp 
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: hash.o doublehash.o
	$(CXX) main.cpp -o main hash.o doublehash.o

hash.o: hash.h
	$(CXX) -c hash.cpp

doublehash.o: doublehash.o
	$(CXX) -c doublehash.cpp

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) main 