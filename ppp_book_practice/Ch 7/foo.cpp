#include "foo.h"
#include <iostream>

int foo{};

void printFoo() {
    std::cout << "Foo: " << foo << '\n';
}

void setFoo(int x) {
    foo = x;
}

int getFoo() {
    return foo;
}