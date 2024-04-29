#include <iostream>
#include <cmath>

double discriminant(double a, double b, double c) {
    double x{ pow(b, 2) - 4 * a * c };
    if (x < 0)
        return -1;
    else
        return sqrt(x);
}

int main() {
    std::cout << "Please enter the coefficients a, b, and c of the quadratic ax^2+bx+c: ";
    double a{};
    double b{};
    double c{};
    std::cin >> a >> b >> c;
    
    if (a == 0 && b != 0) {
        std::cout << "The solution is x=" << -c / b << '\n';
        return 0;
    }

    if (discriminant(a, b, c) == -1)
        std::cout << "Quadratic has complex roots!\n";
    else
        std::cout << "The solutions are: x=" << (-b + discriminant(a, b, c)) / (2 * a)
                    << " and x=" << (-b - discriminant(a, b, c)) / (2 * a) << '\n';

    return 0;
}