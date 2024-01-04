#ifndef BST_DEF_H
#define BST_DEF_H

#include <iostream>
#include <vector>
#include "Node.h"

template <typename T>
class BinarySearchTree {
    private:
        
        Node<T>* root;
        int size;

        std::vector<T> values; // Contains every value within the tree - unsorted

        // Helper functions - aid with abstraction
        int getHeightHelper(const Node<T>* root, const int height) const;

        int findTreeSize(const Node<T>* root) const;
        void updateSize(const Node<T>* root);

        void clearTreeHelper(Node<T>* root);

    public:

        BinarySearchTree();
        /*TODO*/ BinarySearchTree(const BinarySearchTree& other); 

        ~BinarySearchTree();

        void setRoot(T value);
        void insert(const T value);
        /*TODO*/ Node<T>* remove(Node<T>* root, const T value); // Deletes specific value from tree

        Node<T>* getRoot() const;
        Node<T>* find(const T value) const;
        Node<T>* findParent(Node<T>* child) const;
        Node<T>* getSmallestLeaf() const;
        Node<T>* getLargestLeaf() const;

        void getMin(T& operand) const; // Pass by reference in case tree is empty
        void getMax(T& operand) const; 

        // Pass by reference in case tree is empty
        void getLeftChildValue(Node<T>* node, T& operand) const; 
        void getRightChildValue(Node<T>* node, T& operand) const;

        int getSize() const;
        int getHeight() const;

        void clear(); // Clear entire tree

        bool isEmpty() const;

        void writeToString(std::string& output) const; // Write tree contents to string argument
        std::string getStringForm() const; // Return string format of binary tree

        Node<T>* createTreeFromString(const std::string input);

};

#endif
