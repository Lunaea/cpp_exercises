#include <iostream>
#include <string_view>
#include "date.h"

Month operator++(Month& m) {
    m = (m==Month::dec) ? Month::jan : Month{ static_cast<int>(m) + 1 };
    return m;
}

Month operator--(Month& m) {
    m = (m==Month::jan) ? Month::dec : Month{ static_cast<int>(m) - 1 };
    return m;
}

Month operator+(Month& m, int n) {
    if (n == 12 || n == 0)
        return m;
    if (static_cast<int>(m) + n == 12) {
        m = Month::dec;
        return m;
    }

    m = Month{ (static_cast<int>(m) + n) % 12 };
    if ( static_cast<int>(m) == 0)
        m = Month::dec;
    return m;
}

Month operator+=(Month& m, int n) {
    return Month{ m + n };
}

Year operator+(Year& y, int n) {
    y.y += n;
    return Year{ y.y };
}

Year operator+=(Year& y, int n) {
    y.y += n;
    return Year{ y.y };
}

std::ostream& operator<<(std::ostream& o, const Month& m) {
    return o << monthTable[(int)m];
}

std::ostream& operator<<(std::ostream& o, const Year& y) {
    return o << y.y;
}

std::ostream& operator<<(std::ostream& o, const Date& d) {
    return o << d.getMonth() << '/' << d.getDay() << '/' << d.getYear();
}

void Date::addMonth(int n) {
    if (static_cast<int>(m) + n >= 12)
        y += n / 12;
    m += n;
}

void Date::addDay(int n) {
    d += n;
    
    if (d > 31) {
        m += d / 31;
        d %= 31;
        if (d == 0) {
            d = 31;
            --m;
        }
    }
}

void Date::addYear(int n) {
    y += n;
}

bool Date::isValid() const {
    return (0 < d && d <= 31) && (0 < static_cast<int>(m) && static_cast<int>(m) <= 12);
}