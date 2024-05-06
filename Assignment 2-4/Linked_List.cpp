#include "linked_list.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Linked_List::Linked_List() {
    this->length = 0;
    this->head = NULL;
}

int Linked_List::get_length() {
    return this->length; //returns length
}

void Linked_List::print() {
    Node* current = head;
    if (this->head == NULL) {
        cout << "\nError: No list to print\n";
    }
    else {
        cout << "[";
        while(current->next_node != NULL) { 
            cout << current->value << ", "; 
            current = current->next_node; 
        };
        cout << current->value << "]" << endl;
    }
}

void Linked_List::clear() {
    Node* new_head = this->head;
    Node* current = new_head; 
    Node* temp; 
    while(current != NULL) {
        temp = current->next_node;
        delete current;
        current = temp;
    }
    this->length = 0;
}

void Linked_List::push_front(int value) {
    Node* beginning = new Node;
    beginning->next_node = this->head; 
    beginning->value = value;
    this->head = beginning;
    this->length += 1;
}

void Linked_List::enqueue(int value) {
    Node* ending = new Node;
    ending->value = value;
    ending->next_node = NULL;
    Node* hold = head;
    do { 
        hold = hold->next_node;
    } while(hold->next_node != NULL);
    hold->next_node = ending;
    this->length += 1;
}

void Linked_List::insert(int value, int position) {
    Node* inserting = new Node;
    inserting->value = value;
    Node* hold = this->head;
    int count = 1;

    if (position > this->length) {
        delete inserting;
        cout << "\nERROR: Entered value larger than the size of the lost.\n";
    } 
    else if(position == this->length) {
        enqueue(value);
    } 
    else if(position == 1) {
        push_front(value);
    }
    else {
        do {
            count += 1;
            hold = hold->next_node;
        } while (count != (position - 1));
        inserting->next_node = hold->next_node;
        hold->next_node = inserting;
        this->length += 1;
    }
}

int Linked_List::remove(int position) {
    Node* removing = new Node;
    Node* hold = this->head;
    int count = 1;
    int value;

    if (position > this->length) {
        delete removing;
        cout << "\nERROR: Entered value larger than the size of the lost.\n";
    } 
    else if(position == this->length) {
        do {
            count += 1;
            hold = hold->next_node;
        } while (count != (position - 1));
        removing = hold->next_node;
        hold->next_node = NULL;
        value = removing->value;
        delete removing;
        this->length -= 1;
        return value;
    } 
    else if(position == 1) {
        value = dequeue(true);
        return value;
    }
    else {
        do {
            count += 1;
            hold = hold->next_node;
        } while (count != (position - 1));
        removing = hold->next_node;
        hold->next_node = removing->next_node;
        value = removing->value;
        delete removing;
        this->length -= 1;
        return value;
    }
    return value;
}


int Linked_List::dequeue(bool remove) {
    Node* hold = this->head;
    int returnValue = hold->value;
    if (remove == true) {
        this->head = head->next_node;
        delete hold;
        this->length -= 1;
        return returnValue;
    }
    else {
        return returnValue;
    }
}

int Linked_List::get(int position) {
    Node* hold = this->head;
    int count = 0;

    if (position > this->length) {
        cout << "\nERROR: Entered value larger than the size of the lost.\n";
    } 
    else if(position == this->length) {
        do {
            count += 1;
            hold = hold->next_node;
        } while (hold->next_node != NULL);
        return hold->value;
    } 
    else if(position == 1) {
        dequeue(false);
    }
    else {
        do {
            count += 1;
            hold = hold->next_node;
        } while (count != (position - 1));
        return hold->value;
    }
    return hold->value;
}