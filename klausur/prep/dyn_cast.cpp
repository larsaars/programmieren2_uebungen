#include <iostream>

using namespace std;

class B { };
class C : public B {
public:
    int a = 1;

    void b() {
        cout << "from c" << endl;
    }
};
class D : public C { };

void f(D* pd) {
   C* pc = dynamic_cast<C*>(pd);   // ok: C is a direct base class
                                   // pc points to C subobject of pd
   B* pb = dynamic_cast<B*>(pd);   // ok: B is an indirect base class
                                   // pb points to B subobject of pd
}

int main() {
    D d;
    C *c = dynamic_cast<C*>(&d);
    c->b();
    f(&d);
    return 0;
}
