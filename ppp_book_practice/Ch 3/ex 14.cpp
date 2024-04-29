#include <iostream>
#include <vector>

bool isPrime(int x, std::vector<int>& v) {
    for (int i{ 0 }; i < v.size(); ++i) {
        if (x % v[i] == 0)
            return false;
    }
    return true;
}

int main() {
    std::vector<int> primes{};
    primes.push_back(2);

    std::cout << "How many primes would you like? ";
    int in{};
    std::cin >> in;

    for (int i{ 3 }; primes.size() < in; ++i) {
        if (isPrime(i, primes))
            primes.push_back(i);
    }
    for (int prime : primes)
        std::cout << prime << ' ';

    std::cout << '\n';

    return 0;
}