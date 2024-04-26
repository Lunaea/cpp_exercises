#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> digits{ "zero", "one", "two", "three", "four",
                                     "five", "six", "seven", "eight", "nine" };

int getNumber(std::istream& in) {
    int num{};
    std::string number{};
    if (in >> num)
        return num;
    else {
        in.clear();
        in >> number;
        for (int i{0}; i < digits.size(); ++i) {
            if (digits[i] == number)
                return i;
        }
    }
    return -1;
}

int main() {
    int in1, in2;
    char op{};
    std::cout << "Please enter 2 numbers 0-10, as words or digits, and an operator (+,-,*,/): ";
    in1 = getNumber(std::cin);
    in2 = getNumber(std::cin);
    std::cin >> op;

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