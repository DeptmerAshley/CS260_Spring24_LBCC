CC=gcc
CXX=g++
RM=rm -f

SRCS=binary_search.cpp main.cpp 
OBJS=$(subst .cpp,.o,$(SRCS))

all: main 

main: binary_search.o
	$(CXX) main.cpp -o main binary_search.o 

binary_search.o: binary_search.h node.h
	$(CXX) -c binary_search.cpp

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) main 