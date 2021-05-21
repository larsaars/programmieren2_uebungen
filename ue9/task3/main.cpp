#include <iostream>
#include "dynamic_array.h"
#include <string>

using std::string, std::cout, std::endl;

int main() {
    dynamic_array<string> arr("test");

    cout << arr << endl;

    return 0;
}
