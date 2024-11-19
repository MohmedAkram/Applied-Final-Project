#include "vectorC.h"
#include <stdexcept>
#include <algorithm>  // For std::swap
#include <iostream>



// Constructor
template <class T>
vectorC<T>::vectorC(int s) {
    size = s;
    currentSize = 0;
    data = new T[size];
}

// Destructor
template <class T>
vectorC<T>::~vectorC() {
    delete[] data;
}

// Add an element to the vector
template <class T>
T vectorC <T>::push(const T& value) {
    if (currentSize == size) {
        resize();  // Increase size by 5 when capacity is full
    }
    data[currentSize] = value;
    currentSize++;
    return data[currentSize - 1];
}

// Resize the array to a new size
template <class T>
void vectorC<T>::resize() {
    T* newData = new T[size+5];
    for (int i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = size+5;
}

// Pop the last element from the vector
template <class T>
T vectorC<T>::pop() {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[--currentSize];
}

// Peek the last element in the vector
template <class T>
T vectorC<T>::peek() {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[currentSize - 1];
}

// // Sort the vector (simple bubble sort for demonstration purposes)
// template <class T>
// void vectorC<T>::sort() {
//     for (int i = 0; i < currentSize - 1; ++i) {
//         for (int j = 0; j < currentSize - i - 1; ++j) {
//             if (data[j] > data[j + 1]) {
//                 std::swap(data[j], data[j + 1]);
//             }
//         }
//     }
// }

// Get the current size of the vector
template <class T>
int vectorC<T>::getSize() const {
    return currentSize;
}




template<class T>
void vectorC<T>::print() const {
    for (int i = 0; i < currentSize; ++i) {
        std::cout << data[i] << " ";
    }
}

// Explicit instantiation for the types you plan to use
template class vectorC<int>;  // For integers
//template class vectorC<Halls>;


