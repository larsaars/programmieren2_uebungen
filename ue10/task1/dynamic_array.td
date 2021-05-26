#pragma once

#include <iostream>
#include "dynamic_array.h"
#include <ostream>

using std::move, std::endl, std::cerr, std::cout;

// operator to concatenate two dynamic_arrays:
// this array will be edited, the rhs will be copied
template<typename T>
dynamic_array<T> &dynamic_array<T>::operator+=(const dynamic_array<T> &rhs) {
    int newLen = len + rhs.len;
    // create new temporary array with new length
    T *temp = new T[newLen];

    // move lhs to newly allocated arrays
    for (int i = 0; i < len; i++)
        temp[i] = move(arr[i]);

    // copy rhs to new temp array
    for (int i = 0; i < rhs.len; i++)
        temp[i + len] = rhs.arr[i];

    // fix length attribute in this scope
    len = newLen;

    // delete empty pointer
    delete[] arr;
    // reset temp
    arr = temp;

    // return this scope
    return *this;
}


// aka the append function of the list
// add items of type T to list
template<typename T>
dynamic_array<T> &dynamic_array<T>::operator+=(const T &rhs) {
    *this += dynamic_array(rhs);
    // equal to: operator+=(this, dynamic_array(rhs));
    return *this;
}

// access T via index
template<typename T>
T &dynamic_array<T>::operator[](size_t index) {
    if (index < 0 || index >= len)
        cerr << "IndexOutOfBoundsException: " << index << " / " << len << endl;
    return arr[index];
}

// get index via T
template<typename T>
int dynamic_array<T>::operator[](const T &t) {
    for (int i = 0; i < len; ++i)
        if (t == arr[i])
            return i;
    return -1;
}

template<typename T>
void dynamic_array<T>::append(T &obj) {
    *this += obj;
}
