CC=g++ -g
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): bag.o marble.o prog.o
	$(CC) bag.o marble.o -o $(EXE_FILE)

bag.o: bag.o bag.cpp
	$(CC) -c bag.cpp

marble.o: marble.h marble.cpp
	$(CC) -c marble.cpp

clean:
	rm -f *.o $(EXE_FILE)