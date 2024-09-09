#include <random>
#include <iostream>
#include <fstream>

int main() {
    std::ofstream ost{ "input.txt" };
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dis(0.0, 1000.0);

    for(int i = 0; i < 200; ++i)
        ost << dis(rng) << ' ';
}