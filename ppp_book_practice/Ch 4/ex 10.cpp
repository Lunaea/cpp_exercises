#include <iostream>
#include <vector>

class Too_many {};
class Too_few {};
class Too_small {};

int sum(std::vector<double>& v, int count) {
    int total{};
    for (int i{0}; i < count; ++i)
        total += v[i];
    return total;
}

void print(std::vector<double>& v, int count) {
    for (int i{0}; i < count; ++i)
        std::cout << v[i] << ' ';
}

void diffCalc(std::vector<double>& in, std::vector<double>& diff) {
    if (in.size() < 2)
        throw Too_small {};
    for (int i{0}; i < in.size() - 1; ++i)
        diff.push_back(in[i] - in[i + 1]);
}
int main()
try {
    std::vector<double> input{};
    std::vector<double> differences{};

    std::cout << "Please enter the number of values you want to sum: ";
    int count{};
    std::cin >> count;

    if (count < 0)
        throw Too_few{};

    std::cout << "Please enter some integers (press '|' to stop): ";
    double in{};
    while (std::cin >> in) {
        input.push_back(in);
    }

    if (count > input.size())
        throw Too_many{};

    std::cout << "The sum of the first " << count << " numbers ( ";
    print(input, count);
    std::cout << ") is " << sum(input, count) << '\n';

    diffCalc(input, differences);
    std::cout << "The differences between entries is: ( ";
    print(differences, differences.size());
    std::cout << ")\n";

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
catch (Too_small) {
    std::cerr << "Too few entries for differences!\n";
    return 3;
}