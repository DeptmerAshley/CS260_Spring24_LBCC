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
    cout << "Length: " << tester.get_length() << "\n";

    cout << "\nAdding values using enqueue: ";
    tester.enqueue(2);
    tester.enqueue(3);
    tester.enqueue(4);
    tester.enqueue(5);
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";


    cout << "\nUse of a peek(dequeue with remove set to false): " << tester.dequeue(false) << "\n";
    cout << "Proof:";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";

    cout << "\nUse of dequeue: ";
    tester.dequeue(true);
    tester.print();
    cout << "Length: " << tester.get_length() << "\n\n";

    tester.print();
    cout << "Use of Insert (Position: 6): ";
    tester.insert(10, 6);
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";
    cout << "Use of Insert from end of list: ";
    tester.insert(10, 9);
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";
    cout << "Use of Insert at top of list: ";
    tester.insert(10, 1);
    tester.print();
    cout << "Length: " << tester.get_length() << "\n\n";

    tester.print();
    cout << "Use of Remove (Position: 7): " << tester.remove(7) << "\n";
    cout << "Proof: ";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";
    cout << "Use of Remove from end of list: " << tester.remove(10) << "\n";
    cout << "Proof: ";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";
    cout << "Use of Remove from top of list: " << tester.remove(1) << "\n";
    cout << "Proof: ";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";

    cout << "\nUse of get function (Position: 5): " << tester.get(5) << "\n";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";
    cout << "\nUse of get function (end of list): " << tester.get(8) << "\n";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";
    cout << "\nUse of get function (top of list): " << tester.get(1) << "\n";
    tester.print();
    cout << "Length: " << tester.get_length() << "\n";

}