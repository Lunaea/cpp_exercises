/*#include "std_lib_facilities.h"

class Token {
public:
	char kind{};
	double value{};
};

double primary();
double term();
Token get_token();

double expression() {
	double left = term();
	Token t = get_token();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = get_token();
			break;
		case '-':
			left -= term();
			t = get_token();
			break;
		default:
			return left;
		}
	}
}

double term() {
	double left = primary();
	Token t = get_token();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = get_token();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left /= d;
			t = get_token();
			break;
		}
		default:
			return left;
		}
	}
}

double primary() {
	Token t{ get_token() };
	switch (t.kind) {
	case '(':
	{
		double d{ expression() };
		t = get_token();
		if (t.kind != ')')
			error("')' expected");
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
	}
}
int main()

try {
	while (cin)
		cout << expression() << '\n';
	keep_window_open();
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open();
	return 2;
}*/