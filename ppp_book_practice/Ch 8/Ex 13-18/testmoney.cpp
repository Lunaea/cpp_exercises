#include "money.h"
#include <iostream>

int main() {
    Money test{};

    std::cout << "Please enter an amount (ex: USD1.23): ";
    std::cin >> test;
    std::cout << test.getTotal() << '\n';
    std::cout << test.getDollars() << '\n';
    std::cout << test.getCents() << '\n';
    std::cout << test << '\n';

    return 0;
}