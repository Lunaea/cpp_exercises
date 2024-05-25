#include "reverse.h"

std::vector<int> reverseN(const std::vector<int>& in) {
    std::vector<int> reversed{};

    for (int i = in.size() - 1; i >= 0; --i)
        reversed.push_back(in[i]);
        
    return reversed;
}

void reverse(std::vector<int>& in) {
    int temp{};
    for (int i = 0; i < in.size() / 2; ++i) {
        temp = in[i];
        in[i] = in[in.size()-1-i];
        in[in.size()-1-i] = temp;
    }
}

std::vector<std::string> reverseN(const std::vector<std::string>& in) {
    std::vector<std::string> reversed{};

    for (int i = in.size() - 1; i >= 0; --i)
        reversed.push_back(in[i]);
        
    return reversed;
}

void reverse(std::vector<std::string>& in) {
    std::string temp{};
    for (int i = 0; i < in.size() / 2; ++i) {
        temp = in[i];
        in[i] = in[in.size()-1-i];
        in[in.size()-1-i] = temp;
    }
}