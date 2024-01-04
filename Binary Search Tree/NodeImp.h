#ifndef NODE_IMP_H
#define NODE_IMP_H

#include "NodeDef.h"

template <typename T>
Node<T>::Node() {
    dataptr = nullptr;
    left = nullptr;
    right = nullptr;
}

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    dataptr = &this->data;
    right = nullptr;
    left = nullptr;
}

template <typename T>
Node<T>::Node(const Node& other) {
    if (this == &other) return;

    if (other.hasData()) {
        data = other.getData(); // Update the value of data with other's data
    } 
    else {
        dataptr = nullptr;
    }

    this->right = other.right;
    this->left = other.left;
}

template <typename T>
Node<T>::~Node() {}

// Pass by reference bc data may be null if node is empty
template <typename T>
T Node<T>::getData() const {
    if (dataptr) return data;

    T r; // Temp sol to avoid warnings
    return r;
    // Throw exception
}

template <typename T>
void Node<T>::setData(T data) {
    this->data = data;
    dataptr = &this->data;
}

template <typename T>
void Node<T>::setRight(Node* node) {
    this->right = node;
}

template <typename T>
void Node<T>::setLeft(Node* node) {
    this->left = node;
}

template <typename T>
bool Node<T>::hasRight() const {
    return (this->right);
}

template <typename T>
bool Node<T>::hasLeft() const {
    return (this->left);
}

template <typename T>
bool Node<T>::isLeaf() const {
    if (!hasLeft() && !hasRight()) return true;

    return false;
}

template <typename T>
bool Node<T>::hasOnlyOneChild() const {
    if (hasLeft() && !hasRight()) return true;
    if (hasRight() && !hasLeft()) return true;

    return false;
}

template <typename T>
Node<T>* Node<T>::getSingularChild() const {
    if (!hasOnlyOneChild()) return nullptr;

    if (left == nullptr) {
        return right;
    }

    return left;

}

// Reset whole node
template <typename T>
void Node<T>::reset() {
    *this = Node();
}

template <typename T>
void Node<T>::clear() {
    dataptr = nullptr;
}

template <typename T>
void Node<T>::clearRight() {
    this->right = nullptr;
}

template <typename T>
void Node<T>::clearLeft() {
    this->left = nullptr;
}

// ----------------------------------------------------------------
// Operator overrides // TODO
// ----------------------------------------------------------------

template <typename T>
Node<T>& Node<T>::operator=(const Node& other) {
    if (this == &other) return *this;

    if (other.hasData()) {
        other.getData(this->data); // Update the value of data with other's data
    } 
    else {
        dataptr = nullptr;
    }

    this->right = other.right;
    this->left = other.left;
}

template <typename T>
Node<T>& Node<T>::operator=(T value) {
    this->data = value;

    return *this;
}

template <typename T>
bool Node<T>::operator>(const T data) const {
    return this->getData() > data;
}

template <typename T>
bool Node<T>::operator>=(const T data) const {
    return this-getData() >= data;
}

template <typename T>
bool Node<T>::operator<(const T data) const {
    return this->getData() < data;
}

template <typename T>
bool Node<T>::operator<=(const T data) const {
    return this->getData() <= data;
}

template <typename T>
bool Node<T>::operator==(const T data) const {
    return this->getData() == data;
}

template <typename T>
bool Node<T>::operator!=(const T data) const {
    return this->getData() != data;
}


#endif