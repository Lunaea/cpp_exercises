#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void reverseChars(const std::vector<std::string>& lines, std::vector<std::string>& reversed) {
    for(int i = lines.size() - 1; i >= 0; --i) {
        std::string reverse{};
        for(int j = lines[i].length() - 1; j >= 0; --j) {
            reverse += lines[i][j];
        }
        reversed.push_back(reverse);
    }
}

void reverseWords(const std::vector<std::string>& words, std::vector<std::string>& reversed) {
    for(int i = words.size() - 1; i >= 0; --i)
        reversed.push_back(words[i]);
}

int main() {
    std::ifstream ist{ "input.txt" };
    std::ofstream ost{ "outputChar.txt" };
    std::ofstream ost2{ "outputWord.txt" };

    std::vector<std::string> lines{};
    std::vector<std::string> words{};

    for(std::string line; std::getline(ist, line);)
        lines.push_back(line);

    ist.clear(); //clear ist eof state
    ist.seekg(0, std::ios::beg); //seek to beginning of ist
    
    for(std::string word; ist >> word;)
        words.push_back(word);

    std::vector<std::string> reversedChar{};
    std::vector<std::string> reversedWord{};

    reverseChars(lines, reversedChar);
    reverseWords(words, reversedWord);

    for(auto line : reversedChar)
        ost << line << '\n';

    for(auto word : reversedWord)
        ost2 << word << ' ';

    return 0;
}