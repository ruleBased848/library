#include "array.h"
#include <stdexcept>

array_int::array_int(int initSize) {
    if (initSize < 0) { throw std::out_of_range {""}; }
    theSize = initSize;
    theCapacity = initSize == 0 ? 1 : initSize * 2;
    theArray = new int[theCapacity];
}

array_int::~array_int() {
    delete[] theArray;
}

int& array_int::operator[](int index) {
    if (index < 0 || index >= theSize) { throw std::out_of_range {""}; }
    return theArray[index];
}

const int& array_int::operator[](int index) const {
    if (index < 0 || index >= theSize) { throw std::out_of_range {""}; }
    return theArray[index];
}

int array_int::size() const {
    return theSize;
}

void array_int::push_back(int x) {
    if (theSize == theCapacity) {
        theCapacity = 2 * (theSize + 1);
        int* newArray = new int[theCapacity];
        for (int i = 0; i < theSize; ++i) {
            newArray[i] = theArray[i];
        }
        delete[] theArray;
        theArray = newArray;
    }
    theArray[theSize++] = x;
}

int array_int::pop_back() {
    if (theSize == 0) { throw std::logic_error {""}; }
    return theArray[--theSize];
}

void array_int::insertion_sort() {
    for (int i = 1; i < theSize; ++i) {
        int key = theArray[i];
        int j = i - 1;
        while (j >= 0 && theArray[j] > key) {
            theArray[j + 1] = theArray[j];
            --j;
        }
        theArray[j + 1] = key;
    }
}

void array_int::selection_sort() {
    for (int i = 0; i < theSize - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < theSize; ++j) {
            if (theArray[j] < theArray[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int tmp = theArray[i];
            theArray[i] = theArray[minIndex];
            theArray[minIndex] = tmp;
        }
    }
}