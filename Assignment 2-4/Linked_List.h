#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {
private:
	int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list

public:

    Linked_List(); //default constructor

	int get_length();
	
   
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
	void push_front(int); // insert a new value at the front of the list 
	void enqueue(int); // insert a new value at the back of the list 
	int dequeue(bool remove); //remove value at the front of the list and return its value
	void insert(int val, int index); // insert a new value in the list at the specified index 
	int remove(int); //remove a value at a selected position and return it
	int get(int); //finds a positions and returns its value without removing it
};

#endif