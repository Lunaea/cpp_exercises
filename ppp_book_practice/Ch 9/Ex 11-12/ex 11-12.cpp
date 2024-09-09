#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void reverseChars(const std::vector<std::string>& lines, std::vector<std::string>& reversed) {
    for(int i = lines.size() -1; i >= 0; --i) {
        std::string reverse{};
        for(int j = lines[i].length() - 1; j >= 0; --j) {
            reverse += lines[i][j];
        }
        reversed.push_back(reverse);
    }
}

int main() {
    std::ifstream ist{ "input.txt" };
    std::ofstream ost{ "output.txt" };

    std::vector<std::string> lines{};

    for(std::string line; std::getline(ist, line);)
        lines.push_back(line);

    std::vector<std::string> reversed{};

    reverseChars(lines, reversed);

    for(auto line : reversed)
        ost << line << '\n';

    return 0;
}