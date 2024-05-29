#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <cmath>

class Money {
public:
    Money() {}
    Money(long c): total{ c } 
    {
        dollars = total / 100;
        cents = total % 100;
    }

    int getCents() const { return cents; }
    long getDollars() const { return dollars; }
    long getTotal() const { return total; }

private:
    int cents{};
    long dollars{};
    long total{};
};

std::ostream& operator<<(std::ostream& o, Money& a);

#endif