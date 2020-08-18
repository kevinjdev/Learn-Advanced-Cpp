#include <iostream>

using namespace std;

class Complex {

private:
    double real;
    double imaginary;

public:
    Complex() : real(0), imaginary (0) {}
    
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}
    
    Complex(const Complex &other) {
        // cout << "Copy" << endl;
        real = other.real;
        imaginary = other.imaginary;
    }

    const Complex &operator=(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    }

    double getReal() const{ 
        return real; 
    }
    double getImaginary() const{ 
        return imaginary; 
    }

    bool operator==(const Complex &other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    bool operator!=(const Complex &other) const {
        return !(*this==other);
    }

    Complex operator*() const {
        return Complex(real, -imaginary);
    }
};

ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.getReal() << "," << c.getImaginary() << ")";
    return out;
}

// Freestanding. No need for friend or member function.
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex& c1, double d) {
    return Complex(c1.getReal() + d, c1.getImaginary());
}

Complex operator+(double d, const Complex& c1) {
    return Complex(c1.getReal() + d, c1.getImaginary());
}

int main() {
    
    Complex c1(2, 3);
    Complex c2 = c1;

    cout << c1 << endl << c2 << endl;

    Complex c3(1,1);

    Complex c4 = c1 + c3;

    cout << "c4 = " << c4 << endl;

    // Complex c5 = c4 + 7;
    Complex c5 = 6 + c4;
    cout << "c5 = " << c5 << endl;

    if (c1 == c2) {
        cout << "c1 == c2 is true" << endl;
    }
    else {
        cout << "c1 == c2 is false" << endl;
    }

    if (c1 != c2) {
        cout << "c1 != c2 is true" << endl;
    }
    else {
        cout << "c1 != c2 is false" << endl;
    }

    cout << *c1 << endl;

    return 0;
}