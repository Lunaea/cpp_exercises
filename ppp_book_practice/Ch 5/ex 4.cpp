#include "../PPPheaders.h"

class Name_value {
public:
    Name_value(string name, double score)
        : name{ name }, score{ score } {}
    string getName() { return name; }
    double getScore() { return score; }

private:
    string name{};
    double score{};
};

int main() {
    vector<Name_value> scores{};
    string name{};
    double score{};
    bool isDupe{ false };

    std::cout << "Please enter name student pairs (NoName 0 when finished): ";
    while (std::cin >> name >> score) {
        if (name == "NoName" && score == 0)
            break;
        if (scores.size() > 0) {
            for (auto student : scores) {
                if (student.getName() == name) {
                    std::cout << "Duplicate name " << student.getName() << "!\n";
                    return 0;
                }
            }
        }
        scores.push_back(Name_value(name, score));
    }

    /* ex 18
    for (int i{ 0 }; i < scoress.size(); ++i)
    std::cout << scores[i].getName() << '\t' << scores[i].getScore() << '\n';
    */

    /* ex 19
    std::cout << "Enter a name to find a score for: ";
    std::cin >> name;
    bool found { false };

    for (int i{ 0 }; i < names.size(); ++i) {
        if (name == scores[i].getName()) {
            std::cout << scores[i].getName() << '\t' << scores[i].getScore() << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "Name not found!\n";
    */

    std::cout << "Enter a score to find a name for: ";
    std::cin >> score;
    bool found { false };

    for (int i{ 0 }; i < scores.size(); ++i) {
        if (score == scores[i].getScore()) {
            std::cout << scores[i].getName() << '\t' << scores[i].getScore() << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "Score not found!\n";

    return 0;
}