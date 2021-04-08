#include "../pg2.h"

float function(float x) { return sin(x) * cos(x); }

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
    ofstream plotfile("plot.txt");
    for (int N = 1; N < 300; N++) {
        plotfile << N << " " << (0.5 - integrate(&function, 0, M_PI / 2, N)) << endl;
    }
    plotfile.close();
}
