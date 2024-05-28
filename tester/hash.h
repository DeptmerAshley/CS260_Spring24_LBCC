#include <iostream>
#include <sstream>
#include <string>
#include <functional> // for std::hash

using std::string;
using std::stringstream;

class HashTable {
public:
    HashTable(int initialCapacity);
    int hash(const string& value);
    void insert(const string& value);
    bool contains(const string& value);
    bool remove(const string& value);
    string toString();

private:
    int capacity;
    int size;
    string* storage;

    int findSlot(const string& value);
};

