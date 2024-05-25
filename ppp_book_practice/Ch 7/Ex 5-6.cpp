#include "reverse.h"
#include "print.h"
#include <iostream>
#include <vector>
#include <string>

/*int main() {
    std::cout << "Please enter integers for vector: ";

    std::vector<int> input{};
    int x{};
    while (std::cin >> x)
        input.push_back(x);

    std::vector<int> rInput { reverseN(input) };

    print("reverseN: ", rInput);

    print("Input: ", input);

    reverse(input);

    print("reverse: ", input);

    return 0;
} */

int main() {
    std::cout << "Please enter strings for vector (; to end input): ";

    std::vector<std::string> input{};
    std::string x{};
    while (std::cin >> x) {
        if (x == ";")
            break;
        input.push_back(x);
    }

    std::vector<std::string> rInput { reverseN(input) };

    print("reverseN: ", rInput);

    print("Input: ", input);

    reverse(input);

    print("reverse: ", input);

    return 0;
}