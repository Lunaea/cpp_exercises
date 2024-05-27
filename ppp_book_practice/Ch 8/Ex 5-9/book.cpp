#include "book.h"
#include "date.h"
#include <iostream>
#include <regex>
#include <string>

const std::vector<std::string_view> genres{ "empty", "Fiction", "Non-Fiction", "Periodical",
                                      "Biography", "Children" };

void Book::checkIn() {
    if (status)
        throw;
    status = true;
}

void Book::checkOut() {
    if (!status)
        throw;
    status = false;
}

bool Book::isValid() const {
    //regex to ensure isbn is of "int-int-int-char" format
    std::regex format{ "(\\d+)-(\\d+)-(\\d+)-([a-zA-Z0-9])" };
    return std::regex_match(getIsbn(), format);
}

bool operator==(const Book& a, const Book& b) {
    return a.getIsbn() == b.getIsbn();
}

bool operator!=(const Book& a, const Book& b) {
    return !(a==b);
}

std::ostream& operator<<(std::ostream& o, const Genre& g) {
    return o << genres[(int)g];
}

std::ostream& operator<<(std::ostream& o, const Book& a) {
    return o << a.getTitle() << '\n'
             << a.getAuthor() << '\n'
             << a.getIsbn() << '\n'
             << a.getGenre() << '\n';
}