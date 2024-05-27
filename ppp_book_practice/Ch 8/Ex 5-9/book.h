#ifndef BOOK_H
#define BOOK_H

#include "date.h"
#include <string>
#include <string_view>
#include <vector>

enum class Genre {
    empty,
    fiction,
    nonfiction,
    periodical,
    biography,
    children,
};

class Book {
public:
    class InvalidBook {};
    class InvalidOut {};
    class InvalidIn {};

    std::string getIsbn() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    Genre getGenre() const { return genre; }
    Date getCopyright() const { return copyright; }
    bool getStatus() const { return status; }

    void checkIn();
    void checkOut();
    bool isValid() const;

    Book(std::string i, std::string t, std::string a, Genre g, Date d, bool s)
        : isbn{ i }, title{ t }, author{ a }, genre{ g }, copyright{ d }, status{ s }
    {
        if (!isValid())
            throw InvalidBook{};
    }

private:
    std::string isbn, title, author;
    Date copyright{};
    bool status{ true };
    Genre genre{ Genre::empty };
};

std::ostream& operator<<(std::ostream& o, const Genre& g);
std::ostream& operator<<(std::ostream& o, const Book& a);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

#endif