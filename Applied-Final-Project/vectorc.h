#ifndef VECTORC_H
#define VECTORC_H

template <class T>
class vectorC {
private:
    T* data;
    int size;
    int currentSize;

    // Resize the array to a new capacity
    void resize();

public:
    // Constructor
    explicit vectorC(int s);

    // Destructor
    ~vectorC();

    // push an element to the vector
    T push(const T& data);

    // Remove and return the last element
    T pop();

    // Get the last element without removing it
    T peek();

    // Sort the vector
    //void sort();

    // Get the current size of the vector
    int getSize() const;
    void print() const;
};


#endif // VECTORC_H
