#include "../PPPheaders.h"

int toInt(string in) {
    int num{};
    int i{ 1 };
    while (in.size() >= 1) {
        num += (in[in.size() - 1] - '0') * i;
        in.pop_back();
        i *= 10;
    }
    return num;
}
const vector<string> names{ " thousands", " hundreds", " tens", " ones" };

int main() {
    string in{};
    vector<int> digits{};
    cout << "Please enter a number between 0 and 9999: ";
    cin >> in;
    if (in.size() > 4)
        error("Number above 9999!\n");
    int num{ toInt(in) };
    for (int i{ 0 }; i < in.size(); ++i) {
        digits.push_back(in[i] - '0');
    }
    cout << num << " is ";

    for (int i{ 0 }; i < digits.size(); ++i) {
        if (i == digits.size() - 1)
            cout << digits[i] << names[i] << '\n';
        else
            cout << digits[i] << names[i] << " and ";
    }

    return 0;
}
