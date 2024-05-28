#include "binary_search.h"


BST::BST() {
    root = nullptr;
}

void BST::insert(int value) {
    root = insertRec(root, value);
}

void BST::remove(int value) {
        root = removeRec(root, value);
}

bool BST::search(int value) {
    return searchRec(root, value);
}

void BST::inorder() {
    inorderRec(root);
    cout << endl;
}

Node* BST::insertRec(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    
    if (value < node->data) {
        node->left = insertRec(node->left, value);
    } 
    else if (value > node->data) {
        node->right = insertRec(node->right, value);
    }
    
    return node;
}

Node* BST::removeRec(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }
    
    if (value < node->data) {
        node->left = removeRec(node->left, value);
    } 
    else if (value > node->data) {
        node->right = removeRec(node->right, value);
    } 
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } 
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = removeRec(node->right, temp->data);
    }
    
    return node;
}

Node* BST::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

bool BST::searchRec(Node* node, int value) {
    if (node == nullptr) {
        return false;
    }
    
    if (node->data == value) {
        return true;
    } 
    else if (value < node->data) {
        return searchRec(node->left, value);
    } 
    else {
        return searchRec(node->right, value);
    }
}

void BST::inorderRec(Node* node) {
    if (node != nullptr) {
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }
}