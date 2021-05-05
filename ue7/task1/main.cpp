#include <iostream>
#include "complex_number.h"

int main() {
    complex_number c(0, 2);
    complex_number d(0, 3);

    std::cout << (c * d);

    return 0;
}
