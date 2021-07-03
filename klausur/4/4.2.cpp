#include <iostream>

using namespace std;

struct A {
    virtual void a() = 0;
};

struct B : A  {
    void a() override {
        cout << "endl" << endl;
    }
};

int main() {
    B b;
    b.a();
    return 0;
}
