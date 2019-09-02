#include <iostream>

using namespace std;

class Complex {
public:
    Complex() = default;
    
    explicit Complex(double real, double imaginary = 0.0) noexcept 
        : re(real)
        , im(imaginary) 
    {}
    
    Complex(const Complex& other)
        : re(other.re)
        , im(other.im)
    {}

    Complex add(const Complex& other) const noexcept {
        return Complex{ this->re + other.re, this->im + other.im };
    }

    Complex sub(const Complex& other) const noexcept {
        return this->add(Complex{ -other.re, -other.im });
    }

    Complex mul(const Complex& other) const noexcept {
        return Complex {
            this->re * other.re - this->im * other.im, 
            this->re * other.im + this->im * other.re
        };
    }

    Complex div(const Complex& other) const noexcept {
        double denominator = other.mul(other.conj()).re;
        Complex numerator = this->mul(other.conj());
        return Complex{ numerator.re / denominator, numerator.im / denominator };
    }

    bool equ(const Complex& other) const noexcept {
        return (this->re == other.re) && (this->im == other.im);
    }

    Complex conj() const noexcept {
        return Complex{ this->re, -this->im };
    }

    double mod() const noexcept {
        return this->mul(this->conj()).re;
    }

private:
    double re, im;
};

int main() {

}
