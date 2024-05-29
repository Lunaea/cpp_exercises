#include "money.h"

std::ostream& operator<<(std::ostream& o, Money& a) {
    o << '$' << a.getDollars() << '.';
    if (a.getCents() == 0)
        o << "00";
    else
        o << a.getCents();

    return o;
}
