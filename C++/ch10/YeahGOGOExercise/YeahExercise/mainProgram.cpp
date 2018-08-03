#include "stdafx.h"
#include "constVal.h"
#include "store_temps.h"
#include "temp_stats.h"

using namespace std;

int main()
{
	vector<Reading> readings;
	ofstream file;
	file.open(testPath);
	file.clear();

	cout << "plz input Readings" << endl;

	cin >> readings;
	file << readings;

	file.close();

	vector<Reading> readings2;

	ifstream file2;
	file2.open(testPath);

	istream& is = file2;
	operator>>(is, readings2);

	file2.close();
	
	cout << "avg fahrenheit is : " << Get_average(readings2) << endl;
	cout << "avg median is : " << Get_median(readings2) << endl;

	return 0;
}