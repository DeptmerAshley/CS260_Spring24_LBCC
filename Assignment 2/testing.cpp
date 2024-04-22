#include "Linked_List.h"
#include <iostream>
using namespace std;

int main() {
    Linked_List tester;

    cout << "\nAdding initial values to our linked list: ";
    tester.push_front(1);
    tester.push_front(2);
    tester.push_front(3);
    tester.push_front(4);
    tester.push_front(5);
    tester.print();

    cout << "\nAdding values using enqueue: ";
    tester.enqueue(2);
    tester.enqueue(3);
    tester.enqueue(4);
    tester.enqueue(5);
    tester.print();


    cout << "\nUse of a peek(dequeue with remove set to false): " << tester.dequeue(false) << "\n";
    cout << "Proof:";
    tester.print();

    cout << "\nUse of dequeue: ";
    tester.dequeue(true);
    tester.print();
}