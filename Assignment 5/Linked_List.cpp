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
    Node* current = this->head;
    if (this->head == NULL) {
        cout << "\nError: No list to print\n";
    }
    else {
        cout << "[";
        for (int i = 0; i < this->length; i++) {
            cout << current->value << ", ";
            current = current->next_node;
        }
        cout << "]" << endl;
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
    this->head = NULL;
}

void Linked_List::push_front(int value) {
    Node* beginning = new Node;
    beginning->next_node = this->head; 
    beginning->value = value;
    this->head = beginning;
    this->length += 1;
}

void Linked_List::insert(int value) {
    Node* inserting = new Node;
    inserting->value = value;

    if (this->head == NULL) {
        this->head = inserting;
        this->length += 1;
    } 
    else if(inserting->value <= this->head->value) {
        push_front(value);
    }
    else if (this->length == 1 && inserting->value >= this->head->value) {
        this->head->next_node = inserting;
        this->length += 1;
    }
    else {
        Node* hold = this->head;
        do {
            if (inserting->value < hold->next_node->value) {   
                break;
            }
            hold = hold->next_node;
            if (hold->next_node == NULL) {
                break;
            }
        } while (inserting->value > hold->next_node->value);
        inserting->next_node = hold->next_node;
        hold->next_node = inserting;
        this->length += 1;
    }
}

void Linked_List::search(int search_value) {
    Node* hold = this->head;
    bool found = false;
    for (int i = 0; i < this->length; i++) {
        if (search_value == hold->value) {
            cout << "Found: " << hold->value <<endl;
            found = true;
            break;
        }
        hold = hold->next_node;
    }
    if (found != true) {
        cout << "Value not found in list\n";
    }
}

void Linked_List::remove(int remove_value) {
    Node* removing = new Node;
    Node* hold = this->head;
    bool found = false;
    for (int i = 1; i < this->length; i++) {
        if (remove_value == hold->next_node->value) {
            cout << "Removed: " << hold->next_node->value <<endl;
            found = true;
            removing = hold->next_node;
            hold->next_node = removing->next_node;
            delete removing;
            this->length -= 1;
            break;
        }
        hold = hold->next_node;
    }
    if (found != true) {
        cout << "Value not found in list\n";
    }

}


// void Linked_List::enqueue(int value) {
//     Node* ending = new Node;
//     ending->value = value;
//     ending->next_node = NULL;
//     Node* hold = head;
//     do { 
//         hold = hold->next_node;
//     } while(hold->next_node != NULL);
//     hold->next_node = ending;
//     this->length += 1;
// }




// int Linked_List::dequeue(bool remove) {
//     Node* hold = this->head;
//     int returnValue = hold->value;
//     if (remove == true) {
//         this->head = head->next_node;
//         delete hold;
//         this->length -= 1;
//         return returnValue;
//     }
//     else {
//         return returnValue;
//     }
// }

// int Linked_List::get(int position) {
//     Node* hold = this->head;
//     int count = 0;

//     if (position > this->length) {
//         cout << "\nERROR: Entered value larger than the size of the lost.\n";
//     } 
//     else if(position == this->length) {
//         do {
//             count += 1;
//             hold = hold->next_node;
//         } while (hold->next_node != NULL);
//         return hold->value;
//     } 
//     else if(position == 1) {
//         dequeue(false);
//     }
//     else {
//         do {
//             count += 1;
//             hold = hold->next_node;
//         } while (count != (position - 1));
//         return hold->value;
//     }
//     return hold->value;
// }