#include "../PPPheaders.h"

void playGame() {
    vector<int> answer{};
    cout << "Enter a seed integer (any number): ";
    int n{};
    cin >> n;
    seed(n);
    for (int i{0}; i < 4; ++i)
        answer.push_back(random_int(0, 9));
    for (int num : answer)
        cout << num << ' ';
    cout << '\n';
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
    cout << "You Win!\n";
}

int main() {
    char cont{};
    while (cont != 'n' && cont != 'N') {
        playGame();

        cout << "Play again? (y/n): ";
        cin >> cont;
    }

    return 0;
}