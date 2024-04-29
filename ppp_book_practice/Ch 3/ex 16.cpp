#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words{};
    std::string in{};

    std::cout << "Please enter some words: ";
    while (std::cin >> in) {
        words.push_back(in);
    }

    if(words.size() == 0) {
        std::cout << "No Input!\n";
        return 0;
    }

    std::sort(words.begin(), words.end());

    std::string word{ words[0] };
    std::string mode{ word };
    int count{ 1 };
    int modeCount{ 1 };

    for(int i{ 1 }; i < words.size(); ++i) {
        if (words[i] == word) {
            ++count;
            if (count > modeCount) {
                modeCount = count;
                mode = word;
            }
        }
        else {
            count = 1;
            word = words[i];
        }
    }

    int max{ 0 };
    int min{ 1000000 };
    std::string minWord{};
    std::string maxWord{};

    for (std::string word : words) {
        if (word.length() >= max) {
            max = word.length();
            maxWord = word;
        }
        if (word.length() <= min) {
            min = word.length();
            minWord = word;
        }
        if (word.length() > min && word.length() < max) {
            continue;
        }
    }

    std::cout << "The shortest word was: \"" << minWord << "\"\n";
    std::cout << "The longest word was: \"" << maxWord << "\"\n";
    std::cout << "The most frequent word was: \"" << mode << "\"\n";
    std::cout << "It showed up " << modeCount << " times!\n";

    return 0;
}