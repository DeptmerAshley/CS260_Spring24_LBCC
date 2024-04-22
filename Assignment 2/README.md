1. Ok I won't

2. 
    1. For a queue we will most likely need functions to add, delete, and readjust the size when objects are added or deleted.
    2. We will need to know the size of the queue and maybe how many objects have been added/deleted.

3. 
    1. We will need a loop of some sort like a do while or a for loop. We will also need to be able to change around our lins and make sure each node points to the correct next node.
    2. We will need to know the size, every value for each node, and what node each node points at. 

4. Ok!

Update log for week 3 assignment:

void Linked_List::enqueue(int value) {
    Node* ending = new Node;
    ending->value = value;
    ending->next_node = NULL;
    Node* find_last = head;
    do { 
        find_last = find_last->next_node;
    } while(find_last->next_node != NULL);
    find_last->next_node = ending;
    this->length += 1;
}

int Linked_List::dequeue(bool remove) {
    Node* hold = this->head;
    int returnValue = hold->value;
    if (remove == true) {
        this->head = head->next_node;
        delete hold;
        return returnValue;
    }
    else {
        return returnValue;
    }
}