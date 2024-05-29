#include "rational.h"
#include <iostream>

int main() {
    Rational a{ 4, 8 };
    Rational b{ 4, 5 };

    a = b;

    std::cout << a + b << '\n';
    std::cout << a - b << '\n';
    std::cout << a * b << '\n';
    std::cout << a / b << '\n';
    std::cout << toDouble(a) << '\n';
    std::cout << toDouble(b) << '\n';
    std::cout << (a == b) << '\n';
    std::cout << (a != b) << '\n';

    return 0;
}