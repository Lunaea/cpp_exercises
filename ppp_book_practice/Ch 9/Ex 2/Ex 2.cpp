#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string name{};
    std::string target{};
    
    std::cout << "Please enter a file name to search: ";
    std::cin >> name;

    std::ifstream ist{name};
    if (!ist)
        throw std::runtime_error("Couldn't open file " + name);

    std::cout << "Target word?: ";
    std::cin >> target;

    std::vector<std::string> lines{};

    for (std::string line; std::getline(ist, line);)
        lines.push_back(line);

    std::vector<int> found{};

    for (int i = 0; i < lines.size(); ++i) {
        if (lines[i].find(target) != std::string::npos)
            found.push_back(i);
    }

    if (!found.size()) {
        std::cout << "No hits!\n";
        return 0;
    }

    for (int hit : found)
        std::cout << "Line " << hit + 1 << ":\t" << lines[hit] << '\n';
    
    return 0;
}