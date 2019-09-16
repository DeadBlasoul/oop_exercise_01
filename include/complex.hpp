#pragma once

#include <cmath>
#include <string>
#include <sstream>
#include <ostream>

class Complex;

class Complex {
public:
    inline Complex() noexcept
        : re{}
        , im{}
    {}

    inline explicit Complex(double real, double imaginary) noexcept
        : re{ real }
        , im{ imaginary }
    {}

    inline Complex(const Complex& other) noexcept
        : re(other.re)
        , im(other.im)
    {}


    inline double& Real() noexcept { return re; }
    inline double& Imag() noexcept { return im; }
    inline const double& Real() const noexcept { return re; }
    inline const double& Imag() const noexcept { return im; }

    inline Complex Add(const Complex& other) const noexcept {
        return Complex{ this->re + other.re, this->im + other.im };
    }

    inline Complex Sub(const Complex& other) const noexcept {
        return this->Add(Complex{ -other.re, -other.im });
    }

    inline Complex Mul(const Complex& other) const noexcept {
        return Complex{
            this->re * other.re - this->im * other.im,
            this->re * other.im + this->im * other.re
        };
    }

    inline Complex Div(const Complex& other) const noexcept {
        double denominator = other.Mul(other.Conj()).re;
        Complex numerator = this->Mul(other.Conj());
        return Complex{ numerator.re / denominator, numerator.im / denominator };
    }

    inline bool Equ(const Complex& other) const noexcept {
        return (this->re == other.re) && (this->im == other.im);
    }

    inline Complex Conj() const noexcept {
        return Complex{ this->re, -this->im };
    }
    
    inline double Mod() const noexcept {
        return std::sqrt(this->Mul(this->Conj()).re);
    }

    inline std::string Str() const {
        std::stringstream string;
        Write(string);
        return string.str();
    }

    // IO methods
    void Read(std::istream& stream);
    void Write(std::ostream& stream) const;

private:
    double re, im;
};

int Compare(const Complex& left, const Complex& right);
