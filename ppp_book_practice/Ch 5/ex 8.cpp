#include "../PPPheaders.h"

long factorial(int n) {
    if (n < 0)
        error("Can't factorial negative number!\n");
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

int permutations(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int combinations(int n, int r) {
    return permutations(n, r) / factorial(r);
}

int main() 
try {
    cout << "Please enter input as nPr or nCr: ";
    int n, r;
    char op{};
    cin >> n >> op >> r;
    switch (op) {
        case 'c': case 'C':
            cout << n << op << r << " is " << combinations(n, r) << '\n';
            break;
        case 'p': case 'P':
            cout << n << op << r << " is " << permutations(n, r) << '\n';
            break;
        default:
            error("Bad input!\n");
    }

    return 0;
}
catch(runtime_error& e) {
    cerr << "Runtime error: " << e.what();
    return 1;
}