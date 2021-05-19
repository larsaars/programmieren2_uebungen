#include "dynamic_array.h"

using std::move;

template<typename T> const dynamic_array<T> &dynamic_array<T>::operator+=(const dynamic_array &rhs) {
    auto *temp = new T[len + rhs.len];

    for(int i = 0; i < len; i++)
        temp[i] = move(arr[i]);

    for(int i = 0; i < rhs.len; i++)
        temp[i + len] = rhs.arr[i];

    len += rhs.len;

    delete [] arr;
    arr = temp;

    return *this;
}
