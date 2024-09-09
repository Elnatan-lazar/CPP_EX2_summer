// mail:elnatan100@gmail.com
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <cmath>

/**
 * @class Complex
 * A class to represent complex numbers and perform basic operations.
 */
class Complex
{
private:
    double real; // The real part of the complex number.
    double imag; // The imaginary part of the complex number.

public:
    // Constructor to initialize a complex number with given real and imaginary parts.
    Complex(double r, double i) : real(r), imag(i) {}

    // Getter for the real part of the complex number.
    double get_real() const { return real; }

    // Getter for the imaginary part of the complex number.
    double get_imag() const { return imag; }

    // Overloaded insertion operator to print the complex number.
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        if (c.imag >= 0)
        {
            os << c.real << "+" << c.imag << "i";
        }
        else
        {
            os << c.real << " " << c.imag << "i";
        }
        return os;
    }

    // Equality operator to compare two complex numbers.
    bool operator==(const Complex &c) const
    {
        return real == c.real && imag == c.imag;
    }

    // Greater-than and smaller-than operator to compare two complex numbers.
    // note This operator is used to sort complex numbers in a heap iterator.
    bool operator>(const Complex &c) const
    {
        return real > c.real && imag > c.imag;
    }

    bool operator<(const Complex &c) const
    {
        return real < c.real && imag < c.imag;
    }
};

#endif