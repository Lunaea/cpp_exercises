#include "PPP.h"

int main() {
    vector<int> answer{ 1, 2, 3, 4 };
    string in{};
    int bulls{};

    while (bulls != 4) {
        bulls = 0;
        int cows{};
        cout << "Enter a 4 digit guess: ";
        cin >> in;
        vector<int> guess{};

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

        cout << bulls << " bulls and " << cows << " cows\n";
    }

    return 0;
}