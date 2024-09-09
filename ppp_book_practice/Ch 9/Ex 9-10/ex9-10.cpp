#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool isCustom(const char s, const std::string& w) {
    for(int i = 0; i < w.length(); ++i) {
        if(s == w[i])
            return true;
    }
    return false;
}

std::vector<std::string> split(const std::string& s) {
    std::istringstream in{ s };
    std::vector<std::string> subs{};

    for(std::string x; in >> x;)
        subs.push_back(x);

    return subs;
}

std::vector<std::string> split(const std::string& s, const std::string& w) {
    std::vector<std::string> subs{};
    std::string line{};
    
    for(int i = 0; i < s.length(); ++i) {
        if(std::isspace(s[i]) || isCustom(s[i], w)) {
            subs.push_back(line);
            line = "";
        }
        else
            line.push_back(s[i]);
        if(i == s.length() - 1)
            subs.push_back(line);
    }
    return subs;
}

int main() {
    std::string test{ "The quick brown fox jumped over the lazy dogs." };
    std::string test2{ "The qu?ick brown fo!x jum:ped over the la/zy dogs." };
    std::string testSpace{ "?/:!" };
    std::vector<std::string> substrings{ split(test) };
    std::vector<std::string> subCustom{ split(test2, testSpace) };

    for (auto line : substrings)
        std::cout << line << '\n';

    std::cout << "\n\n";

    for (auto line : subCustom)
        std::cout << line << '\n';

    return 0;
}