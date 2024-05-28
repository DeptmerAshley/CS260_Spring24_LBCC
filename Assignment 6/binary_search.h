#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "node.h"
#include <iostream>
using namespace std;

class BST {
public:
    BST();
    
    // Function to insert a new value into the BST
    void insert(int value);

    //Function to remove a value from the BST
    void remove(int value);
    
    // Function to search for a value in the BST
    bool search(int value);

    // Function to display the inorder traversal of the BST
    void inorder();
    
private:
    Node* root;
    
    // Recursive function to insert a new value in the BST
    Node* insertRec(Node* node, int value);

    //Recursive function to remove a value from the BST
    Node* removeRec(Node* node, int value);

    // Helper function to find the node with the minimum value in the BST
    Node* minValueNode(Node* node);

    // Recursive function to search for a value in the BST
    bool searchRec(Node* node, int value);
    
    // Recursive function to perform an inorder traversal of the BST
    void inorderRec(Node* node);
};

#endif