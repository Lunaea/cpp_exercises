#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> answer{ 1, 2, 3, 4 };
    std::string in{};
    int bulls{};

    while (bulls != 4) {
        bulls = 0;
        int cows{};
        std::cout << "Enter a 4 digit guess: ";
        std::cin >> in;
        std::vector<int> guess{};

        for (auto ch : in)
            guess.push_back(ch - '0');

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