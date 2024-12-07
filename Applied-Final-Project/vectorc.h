#ifndef VECTORC_H
#define VECTORC_H

#include <iostream>
#include <stdexcept>
#include <algorithm>  // For std::swap

template <class T>
class vectorC {
public:
    T** data;       // Array of pointers
    int size;       // Capacity of the array
    int currentSize;  // Number of elements currently in the array

    // Resize the array to a new capacity
    void resize();
    explicit vectorC(int s = 10);
    ~vectorC();
    void remove(int index);
    void push(T* value);  // Add a pointer to the array
    T* pop();             // Remove and return the last pointer
    T* peek() const;      // View the last pointer without removing it
    T* get(int index) const;  // Get a pointer at a specific index

    int getSize() const;  // Return the current number of elements
    void print() const;   // Print the elements
};

// Constructor
template <class T>
vectorC<T>::vectorC(int s) {
    size = s;
    currentSize = 0;
    data = new T*[size];  // Allocate array of pointers
}

// Destructor
template <class T>
vectorC<T>::~vectorC() {
    delete[] data;  // Free the array of pointers
}

// Add a pointer to the array
template <class T>
void vectorC<T>::push(T* value) {
    if (currentSize == size) {
        throw std::out_of_range("Vector is full");
    }
    data[currentSize] = value;
    currentSize++;
}

// Remove and return the last pointer
template <class T>
T* vectorC<T>::pop() {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[--currentSize];
}

// View the last pointer without removing it
template <class T>
T* vectorC<T>::peek() const {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[currentSize - 1];
}

// Get a pointer at a specific index
template <class T>
T* vectorC<T>::get(int index) const {
    if (index < 0 || index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];  // Return the pointer to the object at the given index
}

// Get the current number of elements
template <class T>
int vectorC<T>::getSize() const {
    return currentSize;
}
template <class T>
void vectorC<T>::remove(int index) {
    if (index < 0 || index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }

    // If the index is not the last element, shift elements to fill the gap
    for (int i = index; i < currentSize - 1; ++i) {
        data[i] = data[i + 1]; // Shift each element one position to the left
    }

    data[currentSize - 1] = nullptr; // Optional: Nullify the last position
    --currentSize; // Decrease the size of the vector
}

// Print the elements (for debugging purposes)
template <class T>
void vectorC<T>::print() const {
    for (int i = 0; i < currentSize; ++i) {
        std::cout << *data[i] << " ";  // Dereference to print the object
    }
}
#endif // VECTORC_H
