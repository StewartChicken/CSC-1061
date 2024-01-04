#ifndef BST_IMP_H
#define BST_IMP_H

#include "BSTDef.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
    size = 0;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear();
    this->root = nullptr;
    this->size = 0;
}

template <typename T>
void BinarySearchTree<T>::setRoot(T value) {
    this->root = new Node<T>(value);
}

template <typename T>
void BinarySearchTree<T>::insert(const T value) {
    if (isEmpty()) {
        setRoot(value);
        size ++;
        values.push_back(value);
        return;
    }

    Node<T>* node = new Node<T>(value); // New node

    Node<T>* parent = this->root;
    Node<T>* index = this->root; // Node used to index the tree

    while(true) {
        if (*index > value) { // Value falls within left subtree
            parent = index;
            index = index->left;
        } 
        else if (*index < value) { // Value falls within right subtree
            parent = index;
            index = index->right;
        }

        if (index == nullptr) { // Found location for new node
            if (*parent == value) return;

            if (*parent > value) {
                parent->setLeft(node);
                size ++;
                values.push_back(value);
                return;
            }
            else {
                parent->setRight(node);
                size ++;
                values.push_back(value);
                return;
            }
        }
    }

} // End insert definition

// Recursive removal of specific element from tree
template <typename T>
Node<T>* BinarySearchTree<T>::remove(Node<T>* root, const T value) {
    
    // Base case
    if (root == nullptr) return root;

    // Search for value in tree
    if (root->getData() > value) {
        root->left = remove(root->left, value);
        return root;
    } 
    else if (root->getData() < value) {
        root->right = remove(root->right, value);
        return root;
    }

    // Found root

    if (root->left == nullptr) {
        Node<T>* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == nullptr) {
        Node<T>* temp = root->left;
        delete root;
        return temp;
    }
    else { // Both children exist

        Node<T>* successorParent = root;

        Node<T>* successor = root->right;
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent != root) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        root->setData(successor->getData());

        delete successor;
        return root;

    }

} // End remove definition

template <typename T>
Node<T>* BinarySearchTree<T>::getRoot() const {
    return this->root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::find(const T value) const {
    if (this->getRoot() == nullptr) return nullptr;

    Node<T>* index = this->root; // Node to index the tree

    T indexValue; // Initial value is root node's value
    index->getData(indexValue); // Pass value of index to indexValue

    while (index->hasValue()) {
        if (indexValue > value) {
            index = index->leftptr;
            index->getData(indexValue);
        } 
        else {
            index = index->rightptr;
            index->getData(indexValue);
        }
    }

    return index;

} // End find definition

template <typename T>
Node<T>* BinarySearchTree<T>::findParent(Node<T>* node) const {
    // Tree root has no parent | empty trees have no parent
    if (node == getRoot() || getRoot() == nullptr) return nullptr;

    Node<T>* parent = getRoot();

    T parentValue;
    parent->getData(parentValue); // Pass value of parent to parentValue

    T nodeValue;
    node->getData(nodeValue); // Pass value of node into nodeValue

    while (true) {
        // If either of the parent's children contain data that is equal to the child node
        if (getLeftChildValue(parent) == nodeValue || getRightChildValue(parent) == nodeValue) {
            return parent;
        }

        if (parentValue > nodeValue) {
            parent = parent->left;
            parent->getData(parentValue);
        }
        else {
            parent = parent->right;
            parent->getData(parentValue);
        }
    }

} // End findParent definition

template <typename T>
Node<T>* BinarySearchTree<T>::getSmallestLeaf() const {
    Node<T>* leaf = getRoot();
    Node<T>* index = getRoot()->left;

    // Reach bottom of tree
    while (index != nullptr) {
        leaf = index;
        index = index->left;
    }

    return leaf;
}

template <typename T>
Node<T>* BinarySearchTree<T>::getLargestLeaf() const {
    Node<T>* leaf = getRoot();
    Node<T>* index = getRoot()->right;

    // Reach bottom of tree
    while (index != nullptr) {
        leaf = index;
        index = index->right;
    }

    return leaf;
}

template <typename T>
void BinarySearchTree<T>::getMin(T& operand) const {
    Node<T>* min = getRoot();
    Node<T>* index = getRoot()->left;

    while (index != nullptr) {
        min = index;
        index = index->left;
    }

    min.getValue(operand);

}

template <typename T>
void BinarySearchTree<T>::getMax(T& operand) const {
    Node<T>* max = getRoot();
    Node<T>* index = getRoot()->right;

    while (index != nullptr) {
        max = index;
        index = index->right;
    }

    max.getValue(operand);
    
}

template <typename T>
void BinarySearchTree<T>::getLeftChildValue(Node<T>* node, T& operand) const {
    node->left->getValue(operand);
}

template <typename T>
void BinarySearchTree<T>::getRightChildValue(Node<T>* node, T& operand) const {
    node->right->getValue(operand);
}

template <typename T>
int BinarySearchTree<T>::getSize() const {
    return this->size;
}

template <typename T>
int BinarySearchTree<T>::getHeight() const {
    return getHeightHelper(getRoot(), 0);
}

template <typename T>
void BinarySearchTree<T>::clear() {
    clearTreeHelper(getRoot());
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
    return getRoot() == nullptr;
}


// ----------------------------------------------------------------
// Helper functions (private)
// ----------------------------------------------------------------

template <typename T>
int BinarySearchTree<T>::getHeightHelper(const Node<T>* root, const int height) const {
    if (root == nullptr) return 0; // Base case

    // Get left/right subtree height
    int leftHeight = getHeightHelper(root->left, height + 1);
    int rightHeight = getHeightHelper(root->right, height + 1);

    // Bottom leaf returns entire height of tree
    if (leftHeight == 0 and rightHeight == 0) return height;

    if (leftHeight == rightHeight) return leftHeight; 

    // Returns larger of the two heights
    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

template <typename T>
int BinarySearchTree<T>::findTreeSize(const Node<T>* root) const {
    if (root == nullptr) return 0; // Base case

    int leftSubtreeSize = findTreeSize(root->left);
    int rightSubtreeSize = findTreeSize(root->right);

    // Return size of both subtrees + root node
    return leftSubtreeSize + rightSubtreeSize + 1;
}   

template <typename T>
void BinarySearchTree<T>::updateSize(const Node<T>* root) {
    this->size = findTreeSize(root);
}

template <typename T>
void BinarySearchTree<T>::clearTreeHelper(Node<T>* root) {
    if (root == nullptr) return; // Base case   

    clearTreeHelper(root->left);
    clearTreeHelper(root->right);

    delete root;
    root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::writeToString(std::string& output) const {
    output = getStringForm();
}

// Writes the binary search tree to a string format using traversals
template <typename T>
std::string BinarySearchTree<T>::getStringForm() const {

}
#endif