#include <iostream>
#include "complex_number.h"

std::ostream &operator<<(std::ostream &os, const complex_number &c) {
    os << c.real << " + " << c.imag << 'i' << std::endl;
    return os;
}

complex_number &complex_number::operator*=(const complex_number &c) {
    double buffer = real;
    real = real * c.real - imag * c.imag;
    imag = buffer * c.imag + c.real * imag;
    return *this;
}

complex_number &complex_number::operator/=(const complex_number &c) {
    double bufferReal = real;
    double bufferImag = imag;
    real = (bufferReal * c.real + bufferImag * c.imag) / (c.real * c.real + c.imag * c.imag);
    imag = (c.real * bufferImag - bufferReal * c.imag) / (c.real * c.real + c.imag * c.imag);
    return *this;
}

complex_number &complex_number::operator+=(const complex_number &c) {
    imag += c.imag;
    real += c.real;
    return *this;
}

complex_number &complex_number::operator-=(const complex_number &c) {
    imag -= c.imag;
    real -= c.real;
    return *this;
}

complex_number operator*(const complex_number &lhs, const complex_number &rhs) {
    complex_number temp = lhs;
    temp *= rhs;
    return temp;
}

complex_number operator/(const complex_number &lhs, const complex_number &rhs) {
    complex_number temp = lhs;
    temp /= lhs;
    return temp;
}

complex_number operator+(const complex_number &lhs, const complex_number &rhs) {
    complex_number temp = lhs;
    temp += rhs;
    return temp;
}

complex_number operator-(const complex_number &lhs, const complex_number &rhs) {
    complex_number temp = lhs;
    temp -= rhs;
    return temp;
}
