#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {
private:
	int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list

public:

    Linked_List(); //default constructor

	int get_length(); //accessor
	
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
	void insert(int); // insert a new value in the list at the specified index 
	void push_front(int); // insert a new value at the front of the list 
	void search(int);
	void remove(int); //remove a value return it
	// void enqueue(int); // insert a new value at the back of the list 
	// int dequeue(bool remove); //remove value at the front of the list and return its value
	// int get(int); //finds a positions and returns its value without removing it
};

#endif