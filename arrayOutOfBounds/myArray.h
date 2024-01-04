#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>

class myArray{

    public:

        // Constructors/destructor
        myArray(int size);
        myArray(int firstIndex, int lastIndex);
        ~myArray();

        // Copy constructor
        myArray(const myArray &other);

        // Override assignment operator
        myArray& operator=(const myArray &other);

        // Override subscript operator
        int& operator[](int index);

        // Accessor methods
        int getSize() const { return size; }
        int* getArray() const { return array; }
        int getStart() const { return startIndex;}

        void print() const;

    private:
        int *array;
        int size;

        int startIndex;
};

#endif