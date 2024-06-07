This is a hash table that sorts values based on their ASCII values

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

{banana, cherry, apple}
contains banana: true
contains grape: false
{cherry, apple}


        For double hash:

{banana, cherry, apple}
contains banana: true
contains grape: false
{cherry, apple}
{banana, cherry, apple}
contains banana: true
contains grape: false
{cherry, apple}