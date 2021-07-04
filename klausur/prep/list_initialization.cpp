#include <iostream>
#include <string>

using namespace std;

struct A  {
    int i1, i2, i3;
    string s;

//     A() {}
//     A(int i1, int i2) : i1(i1), i2(i2) {}

//     A(initializer_list<int> &&init) {}

    void print() {
        cout << i1 << ", " << i2 << ", " << i3 << ", " << s << endl;
    }
};

int main() {
    A a{1, 2, 3, "test"};
//     A a{1, 2};
    a.print();
}
