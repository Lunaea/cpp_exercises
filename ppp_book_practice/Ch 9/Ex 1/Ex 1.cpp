#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int main() {
    std::cout << "Please enter an input file name *.txt: ";

    std::string name{};
    std::cin >> name;

    std::ifstream ist{name};
    if (!ist)
        throw std::runtime_error("Couldn't open file " + name);

    std::cout << "Please enter an output file name *.txt: ";

    std::cin >> name;

    std::ofstream ost{name};
    if (!ost)
        throw std::runtime_error("Couldn't open file " + name);

    for (char ch; ist.get(ch);) {
        char x{};
        if (std::isalpha(ch)) {
            x = std::tolower(ch);
            ost << x;
        }
        if (std::isspace(ch))
            ost << ch;
        
    }
    
    return 0;
}