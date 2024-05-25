#include "print.h"

void print(const std::string& label, const std::vector<int>& v) {
    std::cout << label << '\n';
    for (int i = 0; i < v.size(); ++i) {
        if (i < v.size() - 1)
            std::cout << v[i] << ", ";
        else
            std::cout << v[i] << '\n';
    }
}