#include <iostream>
#include <memory>

void h (std::unique_ptr<int> x) {
    std::cout << "h_up = " << *x << std::endl;
}

int main() {
    std::unique_ptr<int> up = std::make_unique<int>(4);
    h(std::move(up));
    *up = 20;
    std::cout << "up = " << *up << std::endl;
    return 0;
}
