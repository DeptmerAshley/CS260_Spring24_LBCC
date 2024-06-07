CC=gcc
CXX=g++
RM=rm -f

SRCS=graph.cpp main.cpp 
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: graph.o
	$(CXX) main.cpp -o main graph.o 

graph.o: graph.h
	$(CXX) -c graph.cpp

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) main 