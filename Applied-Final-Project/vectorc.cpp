#include <stdexcept>
#include <algorithm>
#include <iostream>

template <class T>
class vectorC {
public:
    vectorC(int s = 5);     // Default size is 5
    ~vectorC();

    void push(const T& value);
    T pop();
    T& peek() const;
    int getSize() const;
    void print() const;

private:
    void resize();

    T* data;
    int currentSize;
    int capacity;
};

// Constructor
template <class T>
vectorC<T>::vectorC(int s) : capacity(s), currentSize(0) {
    if (capacity <= 0) throw std::invalid_argument("Size must be positive");
    data = new T[capacity];
}

// Destructor
template <class T>
vectorC<T>::~vectorC() {
    delete[] data;
}

// Add an element to the vector
template <class T>
void vectorC<T>::push(const T& value) {
    if (currentSize == capacity) {
        resize();
    }
    data[currentSize++] = value;
}

// Resize the array
template <class T>
void vectorC<T>::resize() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];
    for (int i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Pop the last element
template <class T>
T vectorC<T>::pop() {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[--currentSize];
}

// Peek the last element
template <class T>
T& vectorC<T>::peek() const {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[currentSize - 1];
}

// Get the current size
template <class T>
int vectorC<T>::getSize() const {
    return currentSize;
}

// Print the elements
template <class T>
void vectorC<T>::print() const {
    for (int i = 0; i < currentSize; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
