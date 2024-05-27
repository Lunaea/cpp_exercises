#ifndef BOOK_H
#define BOOK_H

#include "date.h"
#include <string>
#include <vector>

class Book {
public:
    class InvalidBook {};
    class InvalidOut {};
    class InvalidIn {};

    std::string getIsbn() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    Date getCopyright() const { return copyright; }
    bool getStatus() const { return status; }

    void checkIn();
    void checkOut();
    bool isValid() const;

    Book(std::string i, std::string t, std::string a, Date d, bool s)
        : isbn{ i }, title{ t }, author{ a }, copyright{ d }, status{ s }
    {
        if (!isValid())
            throw InvalidBook{};
    }

private:
    std::string isbn, title, author;
    Date copyright{};
    bool status{ true };
};

std::ostream& operator<<(std::ostream& o, const Book& a);
#endif