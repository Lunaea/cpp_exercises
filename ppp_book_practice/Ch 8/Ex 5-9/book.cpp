#include "book.h"
#include "date.h"
#include <iostream>
#include <regex>
#include <string>

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
    std::regex format{ "(\\d+)-(\\d+)-(\\d+)-([a-zA-Z0-9])" };
    return std::regex_match(getIsbn(), format);
}

bool operator==(const Book& a, const Book& b) {
    return a.getIsbn() == b.getIsbn();
}

bool operator!=(const Book& a, const Book& b) {
    return !(a==b);
}

std::ostream& operator<<(std::ostream& o, const Book& a) {
    return o << a.getTitle() << '\n'
             << a.getAuthor() << '\n'
             << a.getIsbn() << '\n';
}