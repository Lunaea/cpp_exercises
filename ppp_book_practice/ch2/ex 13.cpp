#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<bool> primes(101);
    primes[0] = false;
    primes[1] = false;
    for (int i{ 2 }; i < primes.size(); ++i)
        primes[i] = true;
    for (int i{ 2 }; i < 10; ++i) {
        if (primes[i]) {
            for (int j{ pow(i, 2) }; j < primes.size(); j += i)
                primes[j] = false;
        }
    }

    for (int i{ 0 }; i < primes.size(); ++i) {
        if (primes[i])
            std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}