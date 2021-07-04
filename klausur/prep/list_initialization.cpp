#include <iostream>

using namespace std;

struct A  {
    int i1, i2, i3;

    void print() {
        cout << i1 << ", " << i2 << ", " << i3 << endl;
    }
};

int main() {
    A a{1, 2, 3};
    a.print();
}
