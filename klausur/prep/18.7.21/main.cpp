#include <iostream>
#include <cstdarg>

using namespace std;

double avg(int count, ...) {
    va_list ap;
    double total = 0;

    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        double d = va_arg(ap, double);
        cout << d << endl;
        total += d;
    }
    va_end(ap);

    return total / count;
}

struct A {
    virtual void a() = 0;
};

struct B : A {
    void a() override {}
};

int main() {
    // cout << avg(1, 2., 3., 4.) << endl;
    int *i1 = new int[3];
    int *i2 = (int *) malloc(sizeof(int) * 3);

    int ii = static_cast<int>(3.3);

    auto aB = new B;

    // back to c
    // B *back = dynamic_cast<B*>(&aB);



    return 0;
}
