#ifndef NODE_H
#define NODE_H

class Node {
 public:
    int value;
    //Node* prev_node;
    Node* next_node;

    Node& operator=(const Node& old) {
		this->value = old.value;
		this->next_node = old.next_node;
        this->prev_node = old.prev_node;
	}

};


#endif