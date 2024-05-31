#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <fstream>

struct Point {
    int x{};
    int y{};
    Point() {}
    Point(int xx, int yy): x{xx}, y{yy} {}
};

std::ostream& operator<<(std::ostream& o, const Point& p) {
    return o << '(' << p.x << ',' << p.y << ')';
}

std::istream& operator>>(std::istream& i, Point& p) {
    char left, ch, right;
    int x, y;
    i >> left >> x >> ch >> y >> right;
    if (!i)
        return i;
    if (left != '(' || ch != ',' || right != ')') {
        i.clear(std::ios::failbit);
        return i;
    }
    p = Point{x, y};
    return i;
}

Point getCoordinates(const std::string& a) {
    std::istringstream is{ a };
    Point xy{};
    char left, ch, right;
    is >> left >> xy.x >> ch >> xy.y >> right;
    if (!is || left != '(' || ch != ',' || right != ')')
        throw std::runtime_error("bad input! " + a);
    return xy;
}

void fillFromFile(std::vector<Point>& points, const std::string& name) {
    std::ifstream ist{name};
    if (!ist)
        throw std::runtime_error("Can't locate input file!");

    ist.exceptions(ist.exceptions()|std::ios::badbit);

    while (true) {
        Point p{};
        if (!(ist >> p))
            break;
        points.push_back(p);
    }
}

int main() {
    std::string name{"mydata.txt"};

    std::ofstream ost{name};
    if (!ost)
        throw std::runtime_error("Can't locate output file!");

    std::vector<Point> originalPoints{};
    std::cout << "Please enter 7 points (x,y): ";
    for (int i = 0; i < 7; ++i) {
        Point p{};
        std::cin >> p;
        originalPoints.push_back(p);
    }

    for (auto p : originalPoints)
        std::cout << p << '\n';

    for (auto p : originalPoints)
        ost << p << '\n';
    
    ost.close();

    std::vector<Point> processed{};
    fillFromFile(processed, "point.txt");
    std::cout << "read " << processed.size() << " points\n";
    
    for (auto p : processed)
        std::cout << p;

    return 0;
}