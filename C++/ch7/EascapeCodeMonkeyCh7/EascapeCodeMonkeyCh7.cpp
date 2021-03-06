#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <std_lib_facilities.h>
#include <cmath>

using namespace std;

const char let = '#';
const char print = ';';
const char thousand = 'k';

const char number = '8';
const char quit = 'q';
const char name = 'a'; 
const char squareRoot = 's';
const char power = 'p';

const string quitKey = "exit";
const string squareRootKey = "sqrt";
const string powerKey = "pow";

const string promt = "> ";
const string result = "= ";



class Token {
public:
	char kind;     
	double value;    
	string name;
	Token(char ch)   
		:kind{ ch }, value{ 0 } { }
	Token(char ch, double val)   
		:kind{ ch }, value{ val } { }
	Token(char ch, string n)
		:kind{ ch }, name{ n }, value{ 0 } {}
};

class Token_stream {
public:
	Token_stream()
		:full(false), buffer(NULL) {}
	Token get();
	void putback(Token t);
	void ignore(char c);

private:
	bool full{ false };
	Token buffer;
};

class Variable {
public:
	string name;
	double value;
	Variable(string s, double val)
		:name(s), value(val) {}
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
	case print:
	case let:
	case '(': 
	case ')': 
	case '+': 
	case'-': 
	case '*': 
	case '/': 
	case '%':
	case '=':
		return Token{ ch };

	case 'k':
		return Token{ number, 1000 };

	case '.':
	case '0': case'1': case'2': case'3': case'4':
	case'5': case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ number, val };
	}
	default:
		if (isalpha(ch))
		{
			string s;
			s = ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == quitKey)	return Token(quit);
			if (s == squareRootKey) return Token(squareRoot);
			if (s == powerKey) return Token(power);
			return Token{ name,s };
		}
		error("잘못 토큰이에욧");
	}
	return Token(' ');
}
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;

}

Token_stream ts = Token_stream(); // get과 putback 제공
double expression(); 
vector<Variable> var_table;

double get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: 정의되지 않은 변수에욧 멍청아! >>", s);
}

void set_value(string s, double d)
{
	for(Variable& v: var_table)
		if (v.name == s)
		{
			v.value = d;
			return;
		}
	error("set : 정의되지 않은 변수에욧 ~!! : ", s);
}

double primary()
{
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
	case number:
		return t.value;

	case 'a':
	{
		for (Variable v : var_table)
			if (v.name == t.name) return v.value;
	}

	case '-' :
		return -primary();

	case '+':
		return +primary();

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
			if (d == 0) cout << ("영으로 나머지 찾지마") << endl;
			left /= d;
			t = ts.get();
			break;
		}
		
		case '%':
		{
			double d = primary();
			if (d == 0) error("0으로 나누지 마세요 븅시나");
			left = fmod(left, d);
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

void clean_up_mess()
{
	ts.ignore(print);
}

bool is_declared(string var) // check if var is in var_table
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}
bool define_name(string var, double val)
{
	if (is_declared(var)) error(var +"가 제정의되었습니다...쉬불탱");
	var_table.push_back(Variable(var, val));
	return val;
}

double declaration()
//name = expression 을 처리
{
	Token t = ts.get();
	if (t.kind != name) error("선언엔 이름이 필요하다능!");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("선언에서 =가 빠졌다능!!", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();

	case squareRoot:
	{
		double returnVal = sqrt(expression());
		return returnVal;
	}

	case power:
	{
		Token forTs = ts.get();
		Token backTs = ts.get();

		double returnVal = forTs.value;
		const double repeatVal = returnVal;
		
		int j = int(backTs.value);
		for(int i = 1; i<j ; i++)
		{
			returnVal *=repeatVal;
		}

		return returnVal;
	}

	default:
		ts.putback(t);
		return expression();
	}
}

void calculate()
{
	while (cin)
	{
		try 
		{
			cout << promt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << statement() << endl;
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
	}
}

int main()
{
	try {
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);
		
		calculate();

		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		keep_window_open("~~");
		return 1;
	}

} 

