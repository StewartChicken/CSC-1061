#ifndef NODE_DEF_H
#define NODE_DEF_H

#include <iostream>

template <typename T>
class Node{
    private: 
        
        T data;
        T* dataptr;

    public:

        Node* left;
        Node* right;

        Node();
        Node(T data);
        Node(const Node& other); // Copy constructor

        ~Node(); // Empty-bodied destructor

        T getData() const; // Pass by reference bc data may be nullptr
        void setData(T data);

        void setRight(Node* node);
        void setLeft(Node* node);

        bool hasData() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isLeaf() const;
        bool hasOnlyOneChild() const;

        // Returns pointer to only child - returns nullptr if has two children
        Node* getSingularChild() const; 

        void reset(); // Reset node
        void clear(); // Clear data
        void clearRight();
        void clearLeft();

        Node& operator=(const Node& other);
        Node& operator=(const T value);
        bool operator>(const T value) const;
        bool operator>=(const T value) const;
        bool operator<(const T value) const;
        bool operator<=(const T value) const;
        bool operator==(const T value) const;
        bool operator!=(const T value) const;

};

#endif