#include <iostream>
#include <string>
#include <vector>

int main() {
    const std::vector<std::string> digits{ "zero", "one", "two", "three", "four",
                                     "five", "six", "seven", "eight", "nine" };

    int num{};
    std::string number{};
    std::cout << "Please enter a number 0-10 as a digit or word: ";

    while(std::cin) {
        std::cin >> num;
        if (std::cin)
            std::cout << num << " is " << digits[num] << '\n';
        else {
            std::cin.clear();
            std::cin >> number;
            for (int i{0}; i < digits.size(); ++i) {
                if (digits[i] == number) {
                    std::cout << number << " is " << i << '\n';
                    break;
                }
            }
        }

    }

    return 0;
}