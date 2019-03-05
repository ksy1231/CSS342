//
// Created by SooYeon Kim on 4/3/2018.
//

#ifndef OPERATOR_OVERLOADING_COMPLEX_H
#define OPERATOR_OVERLOADING_COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imaginary;
public:
    friend ostream& operator<<(ostream &out, const Complex &c);
    Complex();
    Complex(int real, int imaginary);
    Complex operator+(const Complex &c) const;
    Complex& operator+=(const Complex &c);
    Complex operator*(const Complex &c) const;
};

#endif //OPERATOR_OVERLOADING_COMPLEX_H
