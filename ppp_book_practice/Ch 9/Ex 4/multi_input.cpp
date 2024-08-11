#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

bool isValid(const std::string& in) {
    if (!std::isdigit(in[0]))
        return false;
    if (in.size() == 2 && !std::isdigit(in[1]))
        return false;
    if (in[1] != 'x' && !std::isdigit(in[1]))
        return false;
    if (in[0] == '0' && (in[1] == '9' || in[1] == '8'))
        return false;
    for (int i = 2; i < in.size(); ++i) {
        if (in[1] == 'x') {
            if (!std::isxdigit(in[i]))
                return false;
        }
        else if (in[0] == '0' && (in[i] == '9' || in[i] == '8'))
            return false;
    }
    return true;
}

void getType(const std::vector<std::string>& in, std::vector<std::string>& t) {
    for (int i = 0; i < in.size(); ++i) {
        if (in[i].size() == 1 || in[i][0] != '0') {
            t.push_back("decimal");
            continue;
        }
        if (in[i][1] == 'x') {
            t.push_back("hexadecimal");
            continue;
        }
        t.push_back("octal");
    }
}

void print(const std::string& i, const std::string& t) {
        std::cout << i << '\t' << std::setw(11) << t << "\tconverts to\t" << std::stoi(i, nullptr, 0) << "\tdecimal";
}

int main() {
    std::cout << "Please enter integers in dec, hex(0xNN), and/or oct(0NN): ";
    std::vector<std::string> input{};

    for (std::string in; std::cin >> in;) {
        if (!isValid(in))
            throw std::runtime_error("invalid entry " + in);
        input.push_back(in);
    }

    std::vector<std::string> type{};
    getType(input, type);

    for (int i = 0; i<input.size(); ++i) {
        print(input[i], type[i]);
        std::cout << '\n';
    }


    return 0;
}