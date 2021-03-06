#include "stdafx.h"
#include "store_temps.h"
#include "constVal.h"

#include <fstream>

using namespace std;

istream& operator>>(istream& is, Reading& r)
{
	char oBracket;

	if (is >> oBracket && oBracket != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
	}

	int input_hour;
	char comma;
	double input_temp;
	char char_tempType;
	char cBracket;

	is >> input_hour >> comma >> input_temp >> char_tempType >>cBracket;

	switch (char_tempType)
	{
	case 'c':
		r.is_celcius = true;
		break;

	case 'f':
		r.is_celcius = false;
		break;

	default:
		break;
	}

	r.hour = input_hour;
	r.temperature = input_temp;

	return is;
}
istream& operator>>(istream& is, vector<Reading>& vr)
{
	char oBracket;

	if (is >> oBracket && oBracket != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);
	}
	
	char cBracket;

	while(is >> cBracket)
	{
		Reading r;
		is.unget();
		is >> r;
		vr.push_back(r);

		char comma;
		if (is >> comma && comma == '}')
		{
			is.unget();
			break;
		}
	}

	return is;
}
ostream& operator<<(ostream& os,const Reading& r)
{
	ofstream file;
	file.open(testPath,ios_base::app);
	file << '(' << r.hour << ',' << r.temperature;
	
	if (r.is_celcius) file << 'c';
	else file << 'f';
	
	file << ')';	
	return os;
}
ostream& operator<<(ostream& os, const vector<Reading>& vr)
{
	ofstream file;
	file.open(testPath, ios_base::app);
	file << '{';
	file.close();

	for (int i = 0; i < (int)vr.size()-1; i++)
	{
		file << vr[i];
		file.open(testPath, ios_base::app);
		file << ',';
		file.close();
	}
	
	file.open(testPath, ios_base::app);
	file << vr[vr.size()-1] << '}';;
	file.close();
	return os;
}