#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "calc.h"

using namespace std;


int main(int argc, char **argv) {
    if(argc != 4) {
        cout << "Missing arguments!" << endl;
        return -1;
    }

    int i1 = atoi(argv[1]);
    int i2 = atoi(argv[3]);
    char op = argv[2][0];

    cout << math::calc(op, i1, i2) << endl;

    return 0;
}

