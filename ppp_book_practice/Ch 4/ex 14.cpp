#include "../PPPheaders.h"

class BadDay {};

void print(vector<int>& v) {
    int sum{};
    for (auto num : v) {
        sum += num;
        cout << num << ' ';
    }
    cout << "Total: " << sum << '\n';
}

int main()
try {
    vector<int> sunday{};
    vector<int> monday{};
    vector<int> tuesday{};
    vector<int> wednesday{};
    vector<int> thursday{};
    vector<int> friday{};
    vector<int> saturday{};
    vector<string> days{};

    string day{};
    int val{};
    int rejected{};

    while (cin) {
        cin >> day >> val;

    }
}