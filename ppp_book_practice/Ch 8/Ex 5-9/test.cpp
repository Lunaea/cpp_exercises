#include "book.h"
#include "date.h"
#include "patron.h"
#include "library.h"
#include <iostream>
#include <string>

int main() 
try {
    Library lib{};
    std::string author{};
    std::string title{};
    std::string isbn{};
    Date copy{ Year{ 2024 }, Month::may, 31 };

    std::cout << "Week no. " << weekNum(copy) << '\n';
    std::cout << "Next work day: " << nextWorkday(copy) << '\n';

    std::cout << "isbn, title, author, date: ";
    std::getline(std::cin >> std::ws, isbn);
    std::getline(std::cin >> std::ws, title);
    std::getline(std::cin >> std::ws, author);

    Book test{ isbn, title, author, Genre::nonfiction, copy, true };
    lib.addBook(test);
    lib.addPatron({ "Felix", 7878, 0 });
    std::cout << "okay" << '\n';
}
catch (...)
{
    std::cerr << "bad isbn";
    return 1;
}