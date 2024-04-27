#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string seed{};
    char playerMove{};
    int wins{};
    int draws{};
    int losses{};
    int compMove{};
    std::vector<int> choices{};
    std::cout << "Please enter some numbers to setup: ";
    while (std::cin >> seed) {
        if (seed == "|")
            break;
        choices.push_back((std::stoi(seed) * 7 + 11) % 3);
    }
    std::cout << "Setup Complete! Let's play rock, paper, scissors!\n";

    while(playerMove != 'q') {
        std::cout << "Enter your move (r)ock, (p)aper, (s)cissors; (q) to quit: ";
        std::cin >> playerMove;
        if (playerMove == 'q')
            break;
        if (playerMove == 'r')
            playerMove = 0;
        else if (playerMove == 'p')
            playerMove = 1;
        else if (playerMove == 's')
            playerMove = 2;
        else {
            std::cout << "Bad input, try it again\n";
            continue;
        }

        switch (playerMove) {
            case 0:
                if (choices[compMove] == 0) {
                    std::cout << "Rock! Draw!\n";
                    ++draws;
                }
                else if (choices[compMove] == 1) {
                    std::cout << "Paper! You Lose!\n";
                    ++losses;
                }
                else if(choices[compMove] == 2) {
                    std::cout << "Scissors! You Win!\n";
                    ++wins;
                }
                break;
            case 1:
                if (choices[compMove] == 1) {
                    std::cout << "Paper! Draw!\n";
                    ++draws;
                }
                else if (choices[compMove] == 2) {
                    std::cout << "Scissors! You Lose!\n";
                    ++losses;
                }
                else if(choices[compMove] == 0) {
                    std::cout << "Rock! You Win!\n";
                    ++wins;
                }
                break;
            case 2:
                if (choices[compMove] == 2) {
                    std::cout << "Scissors! Draw!\n";
                    ++draws;
                }
                else if (choices[compMove] == 0) {
                    std::cout << "Rock! You Lose!\n";
                    ++losses;
                }
                else if(choices[compMove] == 1) {
                    std::cout << "Paper! You Win!\n";
                    ++wins;
                }
                break;
            default:
                break;
        }

        std::cout << "Current stats: Wins - " << wins << " Losses - " << losses << " Draws - " << draws << '\n';
        ++compMove;
        if (compMove >= choices.size())
            compMove = 0;
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}