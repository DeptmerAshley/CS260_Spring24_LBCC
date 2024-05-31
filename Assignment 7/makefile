CC=gcc
CXX=g++
RM=rm -f

SRCS=hash.cpp main.cpp 
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: hash.o
	$(CXX) main.cpp -o main hash.o 

hash.o: hash.h hash.h
	$(CXX) -c hash.cpp

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) main 