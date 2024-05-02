#include <iostream>
#include <vector>

class Too_many {};
class Too_few {};

int sum(std::vector<int>& v, int count) {
    int total{};
    for (int i{0}; i < count; ++i)
        total += v[i];
    return total;
}

void print(std::vector<int>& v, int count) {
    for (int i{0}; i < count; ++i)
        std::cout << v[i] << ' ';
}

int main()
try {
    std::vector<int> input{};
    
    std::cout << "Please enter the number of values you want to sum: ";
    int count{};
    std::cin >> count;

    if (count < 0)
        throw Too_few{};

    std::cout << "Please enter some integers (press '|' to stop): ";
    int in{};
    while (std::cin >> in) {
        input.push_back(in);
    }

    if (count > input.size())
        throw Too_many{};

    std::cout << "The sum of the first " << count << " numbers ( ";
    print(input, count);
    std::cout << ") is " << sum(input, count) << '\n';

    return 0;
}
catch (Too_few) {
    std::cerr << "Sum count less than 0!\n";
    return 1;
}
catch (Too_many) {
    std::cerr << "Sum count more than input count!\n";
    return 2;
}