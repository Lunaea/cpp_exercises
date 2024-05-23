#include <iostream>

namespace X {
    int var{};
    void print() {
        std::cout << "X var: " << var << '\n';
    }
}

namespace Y {
    int var{};
    void print() {
        std::cout << "Y var: " << var << '\n';
    }

}

namespace Z {
    int var{};
    void print() {
        std::cout << "Z var: " << var << '\n';
    }

}

void swap_v(int a, int b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
}

/*void swap_cr(const int& a, const int& b) {
    int temp{};
    temp = a;
    a = b;
    b = temp;
} */

int main() {
    X::var = 7;
    X::print(); // print X var

    using namespace Y;
    var = 9;
    print(); // print Y var

    {
        using Z::var;
        using Z::print;
        var = 11;
        print(); // print Z var
    }

    print(); // print Y var
    X::print(); // print X var
    
    return 0;
}