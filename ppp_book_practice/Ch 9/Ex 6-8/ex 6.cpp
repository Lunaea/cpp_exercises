#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const std::vector<char> punct{ '.', ';', ',', '?', '-', '\'' };

bool ispunct(char c) {
    char x = tolower(c);

    for (char v : punct)
        if (x == v)
            return true;

    return false;
}

int main() {
    std::string name{};
    std::cout << "Please enter a file name: ";
    std::getline(std::cin, name);

    std::ifstream ifs{name};
    if(!ifs)
        throw std::runtime_error("Unable to open file " + name);

    std::ofstream ofs{"output.txt"};

    std::vector<std::string> lines{};
    for (std::string line; std::getline(ifs, line);)
        lines.push_back(line);

    for (int i = 0; i < lines.size(); ++i) {
        for (int j = 0; j < lines[i].size(); ++j) {
            if (ispunct(lines[i][j])) {
                lines[i].replace(j, 1, " ");
                --j;    //decrement j to account for now removed vowel
            }
        }
    }

    for (auto line : lines)
        ofs << line << '\n';

    return 0;
}