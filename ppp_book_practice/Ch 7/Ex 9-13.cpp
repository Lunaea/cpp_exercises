#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

double compIndex(const std::vector<double>& price, const std::vector<double>& weight) {
    if (price.size() != weight.size()) {
        std::cerr << "Size mismatch!\n";
        return -1;
    }

    double index{};

    for (int i = 0; i < price.size(); ++i)
        index += price[i] * weight[i];

    return index;
}

template <typename T>
T maxv(const std::vector<T>& in) {
    if (!in.size())
        return -1;

    T max{ in[0] };

    for (auto x : in)
        if (x > max)
            max = x;

    return max;
}

template <typename T>
T minv(const std::vector<T>& in) {
    if (!in.size())
        return -1;

    T min{ in[0] };

    for (auto x : in)
        if (x < min)
            min = x;

    return min;
}

template <typename T>
void calcVal(const std::vector<T>& in, T& min, T& max, T& median, T& mean) {
    max = maxv(in);
    min = minv(in);

    T sum{};
    for (int i = 0; i < in.size(); ++i)
        sum += in[i];
    mean = sum / in.size();

    if (in.size() % 2 == 0)
        median = (in[in.size() / 2] + in[(in.size() / 2) - 1]) / 2;
    else
        median = in[in.size() / 2];

}

std::vector<int> stringCalc(std::vector<std::string>& in) {
    std::vector<int> lengths{};

    for (auto x : in)
        lengths.push_back(x.size());

    return lengths;
}

void print_until(const std::vector<std::string>& v, const std::string& quit) {
    for (auto s : v) {
        if (s==quit)
            return;
        std::cout << s << '\n';
    }
}

void print_until2(const std::vector<std::string>& v, const std::string& quit) {
    int count{};

    for (auto s : v) {
        if (s==quit)
            ++count;
        if (count == 2)
            return;
        std::cout << s << '\n';
    }
}

int main() {
    std::vector<double> test1{ 1.1, 2.2, 3.3, 4.4, 5.5, 6 };
    std::vector<double> test2{ 5.1, 4.2, 3.23, 2.7, 1.5, 6 };
    std::vector<std::string> words{ "popeye", "the", "sailor", "man", "still", "am", "the", "watching" };

    double min, max, median, mean;
    calcVal(test2, min, max, median, mean);

    std::cout << "compIndex: " << compIndex(test1, test2) << '\n'
              << "maxv: " << maxv(test1) << '\n'
              << "calcVal: " << min << ' ' << max << ' ' << median << ' ' << mean << '\n';

    for (auto word : words)
        std::cout << word << ' ';

    std::cout << '\n';

    print_until2(words, "the");

    std::sort(words.begin(), words.end());

    std::vector<int> lengths{ stringCalc(words) };
    for (int x : lengths)
        std::cout << x << ' ';

    std::cout << '\n';

    for (auto word : words)
        std::cout << word << ' ';

    std::cout << '\n';

    return 0;
}