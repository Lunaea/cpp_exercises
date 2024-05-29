#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <cmath>
#include <string>

class Money {
public:
    Money() {}
    Money(std::string s, float c): currency{ s } 
    {
        total = std::round(c * 100);
        dollars = total / 100;
        cents = total % 100;
    }

    const std::string& getCurrency() const { return currency; }
    int getCents() const { return cents; }
    long getDollars() const { return dollars; }
    long getTotal() const { return total; }

    friend std::istream& operator>>(std::istream& i, Money& a);

private:
    int cents{};
    long dollars{};
    long total{};
    std::string currency{};
};

std::ostream& operator<<(std::ostream& o, Money& a);

#endif