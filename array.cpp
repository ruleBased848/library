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

void array_int::merge_sort() {
    merge_sort(0, theSize - 1);
}

void array_int::merge_sort(int begin, int end) {
    if (begin >= end) { return; }
    int mid = (begin + end) / 2;
    merge_sort(begin, mid);
    merge_sort(mid + 1, end);
    array_int tmp {end - begin + 1};
    int index1 = begin;
    int index2 = mid + 1;
    for (int i = 0; i < tmp.size(); ++i) {
        bool insertFromFirstSubarray = index2 > end || (mid >= index1 && theArray[index1] <= theArray[index2]);
        tmp[i] = theArray[insertFromFirstSubarray ? index1++ : index2++];
    }
    for (int i = 0; i < tmp.size(); ++i) {
        theArray[begin + i] = tmp[i];
    }
}

void array_int::bubble_sort() {
    for (int i = 0; i < theSize - 1;) {
        int next = theSize - 1;
        for (int j = theSize - 1; j > i; --j) {
            if (theArray[j] < theArray[j - 1]) {
                int tmp = theArray[j];
                theArray[j] = theArray[j - 1];
                theArray[j - 1] = tmp;
                next = j;
            }
        }
        i = next;
    }
}

void array_int::make_max_heap() {
    for (int i = theSize / 2 - 1; i >= 0; --i) {
        int key = theArray[i];
        int j = i;
        while (true) {
            int l = 2 * j + 1;
            int r = 2 * j + 2;
            if (l >= theSize || (theArray[l] <= key && (r >= theSize || theArray[r] <= key))) {
                theArray[j] = key;
                break;
            }
            int larger = r < theSize && theArray[r] > theArray[l] ? r : l;
            theArray[j] = theArray[larger];
            j = larger;
        }
    }
}