// IORegulationCH11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	double num{ 1234567.89 };

	cout << setprecision(5);
	cout << defaultfloat << num << endl;

	cout << setprecision(5);
	cout << fixed << num << endl;
	cout << scientific << num << endl;

    return 0;
}

