#include "namePairs.h"
#include <iostream>

int main() {
    NamePairs test{};

    std::cout << "Please enter some names (; to stop): ";
    test.readNames();
    test.readAges();
    test.sort();
    test.print();

    return 0;
}