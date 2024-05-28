#ifndef DATE_H
#define DATE_H

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

const std::vector<std::string_view> monthTable{ "NA", "January", "February", "March", "April", "May", "June",
                                                "July", "August", "September", "October", "November", "December" };

bool leapyear(int x);
Date nextWorkday(const Date& d);
int daysSinceFirst(const Date& d);
int weekNum(const Date& d);
Month operator++(Month& m);
Month operator--(Month& m);
Month operator+(Month& m, int n);
Month operator+=(Month& m, int n);
Year operator+(Year& y, int n);
Year operator+=(Year& y, int n);
std::ostream& operator<<(std::ostream& o, const Month& m);
std::ostream& operator<<(std::ostream& o, const Year& y);
std::ostream& operator<<(std::ostream& o, const Date& d);
#endif