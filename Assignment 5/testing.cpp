#include "Linked_List.h"
#include <iostream>
using namespace std;

int main() {
    Linked_List tester;

    tester.insert(1);
    tester.print();
    tester.insert(5);
    tester.print();
    tester.insert(3);
    tester.print();
    tester.insert(4);
    tester.print();
    tester.insert(10);
    tester.print();
    tester.insert(6);
    tester.print();
    tester.insert(2);
    tester.print();
    tester.insert(7);
    tester.print();
    tester.insert(9);
    tester.print();
    tester.insert(8);
    tester.print();

    tester.search(5);
    tester.search(11);

    tester.remove(5);
    tester.print();
    tester.remove(11);

    tester.clear();
    tester.print();
}