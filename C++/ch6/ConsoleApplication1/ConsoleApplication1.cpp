// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Token
{
public : 
	char kind;
	double value;
};


//Token get_token();
//
//double expression()
//{
//	double left = expression();
//	Token t = get_token();
//	switch (t.kind)
//	{
//	case '+':
//		return left + term();
//		break;
//
//	case '-':
//		return left - term();
//		break;
//
//	default :
//		return left; 
//	}
//}


vector<Token> make_token(string x)
{
	vector<Token> rToken;



	return rToken;
}

int main()
{

	string aa = "";
	cin >> aa;
	cout << aa << endl;

	system("pause");
    return 0;
}

