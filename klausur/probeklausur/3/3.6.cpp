#include <iostream>

using namespace std;

struct A {
private:
    int i = 0;

public:
    A(int i) : i(i) {}

    bool operator==(const A &other) {
        return other.i == i;
    }
};

int main() {
    A a1(1);
    A a2{1};

    if(a1 == a2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
