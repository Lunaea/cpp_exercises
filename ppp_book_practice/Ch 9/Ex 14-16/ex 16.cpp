#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream ist{ "ints.txt" };
    std::vector<int> numbers{};

    for(int x; ist >> x;)
        numbers.push_back(x);

    int sum{};

    for(int i = 0; i < numbers.size(); ++i)
        sum += numbers[i];

    std::cout << "The sum of numbers is: " << sum << '\n';
    
    return 0;
}