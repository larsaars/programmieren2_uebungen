#include <iostream>
#include "dynamic_array.h"
#include <ostream>

using std::move, std::endl, std::cerr, std::cout;

// operator to concatenate two dynamic_arrays:
// this array will be edited, the rhs will be copied
template<typename T>
const dynamic_array<T> &dynamic_array<T>::operator+=(const dynamic_array &rhs) {
    // fix length attribute in this scope
    len += rhs.len;
    // create new temporary array with new length
    T *temp = new T[len + rhs.len];

    // move lhs to newly allocated arrays
    for (int i = 0; i < len; i++)
        temp[i] = move(arr[i]);

    // copy rhs to new temp array
    for (int i = 0; i < rhs.len; i++)
        temp[i + len] = rhs.arr[i];

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
const dynamic_array<T> &dynamic_array<T>::operator+=(const T &rhs) {
    this += dynamic_array(rhs);
    return *this;
}


// print out list
template<typename T>
std::ostream& operator<<(std::ostream &out, const dynamic_array<T> &rhs) {
    out << "[";
    for (int i = 0; i < rhs.len; i++) {
        if (i != 0)
            out << ", ";
        out << rhs.arr[i];
    }
    out << "]";
    return out;
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
