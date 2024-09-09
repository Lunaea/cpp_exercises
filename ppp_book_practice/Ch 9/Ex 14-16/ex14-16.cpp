#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

int main() {
    std::ifstream ist{ "input.txt" };
    std::ofstream ost{ "output.txt" };
    std::vector<double> numbers{};

    for(double x; ist >> x;)
        numbers.push_back(x);

    for(int i = 1; i < numbers.size() + 1; ++i) {
        ost << std::scientific 
            << std::setprecision(8) 
            << std::setw(20)
            << numbers[i - 1] << '\t';

        if((i % 4) == 0)
            ost << '\n';
    }

    return 0;
}