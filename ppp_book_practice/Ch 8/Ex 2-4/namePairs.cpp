#include "namePairs.h"
#include <algorithm>
#include <iostream>

void NamePairs::readNames() {
    std::string name{};
    while (std::cin >> name) {
        if (name == ";")
            break;
        names.push_back(name);
    }
}

void NamePairs::readAges() {
    int age{};
    for (auto name : names) {
        std::cout << name << "'s age?: ";
        std::cin >> age;
        ages.push_back(age);
    }
}

void NamePairs::print() const {
    for (int i = 0; i < names.size(); ++i)
        std::cout << '(' << names[i] << ", " << ages[i] << ")\n";
}

void NamePairs::sort() {
    std::vector<std::string> namesOriginal{ names };

    std::sort(names.begin(), names.end());

    std::vector<double> agesSorted{};

    for (int i = 0; i < names.size(); ++i) {
        for (int j = 0; j <names.size(); ++j) {
            if (names[i] == namesOriginal[j])
                agesSorted.push_back(ages[j]);
        }
    }

    ages = agesSorted;
}