#include <iostream>
#include <vector>

class Too_few {};

void fibonacci(std::vector<int>& f, int x) {
    for (int i{0}; i < x; ++i) {
        if (i == 0)
            f.push_back(1);
        if (i == 1)
            f.push_back(1);
        if (i >= 2)
            f.push_back(f[i - 2] + f[i - 1]);
    }
}

void print(std::vector<int>& f) {
    for (int i{0}; i < f.size(); ++i)
        std::cout << f[i] << ' ';
}

int main()
try {
    int in{};
    std::cout << "How many fibonacci numbers would you like?: ";
    std::cin >> in;

    if (in <= 0)
        throw Too_few{};

    std::vector<int> f{};
    fibonacci(f, in);

    print(f);
    std::cout << '\n';

    return 0;
}
catch (Too_few) {
    std::cerr << "Not enough Fibonacci numbers requested!\n";
    return 1;
}