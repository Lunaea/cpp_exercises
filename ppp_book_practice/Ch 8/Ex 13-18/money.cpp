#include "money.h"

std::ostream& operator<<(std::ostream& o, Money& a) {
    o << a.getCurrency() << a.getDollars() << '.';
    if (a.getCents() == 0)
        o << "00";
    else
        o << a.getCents();

    return o;
}

std::istream& operator>>(std::istream& i, Money& a) {
    char ch{};
    std::string s{};
    float x{};

    while (i.get(ch)) {
        if (isalpha(ch))
            s += ch;
        else {
            i.putback(ch);
            i >> x;
        }
    }

    a = Money{ s, x };
    return i;
}