#include "SplayTree.h"
#include <iostream>
using namespace std;

// Constructor
SplayTree::SplayTree() : root(nullptr) {}

// Destructor
SplayTree::~SplayTree() {
    destroyTree(root);
}

// Right rotation
SplayTree::Node* SplayTree::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

// Left rotation
SplayTree::Node* SplayTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation (bring the node with key to the root)
SplayTree::Node* SplayTree::splay(Node* root, int key) {
    if (root == nullptr || root->value == key)
        return root;

    // Key lies in left subtree
    if (key < root->value) {
        if (root->left == nullptr)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->value) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->value) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        return root == nullptr ? root : rightRotate(root);
    }
    // Key lies in right subtree
    else {
        if (root->right == nullptr)
            return root;

        // Zag-Zig (Right Left)
        if (key < root->right->value) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->value) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return root == nullptr ? root : leftRotate(root);
    }
}

// Insert operation
SplayTree::Node* SplayTree::insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    root = splay(root, key);

    if (root->value == key)
        return root;  // Key already exists

    Node* newNode = new Node(key);

    if (key < root->value) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    }
    else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    return newNode;
}

// Delete operation
SplayTree::Node* SplayTree::deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    root = splay(root, key);

    if (root->value != key)
        return root;  // Key not found

    // If one of the children is empty, replace root with the other child
    if (root->left == nullptr) {
        Node* temp = root;
        root = root->right;
        delete temp;
    }
    else {
        Node* temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
        delete temp;
    }

    return root;
}

// Find operation
SplayTree::Node* SplayTree::find(Node* root, int key) {
    root = splay(root, key);
    if (root != nullptr && root->value == key)
        return root;
    return nullptr;
}

// Insert public function
void SplayTree::insert(int key) {
    root = insert(root, key);
}

// Delete public function
void SplayTree::deleteKey(int key) {
    root = deleteNode(root, key);
}

// Find public function
bool SplayTree::find(int key) {
    return find(root, key) != nullptr;
}

// In-order traversal
void SplayTree::printInOrder() {
    printInOrderHelper(root);
    cout << endl;
}

void SplayTree::printInOrderHelper(Node* node) {
    if (node != nullptr) {
        printInOrderHelper(node->left);
        cout << node->value << " ";
        printInOrderHelper(node->right);
    }
}

// Helper function to delete the entire tree
void SplayTree::destroyTree(Node* node) {
    if (node == nullptr) return;

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
