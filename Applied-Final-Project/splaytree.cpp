#include "splaytree.h"

// Right rotation
template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::rightRotate(Node* node) {
    Node* x = node->left;
    node->left = x->right;
    x->right = node;
    return x;
}

// Left rotation
template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::leftRotate(Node* node) {
    Node* x = node->right;
    node->right = x->left;
    x->left = node;
    return x;
}

// Splay operation
template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::splay(Node* root, const T& key) {
    if (!root || root->data == key)
        return root;

    // Key lies in the left subtree
    if (key < root->data) {
        if (!root->left) return root;

        if (key < root->left->data) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->data) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }

        return (root->left) ? rightRotate(root) : root;
    }
    // Key lies in the right subtree
    else {
        if (!root->right) return root;

        if (key > root->right->data) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->data) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }

        return (root->right) ? leftRotate(root) : root;
    }
}

// Insert operation
template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::insert(Node* root, const T& key) {
    if (!root) return new Node(key);

    root = splay(root, key);

    if (root->data == key) return root;

    Node* newNode = new Node(key);
    if (key < root->data) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    return newNode;
}

// Remove operation
template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::deleteNode(Node* root, const T& key) {
    if (!root) return nullptr;

    root = splay(root, key);

    if (root->data != key) return root;

    Node* temp;
    if (!root->left) {
        temp = root->right;
    } else {
        temp = splay(root->left, key);
        temp->right = root->right;
    }

    delete root;
    return temp;
}

// Insert key
template <typename T>
void SplayTree<T>::insert(const T& key) {
    root = insert(root, key);
}

// Remove key
template <typename T>
void SplayTree<T>::remove(const T& key) {
    root = deleteNode(root, key);
}

// Search key
template <typename T>
bool SplayTree<T>::search(const T& key) {
    root = splay(root, key);
    return root && root->data == key;
}

// In-order traversal
template <typename T>
void SplayTree<T>::inorder(Node* root) const {
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

template <typename T>
void SplayTree<T>::displayInOrder() const {
    inorder(root);
    std::cout << std::endl;
}

// Clear tree
template <typename T>
void SplayTree<T>::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
