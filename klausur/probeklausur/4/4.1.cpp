#include <iostream>

using namespace std;

struct A {
    virtual void a() {
        cout << "from A" << endl;
    }

//     virtual void b() = 0;
};

struct B : A {
    void a() override {
        cout << "from B" << endl;
    }

//     void b() override { cout << "B from B" << endl; }
};

struct C : B {
    void a() override {
        cout << "from C" << endl;
    }
};

int main() {
    C c;
    A *a = &c;
    a->a();
//     a.b();

//     A a0;
//     a0.b();
    return 0;
}
