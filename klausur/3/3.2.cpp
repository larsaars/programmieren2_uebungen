#include <iostream>

struct test {

    test() {}

    static void sth() {
        std::cout << "sth" << std::endl;
    }
};

int main() {
    test t;

    t.sth();

    test::sth();
}
