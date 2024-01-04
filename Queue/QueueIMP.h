#ifndef QUEUE_IMP_H
#define QUEUE_IMP_H

#include "QueueDEF.h"

template <typename T> 
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0), capacityPtr(nullptr) {}

template <typename T>
Queue<T>::Queue(const int capacity) : front(nullptr), rear(nullptr), size(0) {
    this->capacity = capacity;
    capacityPtr = &this->capacity;
}

template <typename T>
Queue<T>::Queue(const Queue& other) : front(nullptr), rear(nullptr), size(0) {
    if (this == &other) return;

    if (other.capacityPtr) { // If 'other' has a capacity, update capacity
        this->capacity = other.capacity;
        this->capacityPtr = &this->capacity;
    } else {
        capacityPtr = nullptr; // No capacity
    }

    Node* current = other.front;

    while (current) {
        enqueue(current->data);
        current = current->next;
    }

}

template <typename T>
Queue<T>::~Queue() {
    clear(); // Empties queue, sets size to 0
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this == &other) return *this;

    clear(); // Empties queue and sets size to 0

    this->front = nullptr;
    this->rear = nullptr;

    if (other.capacityPtr) { // If 'other' has a capacity
        this->capacity = other.capacity;
        this->capacityPtr = &this->capacity;
    } else {
        this->capacityPtr = nullptr;
    }

    Node* current = other.front;

    while (current) {
        enqueue(current->data);
        current = current->next;
    }

    return *this;
}

// Compare each element of each queue
template <typename T>
bool Queue<T>::operator==(const Queue& other) const {
    if (this->get_size() != other.get_size()) return false;

    Node* thisCurrent = this->front;
    Node* otherCurrent = other.front;

    while (thisCurrent) { // While thisCurrent != nullptr
        if (thisCurrent->data != otherCurrent->data) return false;

        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return true;
}

// Compare each element of each queue
template <typename T>
bool Queue<T>::operator!=(const Queue& other) const {
    if (this->get_size() != other.get_size()) return true;

    Node* thisCurrent = this->front;
    Node* otherCurrent = other.front;

    while (thisCurrent) { // While thisCurrent != nullptr
        if (thisCurrent->data != otherCurrent->data) {
            return true;
        }

        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return false;
}

template <typename T>
void Queue<T>::enqueue(const T value) {

    if (is_full()) {
        std::cout << "Queue is full" << std::endl;
        return;
    }

    if (is_empty()) {
        front = rear = new Node(value); // Insert first node
    } else {
        rear->next = new Node(value);
        rear = rear->next;
    }

    size ++;
}

// This is the only function that deallocates memory
template <typename T>
void Queue<T>::dequeue() {
    if (is_empty()) {
        std::cout << "Cannot dequeue an empty queue" << std::endl;
        return;
    }

    if (front == rear) { // Queue contains one element
        
        delete front;
        front = nullptr;
        rear = nullptr;

        size --;
        return;
    }

    Node* dequeued = front;
    front = front->next;

    delete dequeued;

    size --;
}

template <typename T>
T Queue<T>::get_front() const {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    
    return front->data;
}

template <typename T>
size_t Queue<T>::get_size() const {
    return size;
}

// Return -1 if queue has no capacity
template <typename T>
int Queue<T>::get_capacity() const {
    if (capacityPtr == nullptr) return -1;

    return capacity;
}

template <typename T>
bool Queue<T>::is_empty() const {
    return size == 0;
}

template <typename T>
bool Queue<T>::is_full() const {
    if (capacityPtr == nullptr) return false;

    return size == capacity;
}

template <typename T>
void Queue<T>::clear() {
    while (!is_empty()) {
        dequeue();
    }

    size = 0;
}

template <typename T>
void Queue<T>::print() const {
    if (is_empty()) {
        std::cout << "\nQueue is empty\n" << std::endl;
        return;
    }

    Node* frontIndex = front;
    Node* rearIndex = rear;

    std::cout << "\n";

    while(frontIndex != rearIndex) {
        std::cout << frontIndex->data << " ";
        frontIndex = frontIndex->next;
    }

    std::cout << frontIndex->data;
}

#endif