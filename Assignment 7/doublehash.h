#ifndef DOUBLEHASH_H
#define DOUBELHASH_H

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <vector>

using namespace std;

class DoubleHashTable {
public:
    DoubleHashTable(int initialCapacity);
    int hash1(const string& value);
    int hash2(const string& value);
    void insert(const string& value);
    bool contains(const string& value);
    bool remove(const string& value);
    string toString();

private:
    int capacity;
    int size;
    vector<string> storage;

    int findSlot(const string& value);
};

#endif