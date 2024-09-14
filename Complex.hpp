//omer shahar
//207689621
//omerzshahar@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Getters for real and imaginary parts
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Overload the output operator for printing
    friend std::ostream& operator<<(std::ostream &os, const Complex &c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
    
    // Overload equality operator with epsilon for floating-point comparison
    bool operator==(const Complex &other) const {
        const double epsilon = 1e-6;
        return (std::abs(real - other.real) < epsilon) && (std::abs(imag - other.imag) < epsilon);
    }
};

#endif // COMPLEX_HPP
