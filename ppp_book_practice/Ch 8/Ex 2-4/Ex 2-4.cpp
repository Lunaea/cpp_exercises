#include "namePairs.h"
#include <iostream>

int main() {
    NamePairs test{};

    std::cout << "Please enter some names (; to stop): ";
    test.readNames();
    test.readAges();

    NamePairs test2{ test };

    test.sort();

    NamePairs test3{ test };

    std::cout << test << "\n\n" << test2 << "\n\n" << test3;

    if ( test != test2)
        std::cout << "yay\n";
    else
        std::cout << "boo\n";

    return 0;
}