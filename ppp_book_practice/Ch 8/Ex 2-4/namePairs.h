#ifndef NAMEPAIRS_H
#define NAMEPAIRS_H

#include <iostream>
#include <vector>
#include <string>

class NamePairs {
public:
    void readNames();
    void readAges();
    void print() const;
    void sort();

private:
    std::vector<std::string> names{};
    std::vector<double> ages{};
};

#endif