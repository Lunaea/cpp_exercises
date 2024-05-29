#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
    class BadFraction {};

    Rational() {}
    Rational(int x, int y): numerator{ x }, denominator{ y }
    {
        if (denominator == 0)
            throw BadFraction{};
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Rational operator=(const Rational& a);
    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator-(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator/(const Rational& a, const Rational& b);
    friend bool operator==(const Rational& a, const Rational& b);
    friend bool operator!=(const Rational& a, const Rational& b);
    friend std::ostream& operator<<(std::ostream& o, const Rational& a);

private:
    int numerator{};
    int denominator{ 1 };
};

double toDouble(const Rational& a);
Rational reciprocal(const Rational& a);

#endif