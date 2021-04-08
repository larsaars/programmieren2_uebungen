#include "../pg2.h"

int* func() {
    int *d = (int*) malloc(3 * sizeof(int));
    for(int i = 0; i < 3; i++) {
        d[i] = 42;
    }

    return d;
}

int main(int argc, char **argv) {
    int *dptr = func();
    cout << "Hi" << endl;
    for(int i = 0; i < 3; i++) {
        cout << dptr[i] << endl;
    }

    free(dptr);
    return 0;
}
