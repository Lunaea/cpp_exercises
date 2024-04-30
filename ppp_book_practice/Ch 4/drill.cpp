#include <iostream>
#include <vector>
using namespace std;

int main()
try {
    cout << "Success!\n";
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}