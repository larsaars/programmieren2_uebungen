#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace math {

bool valid_op(char op) {
    return op == '+' || op == '*' || op == '/' || op == '-';
}

int calc(char op, int i1, int i2) {
    if (!valid_op(op)) {
        cerr << "Invalid operator!" << endl;
        return 0;
    }

    int out = 0;

    switch (op) {
    case '+':
        out = i1 + i2;
        break;
    case '-':
        out = i1 - i2;
        break;
    case '*':
        out = i1 * i2;
        break;
    case '/':
        out = i1 / i2;
        break;
    default:
        break;
    }

    return out;
}

} // namespace math

