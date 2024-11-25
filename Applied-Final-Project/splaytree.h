#ifndef SPLAYTREE_H
#define SPLAYTREE_H

class SplayTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Private methods for Splay Tree operations
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* splay(Node* root, int key);
    Node* insert(Node* root, int key);
    Node* deleteNode(Node* root, int key);
    Node* find(Node* root, int key);

public:
    SplayTree();
    ~SplayTree();

    void insert(int key);
    void deleteKey(int key);
    bool find(int key);
    void printInOrder();

    // Helper functions
    void printInOrderHelper(Node* node);
    void destroyTree(Node* node);
};

#endif
