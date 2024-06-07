#include "hash.h"
#include "doublehash.h"

using std::cout;
using std::endl;


int main() {
    HashTable ht(10);

    ht.insert("apple");
    ht.insert("banana");
    ht.insert("cherry");
    ht.insert("banana"); // This should overwrite the existing "banana"

    cout << ht.toString() << endl; // {apple, banana, cherry}

    cout << std::boolalpha;
    cout << "contains banana: " << ht.contains("banana") << endl; // true
    cout << "contains grape: " << ht.contains("grape") << endl; // false

    ht.remove("banana");
    cout << ht.toString() << endl; // {apple, cherry}

    DoubleHashTable dh(10);

    ht.insert("apple");
    ht.insert("banana");
    ht.insert("cherry");
    ht.insert("banana"); // This should overwrite the existing "banana"

    cout << ht.toString() << endl; // {apple, banana, cherry}

    cout << std::boolalpha;
    cout << "contains banana: " << ht.contains("banana") << endl; // true
    cout << "contains grape: " << ht.contains("grape") << endl; // false

    ht.remove("banana");
    cout << ht.toString() << endl; // {apple, cherry}

    return 0;
}