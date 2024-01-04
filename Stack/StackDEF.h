#ifndef STACK_DEF_H
#define STACK_DEF_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack{

    private:
        
        struct Node {
            T data;
            Node* next;

            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* top;
        size_t size;

        int capacity;
        int* capacityPtr;

    public:

        Stack();
        Stack(const int capacity);
        Stack(const Stack& other);

        ~Stack();

        Stack& operator=(const Stack& other);
        bool operator==(const Stack& other) const;
        bool operator!=(const Stack& other) const;

        void push(const T value);
        T pop();
        T peek() const;

        size_t get_size() const;
        int get_capacity() const;
        bool is_empty() const;
        bool is_full() const;

        void clear();

        void print() const;

};

#endif