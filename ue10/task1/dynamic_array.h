#ifndef TASK3_DYNAMIC_ARRAY_H
#define TASK3_DYNAMIC_ARRAY_H

#include <ostream>
#include <string>


template<typename T>
class dynamic_array {
private:
    T *arr;
    int len;

public:
    dynamic_array() : len(0), arr(nullptr) {}

    dynamic_array(int size) : len(size) {
        arr = new T[size];
    }

    dynamic_array(const T &t) : dynamic_array(1) {
        arr[0] = t;
    }

    dynamic_array(T arr0[]) {
        arr = arr0;
        len = sizeof(arr) / sizeof(arr[0]);
    }

    // copy constructor
    dynamic_array(const dynamic_array &og) : dynamic_array(og.len) {
        for (int i = 0; i < og.len; i++)
            arr[i] = og.arr[i];
    }

    // move constructor
    dynamic_array(dynamic_array &&src) : len(src.len), arr(src.arr) {
        src.arr = nullptr;
    }

    // destructor
    ~dynamic_array() {
        delete[] arr;
    }

    T &operator[](size_t);

    int operator[](const T &);

    dynamic_array &operator+=(const dynamic_array &);

    dynamic_array &operator+=(const T &);

    friend std::ostream &operator<<(std::ostream &out, const dynamic_array &rhs) {
        out << "[";
        for (int i = 0; i < rhs.len; i++) {
            if (i != 0)
                out << ", ";
            out << rhs.arr[i];
        }
        out << "]";
        return out;

    }

    int size() { return len; }

    void append(T &);
};

#include "dynamic_array.td"

#endif