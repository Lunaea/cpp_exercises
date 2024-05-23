#include <iostream>
#include "foo.h"

int main() {
    int test{100};
    setFoo(test);
    std::cout << "get: " << getFoo() << '\n';

    printFoo();

    return 0;
}