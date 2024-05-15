#include "../PPPheaders.h"

int factorial(int n) {
    int x{};
    if (n < 0)
        error("Can't factorial negative number!\n");
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

class Token {
public:
    char kind{};
    double val{};
    Token() = default;
    Token(char x)
        : kind { x }
        , val { 0.0 } {}
    Token(char x, double y) 
        : kind { x }
        , val { y } {}
};

class Token_stream {
public:
    Token get();
    void putback(Token t);

private:
    bool full = false;
    Token buffer;
};

void Token_stream::putback(Token t) {
    if (full)
        error("Buffer already full!\n");
    full = true;
    buffer = t;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch{};
    if (!(cin >> ch))
        error("No input!\n");

    switch(ch) {
        case ';':
        case 'q':
        case '(': case ')': case '+': case '-': case '*': case '/':
        case '{': case '}': case '!':
            return Token{ ch };
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {   
            double val{};
            cin.putback(ch);
            cin >> val;
            return Token{ '8', val };
        }
        default:
            error("Bad token!\n");
    }
}

Token_stream ts;
double expression();

double primary() {
    Token t{ ts.get() };
    switch (t.kind) {
        case '(':
        {
            double d{ expression() };
            t = ts.get();
            if (t.kind != ')')
                error("Expected ')'\n");
            return d;
        }
        case '{':
        {
            double d{ expression() };
            t = ts.get();
            if (t.kind != '}')
                error("Expected '}'\n");
            return d;
        }
        case '8':
            return t.val;
        default:
            error("Primary expected!\n");
    }
}

double term() {
    double left{ primary() };
    Token t{ ts.get() };
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0)
                    error("Can't divide by 0\n");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression() {
    double left{ term() };
    Token t{ ts.get() };
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }            
    }
}

int main() 
try {
    double val{};
    while (cin) {
        Token t{ ts.get() };
        if (t.kind == 'q')
            break;
        if (t.kind == ';')
            cout << '=' << val << '\n';
        else
            ts.putback(t);
            val = expression();
    }
    return 0;
}
catch (...) {
    return 1;
}