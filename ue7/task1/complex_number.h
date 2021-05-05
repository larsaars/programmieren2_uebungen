#ifndef TASK1_COMPLEX_NUMBER_H
#define TASK1_COMPLEX_NUMBER_H

class complex_number {
    double real, imag;

public:
    // Konstruktor
    complex_number(double real, double imag) : real(real), imag(imag) {}

    complex_number(double real) : complex_number(real, 0) {}

    //Funktion zum Auslesen des Imaginärteils und Realteils
    friend std::ostream &operator<<(std::ostream &os, const complex_number &c);

    complex_number &operator*=(const complex_number &c);

    complex_number &operator+=(const complex_number &c);

    complex_number &operator-=(const complex_number &c);

    complex_number &operator/=(const complex_number &c);

    double abs();
};

complex_number operator*(const complex_number &lhs, const complex_number &rhs);

complex_number operator/(const complex_number &lhs, const complex_number &rhs);

complex_number operator+(const complex_number &lhs, const complex_number &rhs);

complex_number operator-(const complex_number &lhs, const complex_number &rhs);


#endif //TASK1_COMPLEX_NUMBER_H
