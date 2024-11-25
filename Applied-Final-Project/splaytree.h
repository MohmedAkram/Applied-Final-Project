#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>

template <typename T>
class SplayTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Utility functions
    Node* splay(Node* root, const T& key);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    Node* insert(Node* root, const T& key);
    Node* deleteNode(Node* root, const T& key);
    void inorder(Node* root) const;

public:
    SplayTree() : root(nullptr) {}
    ~SplayTree() { clear(root); }

    // Public member functions
    void insert(const T& key);
    void remove(const T& key);
    bool search(const T& key);
    void displayInOrder() const;

private:
    void clear(Node* node);
};

#endif // SPLAYTREE_H
