#include "myArray.h"
#include <iostream>

// Single parameter constructor
myArray::myArray(int size){
    this->array = new int[size];
    this->size = size;

    startIndex = 0;

    for(int i{}; i < size; i++){
        this->array[i] = 0;
    }
}

// Two parameter constructor
myArray::myArray(int firstIndex, int secondIndex){
    this->array = new int[secondIndex - firstIndex];
    this->size = secondIndex - firstIndex;

    startIndex = firstIndex;

    for(int i{}; i < size; i++){
        this->array[i] = 0;
    }
}

// Destructor
myArray::~myArray(){
    delete[] this->array;
}

// Copy constructor
myArray::myArray(const myArray &other){
    size = other.getSize();
    array = new int[size];
    startIndex = other.getStart();

    for(int i{}; i < size; i ++){
        array[i] = other.getArray()[i];
    }
}

// Overload assignment operator
myArray& myArray::operator=(const myArray &other){
    if(this == &other){
        return *this;
    }

    if(this->size != other.getSize()){
        std::cout << "Size of the array is not the same!" << std::endl;
        return *this;
    }

    for(int i{}; i < this->size; i ++){
        this->array[i] = other.getArray()[i];
    }

    return *this;
}

// Overload subscript operator - allows for negative indeces
int& myArray::operator[](int index){
    if(index < this->startIndex || index >= (this->startIndex + this->size)){
        std::cout << "Index out of bounds!\nYou cannot access indeces outside of " << 
        "the range (" << this->startIndex << ", " << (this->startIndex + this->size) << ")\n";
        return this->array[0];
    }else{
        return this->array[index - this->startIndex];
    }
}

// Added for debugging purposes
void myArray::print() const{
    for(int i{}; i < this->size; i ++){
        std::cout << this->array[i] << " ";
    }
    std::cout << std::endl;
}
