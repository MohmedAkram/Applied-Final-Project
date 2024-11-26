#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "Customer.h"

class SplayTree {
public:
    struct Node {
        Customer customer;
        Node* left;
        Node* right;

        Node(const Customer& cust) : customer(cust), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Private methods for Splay Tree operations
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* splay(Node* root, const Customer& key);
    Node* insert(Node* root, const Customer& key);
    Node* deleteNode(Node* root, const Customer& key);
    Node* find(Node* root, const Customer& key);

 //efeyhemwd

    SplayTree();
    ~SplayTree();

    void insert(const Customer& customer);
    void deleteKey(const Customer& customer);
    bool find(const Customer& customer);
    Node* findNode(const Customer& customer);
    void printInOrder();

    // Helper functions
    void printInOrderHelper(Node* node);
    void destroyTree(Node* node);
};

#endif
