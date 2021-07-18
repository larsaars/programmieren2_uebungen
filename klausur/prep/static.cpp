#include <iostream>

using namespace std;

struct A  {
    int i;
    static int b;

    static void bla() {
        b++;
    }

    A(const A &other) = delete;
}

void dos() {
    static int i = 0;
    i++;
    cout << i << endl;
}

void main() {
//     A::b = 3;
//     A a;
//     a.b = 5;
//     A c;
//     A::b;
    A::bla();
    
    dos();
    dos();
    dos();

    A a;
    A b = a;

}
