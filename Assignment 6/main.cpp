#include "node.h"
#include  "binary_search.h"

int main() {
    BST bst;
    
    // Test Insert and Inorder Traversal
    cout << "Testing Insert and Inorder Traversal:" << endl;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(7);
    bst.insert(15);
    bst.insert(30);
    
    cout << "Inorder Traversal: ";
    bst.inorder(); // Expected: 3 5 7 10 15 20 30
    
    // Test Search
    cout << "\nTesting Search:" << endl;
    cout << "Search 15: " << (bst.search(15) ? "Found" : "Not Found") << endl; // Expected: Found
    cout << "Search 8: " << (bst.search(8) ? "Found" : "Not Found") << endl;   // Expected: Not Found
    
    // Test Remove
    cout << "\nTesting Remove:" << endl;
    cout << "Remove 20:" << endl;
    bst.remove(20);
    cout << "Inorder Traversal: ";
    bst.inorder(); // Expected: 3 5 7 10 15 30
    
    cout << "Remove 5:" << endl;
    bst.remove(5);
    cout << "Inorder Traversal: ";
    bst.inorder(); // Expected: 3 7 10 15 30
    
    cout << "Remove 10:" << endl;
    bst.remove(10);
    cout << "Inorder Traversal: ";
    bst.inorder(); // Expected: 3 7 15 30
    
    return 0;
}