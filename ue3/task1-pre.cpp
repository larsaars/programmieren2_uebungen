#include "../pg2.h"

const double E = exp(1.0);

float function(float x) { return pow(E, x); }

float integrate(float (*func)(float), float a, float b, float N) {
    float pre = (b - a) / N;
    float sum = 0;
    for (int i = 0; i < N; i++) {
        float xi = a + (((b - a) * i) / (N - 1));
        sum += func(xi);
    }
    return pre * sum;
}

int main(int argc, char **argv) {
    float N = 20;
    cout << integrate(&function, -8, 5, N) << endl;
}
