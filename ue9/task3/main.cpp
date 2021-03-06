#include <iostream>
#include "dynamic_array.h"
#include <string>

using std::string, std::cout, std::endl;

int main() {
    dynamic_array<string> arr(3);
    for (int i = 0; i < 3; ++i) {
        arr[i] = "test";
    }

    arr += dynamic_array<string>("Hi");

    cout << arr << endl;

    return 0;
}
