#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main() {
    std::ifstream ist{ "ints.txt" };
    std::ofstream ost{ "output.txt" };

    std::vector<int> numbers{};
    std::vector<int> seen{};
    std::vector<int> count{};

    for(int x; ist >> x;)
        numbers.push_back(x);

    std::sort(numbers.begin(), numbers.end());

    seen.push_back(numbers[0]);
    count.push_back(0);

    int j = 0;

    for(int i = 0; i < numbers.size(); ++i) {
        if(numbers[i] == seen[j])
            ++count[j];
        else {
            seen.push_back(numbers[i]);
            count.push_back(1);
            ++j;
        }
    }

    for(int i = 0; i < seen.size(); ++i) {
        ost << seen[i];

        if(count[i] > 1)
            ost << "\t" << count[i] << '\n';
        else
            ost << '\n';
    }

    return 0;
}