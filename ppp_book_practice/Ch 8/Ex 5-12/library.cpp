#include "library.h"
#include "book.h"
#include "date.h"
#include "patron.h"
#include <vector>
#include <iostream>


void Library::addBook(Book b) {
    books.push_back(b);
}

void Library::addPatron(Patron p) {
    patrons.push_back(p);
}

void Library::checkOut(Book b, Patron p, Date d) {
    if (!b.getStatus()) {
        std::cerr << "Book already checked out!";
        throw;
    }

    bool isPatron{ false };
    for (auto patron : patrons) {
        if (p == patron)
            isPatron = true;
    }
    if (!isPatron) {
        std::cerr << "Not a patron!";
        throw;
    }

    if (p.hasFee()) {
        std::cerr << "Patron has fees!";
        throw;
    }
    
    b.checkOut();
    transactions.push_back({ b, p, d });
}

void Library::checkIn(Book b, Patron p) {
    for (int i = 0; i < transactions.size(); ++i) {
        if (transactions[i].patron == p && transactions[i].book == b)
            transactions.erase(transactions.begin() + i);
    }
}

std::vector<Patron> Library::hasFees() {
    std::vector<Patron> fees{};

    for (auto patron : patrons) {
        if (patron.hasFee())
            fees.push_back(patron);
    }

    return fees;
}