#include "std_lib_facilities.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};
class Token_stream {
public:
	Token_stream()
		:full(false), buffer(NULL) {}// make a Token_stream that reads from cin
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

void Token_stream::putback(Token t)
{
	if (full) cout << "가득찬 버퍼에 putback()넣냐 븅신 ㅋㅋ" << endl;
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;  
	switch (ch)
	{
	case ';':
	case 'q':
	case '{' : case '}' :case '(': case ')': case '+': case'-': case '*': case '/':
		return Token{ ch };
	case '.':
	case '0': case'1': case'2': case'3': case'4':
	case'5': case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };
	}
	default:
		cout << "잘못된 토큰이여 븅신" << endl;
		break;
	}
	return Token(' ');
}

Token_stream ts = Token_stream(); // get과 putback 제공
double expression(); // primary가 expression 호출 제공

double secondary() {
	Token t = ts.get();
	switch (t.kind)
	{
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') cout << "'}' 가 나와야함" << endl;
		return d;
	}
	case '8':
		return t.value;

	default:
		cout << "Secondary 가 나와야해욧 " << endl;
		break;
	}
	return 0.0;
}

double primary()
{
	double left = secondary();
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') cout << "')' 가 나와야함" << endl;
		return d;
	}
	case '8':
		return t.value;

	default:
		cout << "Primary 가 나와야해욧 " << endl;
		break;
	}
	return 0.0;
} // 숫자와 괄호처리

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;

		case '/':
		{
			double d = primary();
			if (d == 0) cout << ("영으로 나누기") << endl;
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
			break;
		}
	}
} // * / 처리
double expression()
{
	double left = term(); 
	Token t = ts.get(); 
	while (true)
	{
		switch (t.kind)
		{
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
} // + - 처리

int main()
{
	try {
		double val = 0;
		while (cin)
		{
			Token t = ts.get();
			if (t.kind == 'q') break;
			if (t.kind == ';')
				cout << "=" << val << endl;
			else
				ts.putback(t);
			val = expression();
		}
		system("pause");
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		system("pause");
		return 1;
	}

	return 0;
} // 메인 루프와 오류 처리

