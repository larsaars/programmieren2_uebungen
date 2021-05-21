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

    dynamic_array(T arr0[]){
        arr = arr0;
        len = sizeof(arr) / sizeof(arr[0]);
    }

    ~dynamic_array() {
        delete[] arr;
    }

    T &operator[](size_t index);

    int operator[](const T &t);

    const dynamic_array &operator+=(const dynamic_array &rhs);

    const dynamic_array &operator+=(const T &rhs);

    friend std::ostream& operator<<(std::ostream &out, const dynamic_array<T> &t);
};

#endif //TASK3_DYNAMIC_ARRAY_H
