#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int in{};
    std::vector<int> numbers{};
    std::cout << "Please enter some numbers: ";
    while (std::cin >> in) {
        numbers.push_back(in);
    }
    if (numbers.size() == 0) {
        std::cout << "No input!\n";
        return 0;
    }
    std::sort(numbers.begin(), numbers.end());

    int modeCount{ 1 };
    int tempNumber{ numbers[0] };
    int mode{ numbers[0] };
    int count{ 1 };

    for (int i{ 1 }; i < numbers.size(); ++i) {
        if (numbers[i] == tempNumber) {
            ++count;
            if (count > modeCount) {
                modeCount = count;
                mode = tempNumber;
            }
        }
        else {
            tempNumber = numbers[i];
            count = 1;
        }
    }

    std::cout << "The sorted numbers are:\n";
    for(int num : numbers)
        std::cout << num << ' ';
    std::cout << '\n';
    std::cout << "The mode is: " << mode << " with " << modeCount << " occurences!\n";
    
    return 0;
}