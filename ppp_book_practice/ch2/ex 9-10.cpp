#include <iostream>
#include <cmath>
#include <vector>

constexpr int milestone1{ 1000 };
constexpr int milestone2{ 1000000 };
constexpr int milestone3{ 1000000000 };

int main() {
    double squareRice{};
    double totalRice{};
    std::vector<bool> milestones{ false, false, false };

    for (int position { 1 }; position <= 64; ++position) {
        squareRice = pow(2,position - 1);
        totalRice += squareRice;
        std::cout << "Square " << position << " has " << squareRice << " grains of rice, " << totalRice << " grains total\n";
        if (totalRice >= milestone1 && !milestones[0]) {
            std::cout << "1,000 reached at square " << position << "!\n";
            milestones[0] = true;
        }
        if (totalRice >= milestone2 && !milestones[1]) {
            std::cout << "1,000,000 reached at square " << position << "!\n";
            milestones[1] = true;
        }
        if (totalRice >= milestone3 && !milestones[2]) {
            std::cout << "1,000,000,000 reached at square " << position << "!\n";
            milestones[2] = true;
        }
    }

    return 0;
}