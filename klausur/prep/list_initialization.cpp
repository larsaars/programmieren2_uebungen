#include <iostream>
#include <string>

using namespace std;

struct A  {
    int i1, i2, i3;
    string s;

    void print() {
        cout << i1 << ", " << i2 << ", " << i3 << ", " << s << endl;
    }
};

int main() {
    A a{1, 2, 3, "test"};
    a.print();
}
