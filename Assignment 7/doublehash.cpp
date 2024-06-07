#include "doublehash.h"

DoubleHashTable::DoubleHashTable(int initialCapacity) : capacity(initialCapacity), size(0), storage(initialCapacity, "") {}

int DoubleHashTable::hash1(const string& value) {
    std::hash<string> hasher;
    return hasher(value) % capacity;
}

int DoubleHashTable::hash2(const string& value) {
    std::hash<string> hasher;
    return 1 + (hasher(value) % (capacity - 1));
}

int DoubleHashTable::findSlot(const string& value) {
    int index = hash1(value);
    int step = hash2(value);
    while (!storage[index].empty() && storage[index] != value) {
        index = (index + step) % capacity;
    }
    return index;
}

void DoubleHashTable::insert(const string& value) {
    int index = findSlot(value);
    storage[index] = value;
    ++size;
}

bool DoubleHashTable::contains(const string& value) {
    int index = findSlot(value);
    return storage[index] == value;
}

bool DoubleHashTable::remove(const string& value) {
    int index = findSlot(value);
    if (storage[index] == value) {
        storage[index] = "";
        --size;
        return true;
    }
    return false;
}

string DoubleHashTable::toString() {
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
