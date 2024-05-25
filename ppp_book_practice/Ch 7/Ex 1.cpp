#include "../PPPheaders.h"

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char root = 'r';
constexpr char exponent = 'e';
constexpr char con = 'C';
const string declkey = "let";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string constkey = "const";
const string prompt = "> ";
const string result = "= ";

class Variable {
    public:
        string name{};
        double value{};
        bool constant{ false };
        Variable(string n, double x) : name{ n }, value{ x } {}
        Variable(string n, double x, bool c) : name{ n }, value{ x }, constant{ c } {}
};

class Symbol_table {
    public:
        vector<Variable> var_table{};
        double get(string s);
        void set(string s, double d, bool c);
        bool is_declared(string var);
        double declare(string var, double val, bool c);
        Symbol_table() {}
};

Symbol_table table{};

double Symbol_table::get(string s) {
    for (const Variable& v : var_table)
        if (v.name == s)
            return v.value;
    error("Reading undefined variable ", s);
}

void Symbol_table::set(string s, double d, bool c) {
    for (Variable& v : var_table)
        if (v.name == s) {
            if (v.constant)
                error(v.name, " is a constant!");
            v.value = d;
            v.constant = c;
            return;
        }
    error("Writing undefined variable ", s);
}

bool Symbol_table::is_declared(string var) {
    for (const Variable& v : var_table)
        if (v.name == var)
            return true;
    return false;
}

double Symbol_table::declare(string var, double val, bool c) {
    if (is_declared(var)) {
        set(var, val, c);
        return val;
    }
    var_table.push_back(Variable{var,val,c});
    return val;
}

class Token {
public:
    char kind{};
    double val{};
    string name{};
    Token() : kind{ 0 } {}
    Token(char x): kind { x }, val { 0.0 } {}
    Token(char x, double y) : kind { x }, val { y } {}
    Token(char x, string n) : kind{ x }, name{ n } {}
};

class Token_stream {
public:
    Token get();
    void putback(Token t);
    void ignore(char c);
    Token_stream() {}
    Token_stream(istream& in) {}

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

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch{};
    cin.get(ch);
    while (isspace(ch)) {
        if (ch == '\n')
            return Token{ print };
        cin.get(ch);
    }

    switch(ch) {
        case print:
        case quit:
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/': 
        case '%':
        case '=':
        case ',':
            return Token{ ch };
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {   
            double val{};
            cin.putback(ch);
            cin >> val;
            return Token{ number, val };
        }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;
                cin.putback(ch);
                if (s == declkey)
                    return Token{ let };
                if (s == sqrtkey)
                    return Token{ root };
                if (s == powkey)
                    return Token{ exponent };
                if (s == constkey)
                    return Token{ con };
                return Token{ name, s };
            }
            error("Bad token!");
    }
}

Token_stream ts;

double expression(Token_stream& ts);

double declaration() {
    bool constant{ false };
    Token c{ ts.get() };
    if (c.kind == con)
        constant = true;
    else
        ts.putback(c);

    Token t{ ts.get() };
    if (t.kind != name)
        error("Name expected in declaration!\n");

    Token t2{ ts.get() };
    if (t2.kind != '=')
        error("= missing in declaration of ", t.name);
    
    double d = expression(ts);
    table.declare(t.name, d, constant);
    return d;
}

double primary(Token_stream& ts) {
    Token t{ ts.get() };
    switch (t.kind) {
        case '(':
        {
            double d{ expression(ts) };
            t = ts.get();
            if (t.kind != ')')
                error("Expected ')'\n");
            return d;
        }
        case number:
            return t.val;
        case name:
            return table.get(t.name);
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        default:
            error("Primary expected!\n");
    }
}

double square_root() {
    Token t{ ts.get() };
    if (t.kind != '(')
        error("expected '(' after ", sqrtkey);
    double d = expression(ts);
    if (d < 0)
        error("Can't provide complex numbers");
    Token t2{ ts.get() };
    if (t2.kind != ')')
        error("expected ')' to complete ", sqrtkey);
    return sqrt(d);
}

double power() {
    Token t{ ts.get() };
    if (t.kind != '(')
        error("expected '(' after ", powkey);
    double b = expression(ts);
    Token t2{ ts.get() };
    if (t2.kind != ',')
        error("expected ',' after base");
    int p = narrow<int>(expression(ts));
    Token t3{ ts.get() };
    if (t3.kind != ')')
        error("expected ')' to complete ", powkey);
    if (b == 0 && p == 0)
        error("0^0 is indeterminant");
    if (p == 0)
        return 1.0;
    bool inverse{ false };
    if (p < 0) {
        inverse = true;
        p *= -1;
    }
    double result{ 1.0 };
    for (int i{ 0 }; i < p; ++i)
        result *= b;
    if (inverse)
        return 1 / result;
    return result;
}

double term(Token_stream& ts) {
    double left{ primary(ts) };
    Token t{ ts.get() };
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary(ts);
                t = ts.get();
                break;
            case '/':
            {
                double d = primary(ts);
                if (d == 0)
                    error("Can't divide by 0\n");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d{ primary(ts) };
                if (d==0)
                    error("%: division by 0!\n");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression(Token_stream& ts) {
    double left{ term(ts) };
    Token t{ ts.get() };
    while (true) {
        switch (t.kind) {
            case '+':
                left += term(ts);
                t = ts.get();
                break;
            case '-':
                left -= term(ts);
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }            
    }
}

double statement() {
    Token t{ ts.get() };
    switch (t.kind) {
        case let:
            return declaration();
        case exponent:
            return power();
        case root:
            return square_root();
        default:
            ts.putback(t);
            return expression(ts);
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin) 
    try {
        cout << prompt;
        Token t{ ts.get() };
        while (t.kind == print)
            t = ts.get();
        if (t.kind == quit)
            return;
        ts.putback(t);
        cout << result << statement() << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}

int main() 
try {
    table.declare("pi", 3.14159, true);
    table.declare("e", 2.71828, true);
    table.declare("k", 1000, true);
    calculate();
    return 0;
}
catch (runtime_error& e) {
    cerr << "runtime error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown error!\n";
    return 2;
}