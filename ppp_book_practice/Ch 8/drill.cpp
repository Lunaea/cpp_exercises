#include <iostream>
#include <vector>
#include <string_view>

enum class Month {
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

const std::vector<std::string_view> monthTable{ "NA", "January", "February", "March", "April", "May", "June",
                                                "July", "August", "September", "October", "November", "December" };

struct Year {
    int y{};
};

class Date {
public:
    class InvalidDate {};
    Year getYear() const { return y; }
    Month getMonth() const { return m; }
    int getDay() const { return d; }

    void setYear(Year yy) { y = yy; }
    void setMonth(Month mm) { m = mm; }
    void setDay(int dd) { d = dd; }

    void addDay(int n);
    void addMonth(int n);
    void addYear(int n);

    bool isValid() const;

    Date() {}
    Date(Year yy, Month mm, int dd): y{ yy }, m{ mm }, d{ dd }
    {
        if (!isValid())
            throw InvalidDate{};
    }

private:
    Year y{ 1900 };
    Month m{ Month::jan };
    int d{ 1 };
};

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

std::ostream& operator<<(std::ostream& o, Month m) {
    return o << monthTable[(int)m];
}

std::ostream& operator<<(std::ostream& o, Year y) {
    return o << y.y;
}

std::ostream& operator<<(std::ostream& o, Date d) {
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

int main() 
try {
    Date today{ Year{ 2020 }, Month::feb, 2 };
    Date tomorrow{ today };
    tomorrow.addDay(1);

    std::cout << today << '\n' << tomorrow << '\n';

    return 0;
}
catch(Date::InvalidDate) {
    std::cerr << "Invalid date!\n";
    return 1;
}