#include <iostream>

int main() {
    double in1, in2;
    char op{};
    std::cout << "Please enter 2 numbers and an operator (+,-,*,/): ";
    std::cin >> in1 >> in2 >> op;

    switch (op) {
        case '+':
            std::cout << "The sum of " << in1 << " and " << in2 << " is " << in1 + in2 << '\n';
            break;
        case '-':
            std::cout << "The difference of " << in1 << " and " << in2 << " is " << in1 - in2 << '\n';
            break;
        case '*':
            std::cout << "The product of " << in1 << " and " << in2 << " is " << in1 * in2 << '\n';
            break;
        case '/':
            std::cout << "The quotient of " << in1 << " and " << in2 << " is " << in1 / in2 << '\n';
            break;
        default:
            std::cout << "Invalid operator!\n";
            break;
    }

    return 0;
}