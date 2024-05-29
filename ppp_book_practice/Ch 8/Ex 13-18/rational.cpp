#include "rational.h"

Rational reciprocal(const Rational& a) {
    return Rational{ a.getDenominator(), a.getNumerator() };
}

Rational operator+(const Rational& a, const Rational& b) {
    if (a.denominator == b.denominator)
        return Rational{ (a.numerator + b.numerator), a.denominator };

    int numerator{ (a.numerator * b.denominator) + (b.numerator * a.denominator) };
    int denominator{ a.denominator * b.denominator };
    return Rational{ numerator, denominator };
}

Rational operator-(const Rational& a, const Rational& b) {
    if (a.denominator == b.denominator)
        return Rational{ (a.numerator - b.numerator), a.denominator };

    int numerator{ (a.numerator * b.denominator) - (b.numerator * a.denominator) };
    int denominator{ a.denominator * b.denominator };
    return Rational{ numerator, denominator };
}

Rational operator*(const Rational& a, const Rational& b) {
    return Rational{ (a.numerator * b.numerator), (a.denominator * b.denominator ) };
}

Rational operator/(const Rational& a, const Rational& b) {
    return{ a * reciprocal(b) };
}

bool operator==(const Rational& a, const Rational& b) {
    return (a.numerator == b.numerator) && (a.denominator == b.denominator);
}

bool operator!=(const Rational& a, const Rational& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& o, const Rational& a) {
    return o << a.numerator << '/' << a.denominator;
}

Rational Rational::operator=(const Rational& a) {
    if (this == &a)
        return *this;

    this -> numerator = a.numerator;
    this -> denominator = a.denominator;

    return *this;
}

double toDouble(const Rational& a) {
    return (double)a.getNumerator() / a.getDenominator();
}