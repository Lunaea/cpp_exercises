#ifndef PATRON_H
#define PATRON_H

#include <string>

class Patron {
public:
    std::string getName() const { return name; }
    int getCard() const { return card; }
    double getFee() const { return fee; }

    bool hasFee() const { return (fee > 0); }

    Patron() {}
    Patron(std::string n, int c, double f): name{ n }, card{ c }, fee{ f } {}

private:
    std::string name{};
    int card{};
    double fee{ 0.00 };
};

bool operator==(const Patron& a, const Patron& b);
bool operator!=(const Patron& a, const Patron& b);

#endif