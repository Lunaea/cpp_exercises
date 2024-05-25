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
    std::vector<std::string> getNames() const { return names; }
    std::vector<double> getAges() const { return ages; }

private:
    std::vector<std::string> names{};
    std::vector<double> ages{};
};

std::ostream& operator<<(std::ostream& o, const NamePairs& a);
bool operator==(const NamePairs& a, const NamePairs& b);
bool operator!=(const NamePairs& a, const NamePairs& b);

#endif