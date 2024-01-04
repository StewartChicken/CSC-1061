#ifndef STACK_IMP_H
#define STACK_IMP_H

#include "StackDEF.h"

template <typename T>
Stack<T>::Stack() : top(nullptr), capacityPtr(nullptr), size(0) {}

template <typename T>
Stack<T>::Stack(const int capacity) : top(nullptr), size(0) {
    this->capacity = capacity;
    capacityPtr = &this->capacity;
}

template <typename T>
Stack<T>::Stack(const Stack& other) : top(nullptr), size(0) {
    if (this == &other) return;

    if (other.capacityPtr) {
        this->capacity = other.capacity;
        this->capacityPtr = &this->capacity;
    } else {
        this->capacityPtr = nullptr;
    }

    Node* current = other.top;

    // Dynamic array to hold data since the stack must be traversed from top down
    T* data = new T[other.size];
    int index = 0;

    while (current) {
        data[index] = current->data;
        index ++;
        current = current->next;
    }

    // Reverse order of data
    for(int i = index - 1; i >= 0; i --) {
        push(data[i]);
    }

    delete data;
}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this == &other) return *this;

    clear();
    
    this->top = nullptr;

    if (other.capacityPtr) {
        this->capacity = other.capacity;
        this->capacityPtr = &this->capacity;
    } else {
        this->capacityPtr = nullptr;
    }

    Node* current = other.top;

    // Dynamic array to hold data since the stack must be traversed from top down
    T* data = new T[other.size];
    int index = 0;

    while (current) {
        data[index] = current->data;
        index ++;
        current = current->next;
    }

    // Switch order of data
    for(int i = index - 1; i >= 0; i --) {
        push(data[i]);
    }

    delete data;
    return *this;

}

template <typename T>
bool Stack<T>::operator==(const Stack& other) const {
    if (this->get_size() != other.get_size()) return false;

    Node* thisCurrent = this->top;
    Node* otherCurrent = other.top;

    while (thisCurrent) { // While thisCurrent != nullptr
        if (thisCurrent->data != otherCurrent->data) return false;

        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return true;
}

template <typename T>
bool Stack<T>::operator!=(const Stack& other) const {
    if (this->get_size() != other.get_size()) return true;

    Node* thisCurrent = this->top;
    Node* otherCurrent = other.top;

    while (thisCurrent) { // While thisCurrent != nullptr
        if (thisCurrent->data != otherCurrent->data) return true;

        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return false;
}

// Create a temp node pointer that points to the top of the stack
// Dynamically create a new node with the given value and assign it
//  to the top of the stack
// The new node's 'next' pointer points to the temp node's memory address
template <typename T>
void Stack<T>::push(const T value) {
    if (is_full()) {
        std::cout << "Stack is full" << std::endl;
        return;
    }

    if (is_empty()) { // Adding first element
        top = new Node(value);
    } else {
        Node* temp = top;
        top = new Node(value);
        top->next = temp;
    }

    size ++;
    
}

template <typename T>
T Stack<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }

    Node* temp = top;
    T topValue = temp->data;

    top = top->next;
    delete temp;

    size --;

    return topValue;

}

template <typename T>
T Stack<T>::peek() const {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }

    return top->data;
}

template <typename T>
size_t Stack<T>::get_size() const {
    return size;
}

template <typename T>
int Stack<T>::get_capacity() const {
    if (capacityPtr == nullptr) return -1;

    return capacity;
}

template <typename T>
bool Stack<T>::is_empty() const {
    return size == 0;
}

template <typename T>
bool Stack<T>:: is_full() const {
    if (capacityPtr == nullptr) return false;

    return size == capacity;
}

template <typename T>
void Stack<T>::clear() {
    while (!is_empty()) {
        pop();
    }

    size = 0;
}

template <typename T>
void Stack<T>::print() const {
    if (is_empty()) {
        std::cout << "\nStack is empty\n" << std::endl;
        return;
    }

    Node* current = top;

    std::cout << "\n";

    while (current) { // While current != nullptr
        std::cout << current->data << " ";
        current = current->next;
    }   
    
}

#endif