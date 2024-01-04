#ifndef QUEUE_DEF_H
#define QUEUE_DEF_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T>
class Queue {

    private:
        
        // Basic node template
        struct Node {
            T data;
            Node* next; // Points to "next node in line"

            Node(const T& value) : data(value), next(nullptr) {}; // Constructor
        };

        Node* front;
        Node* rear;
        size_t size;

        int capacity; 
        int* capacityPtr; // If nullptr, Queue has no capacity

    public:

        Queue();
        Queue(const int capacity);
        Queue(const Queue& other);

        ~Queue();

        Queue& operator=(const Queue& other);
        bool operator==(const Queue& other) const;
        bool operator!=(const Queue& other) const;

        void enqueue(const T value);
        void dequeue();

        T get_front() const;
        
        size_t get_size() const;
        int get_capacity() const; // -1 means queue has no capacity    
        bool is_empty() const;
        bool is_full() const;

        void clear();

        void print() const; // Print queue contents

};

#endif