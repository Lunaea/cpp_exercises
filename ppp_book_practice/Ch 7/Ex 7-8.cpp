#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Please enter some names: ";

    std::vector<std::string> name{};
    std::string in{};
    while (std::cin >> in) {
        if (in == ";")
            break;

        name.push_back(in);
    }

    std::cout << "Please enter the associated ages: ";

    std::vector<int> age{};
    int x{};
    while (std::cin >> x)
        age.push_back(x);

    if (name.size() != age.size()) {
        std::cerr << "Size mismatch!\n";
        return 1;
    }

    for (int i = 0; i < name.size(); ++i)
        std::cout << '(' << name[i] << ", " << age[i] << ")\n";

    std::vector<std::string> nameOriginal{ name };

    std::sort(name.begin(), name.end());

    std::vector<int> ageSorted{};

    for (int i = 0; i < name.size(); ++i) {
        for (int j = 0; j < name.size(); ++j) {
            if (name[i] == nameOriginal[j])
                ageSorted.push_back(age[j]);
        }
    }

    for (int i = 0; i < name.size(); ++i)
        std::cout << '(' << name[i] << ", " << ageSorted[i] << ")\n";

    return 0;
}