#include "fibonacci.h"

void fibonacci(int x, int y, std::vector<int>& v, int n) 
try {
    if (v.size())
        throw;

    v.push_back(x);
    v.push_back(y);

    if (n <= 2)
        return;

    for (int i = 2; i < n; ++i)
        v.push_back(v[i-2] + v[i-1]);
}
catch (...) {
    std::cerr << "vector not empty!\n";
}