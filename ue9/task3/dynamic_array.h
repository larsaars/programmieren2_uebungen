#ifndef TASK3_DYNAMIC_ARRAY_H
#define TASK3_DYNAMIC_ARRAY_H


#include <string>

using std::string;

template<typename T> class dynamic_array {
private:
    T *arr;
    int len;

public:
    dynamic_array() : len(0), arr(nullptr) {}

    dynamic_array(int size) : len(size) {
        arr = new string[size];
    }

    ~dynamic_array() {
        delete[] arr;
    }

    const dynamic_array &operator+=(const dynamic_array &rhs);
};

#endif //TASK3_DYNAMIC_ARRAY_H
