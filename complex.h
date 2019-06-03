#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
    double a;
    double b;

    double ro;
    double theta;
public:
    Complex(const double &a = 0, const double &b = 0, const bool &polaire = false);

    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    bool operator==(const Complex &c);

    void display(std::ostream &stream);
};

#endif // COMPLEX_H
