#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string answer{ "abcd" };
    std::string guess{};
    int bulls{};

    while (bulls != 4) {
        bulls = 0;
        int cows{};
        std::cout << "Enter a 4 letter guess: ";
        std::cin >> guess;

        for (int i{0}; i < answer.size(); ++i) {
            for (int j{0}; j < answer.size(); ++j) {
                if (i != j && answer[i] == guess[j])
                    ++cows;
                else if (i == j && answer[i] == guess[j])
                    ++bulls;
            }
        }

        std::cout << bulls << " bulls and " << cows << " cows\n";
    }

    return 0;
}