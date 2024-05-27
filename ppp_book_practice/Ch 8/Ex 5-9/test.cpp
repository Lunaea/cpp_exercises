#include "book.h"
#include "date.h"
#include <iostream>
#include <string>

int main() 
try {
    std::string author{};
    std::string title{};
    std::string isbn{};
    Date copy{};

    std::cout << "isbn, title, author, date: ";
    std::getline(std::cin >> std::ws, isbn);
    std::getline(std::cin >> std::ws, title);
    std::getline(std::cin >> std::ws, author);

    Book test{ isbn, title, author, copy, true };
    std::cout << test << copy << '\n';
}
catch (...)
{
    std::cerr << "bad isbn";
    return 1;
}