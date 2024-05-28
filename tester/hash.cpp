#include "hash.h"

HashTable::HashTable(int initialCapacity) : capacity(initialCapacity), size(0) {
    storage = new string[capacity];
    for (int i = 0; i < capacity; ++i) {
        storage[i] = "";
    }
}

int HashTable::hash(const string& value) {
    std::hash<string> hasher;
    return hasher(value) % capacity;
}

int HashTable::findSlot(const string& value) {
    int index = hash(value);
    while (!storage[index].empty() && storage[index] != value) {
        index = (index + 1) % capacity;
    }
    return index;
}

void HashTable::insert(const string& value) {
    int index = findSlot(value);
    storage[index] = value;
    ++size;
}

bool HashTable::contains(const string& value) {
    int index = findSlot(value);
    return storage[index] == value;
}

bool HashTable::remove(const string& value) {
    int index = findSlot(value);
    if (storage[index] == value) {
        storage[index] = "";
        --size;
        return true;
    }
    return false;
}

string HashTable::toString() {
    stringstream ss;
    ss << "{";
    for (int i = 0; i < capacity; ++i) {
        if (!storage[i].empty()) {
            ss << storage[i] << ", ";
        }
    }
    string result = ss.str();
    if (result.length() > 1) {
        result.pop_back();
        result.pop_back();
    }
    result += "}";
    return result;
}