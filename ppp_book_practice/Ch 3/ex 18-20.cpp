#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names{};
    std::vector<double> scores{};
    std::string name{};
    double score{};
    bool isDupe{ false };

    std::cout << "Please enter name student pairs (NoName 0 when finished): ";
    while (std::cin >> name >> score) {
        if (name == "NoName" && score == 0)
            break;
        if (names.size() > 0) {
            for (auto student : names) {
                if (name == student) {
                    std::cout << "Duplicate name " << student << "!\n";
                    return 0;
                }
            }
        }
        names.push_back(name);
        scores.push_back(score);
    }

    /* ex 18
    for (int i{ 0 }; i < names.size(); ++i)
    std::cout << names[i] << '\t' << scores[i] << '\n';
    */

    /* ex 19
    std::cout << "Enter a name to find a score for: ";
    std::cin >> name;
    bool found { false };

    for (int i{ 0 }; i < names.size(); ++i) {
        if (name == names[i]) {
            std::cout << names[i] << '\t' << scores[i] << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "Name not found!\n";
    */

    std::cout << "Enter a score to find a name for: ";
    std::cin >> score;
    bool found { false };

    for (int i{ 0 }; i < names.size(); ++i) {
        if (score == scores[i]) {
            std::cout << names[i] << '\t' << scores[i] << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "Score not found!\n";

    return 0;
}