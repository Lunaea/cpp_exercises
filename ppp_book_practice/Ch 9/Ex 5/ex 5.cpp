#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void makeOut(char x, std::ostringstream& out) {
    out << x << " is: ";
    if (isspace(x)) {
        out << "whitespace\n";
        return;
    }

    if (isalpha(x)) {
        out << "a letter\n";
        return;
    }

    if (isdigit(x)) {
        out << "a number\n";
        return;
    }

}

int main() {
    std::vector<std::string> lines{};

    std::cout << "Please enter some strings: ";

    for (std::string line; std::getline(std::cin, line);)
        lines.push_back(line);

    for (auto line : lines){
        for (int i = 0; i < line.size(); ++i) {
            std::ostringstream out{};
            makeOut(line[i], out);
            std::cout << out.str();
        }
        std::cout << '\n';
    }
}