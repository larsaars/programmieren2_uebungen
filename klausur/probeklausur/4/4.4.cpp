#include <iostream>
#include <string>

using namespace std;

struct A {
    A() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~A() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};


struct B : A {

    B() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~B() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};


struct C : B {

    C() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~C() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void do_sth() {
        cout << "called do sth" << endl;
    }
};


struct D : C {

    D() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~D() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

int main() {
    C c; 
    c.do_sth();
}

