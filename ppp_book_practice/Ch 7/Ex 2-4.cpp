#include <iostream>
#include <string>
#include <vector>
#include "print.h"
#include "fibonacci.h"

int main() {
    std::cout << "Please enter 2 starting integers and a number of fibonacci numbers you'd like: ";

    int x, y, n;
    std::cin >> x >> y >> n;

    std::vector<int> v{};

    fibonacci(x,y,v,n);

    print("Fibonacci", v);

    // max int approx 1836311903

    return 0;
}