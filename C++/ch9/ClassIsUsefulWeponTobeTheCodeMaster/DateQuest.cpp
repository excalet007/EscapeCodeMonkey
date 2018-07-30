#include "stdafx.h"
#include "chrono.h"
#include <string>

using namespace std;

int main()
{
	try
	{
		//cout << Chrono::Month::mar << endl;
		Chrono::Date holiday(1978, Chrono::Month::jul, 4); // initialization
		cout << "holiday is " << holiday << endl;
		Chrono::Date test{ 11,Chrono::Month::jul, 3 };
		Chrono::Day nDay = test.day_of_week(test);
		return 0;
	}
	catch (Chrono::Date::Invalid&) {
		cerr << "error: Invalid date\n";
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}
