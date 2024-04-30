#include <iostream>

class Bad_unit {};
class Below_zero {};

double convert(double temp, char unit)
{
    switch (unit) {
        case 'c':
            if (temp < -273.15)
                throw Below_zero{};
            return temp + 273.15;
        case 'k':
            return temp - 273.15;
        default:
            throw Bad_unit{};
    }
}
int main()
try {
    std::cout << "Please enter a temperature and unit (k or c): ";
    double temp{};
    char unit{};
    std::cin >> temp >> unit;
    
    double conv = convert(temp, unit);
    std::cout << "The converted temperature is: " << conv << '\n' ;

    return 0;
}
catch (Below_zero) {
    std::cerr << "Temperature below absolute zero!\n";
    return 1;
}
catch (Bad_unit) {
    std::cerr << "Unknown unit!\n";
    return 2;
}
catch (...) {
    std::cerr << "Unknown exception!\n";
    return 3;
}