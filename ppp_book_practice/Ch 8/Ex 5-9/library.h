#ifndef LIBRARY_H
#define LIBRARY_H

#include "patron.h"
#include "book.h"
#include <vector>

class Library {
private:
    struct Transaction {
        Book book{};
        Patron patron{};
        Date date{};
        Transaction(Book b, Patron p, Date d): book{ b }, patron{ p }, date{ d } {}
    };
    
public:
    std::vector<Book> getBooks() const { return books; }
    std::vector<Patron> getPatrons() const { return patrons; }
    std::vector<Transaction> getTransactions() const { return transactions; }

    void addBook(Book b);
    void addPatron(Patron p);
    void checkOut(Book b, Patron p, Date d);
    void checkIn(Book b, Patron p);
    std::vector<Patron> hasFees();

    Library() {}
    Library(std::vector<Book> b, std::vector<Patron> p, std::vector<Transaction> t)
            : books{ b }, patrons{ p }, transactions{ t } {}

private:
    std::vector<Book> books{};
    std::vector<Patron> patrons{};
    std::vector<Transaction> transactions{};
};

#endif