//
// Created by SooYeon Kim on 4/3/2018.
//

#include "complex.h"

ostream& operator<<(ostream &out, const Complex &c) {
    out << "C(" << c.real << ", " << c.imaginary << ")";
}

Complex::Complex(int real, int imaginary) :
        real{real}, imaginary{imaginary} {

}

Complex::Complex() :
        real{0}, imaginary{0} {

}

Complex Complex::operator+(const Complex &c) const {
    Complex result = *this;
    result += c;
    return result;
}

// a + bi * c * di
// (a * c) - (b * d) + (a * di) + (c * bi)
Complex Complex::operator*(const Complex &c) const {
    Complex result;
    result.real = (real * c.real) - (imaginary * c.imaginary);
    result.imaginary = (real * c.imaginary) + (c.real * imaginary);
    return result;
}

Complex& &Complex::operator+=(const Complex &c) {
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}