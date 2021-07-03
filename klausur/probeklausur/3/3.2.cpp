#include <iostream>

struct test {

    int i;
    static int o;
    
    test() = default;

    static void sth() {
        std::cout << "sth" << std::endl;
        o = 2;
    }
};

void whatever() {
    static int counter = 0;
    counter++;
    std::cout << counter << std::endl;
}

int main() {
    test t;

    t.sth();

    test::sth();

    test::o = 2;

    whatever();
    whatever();
}
