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

int main() {
    cout << avg(1, 2., 3., 4.) << endl;
    return 0;
}
