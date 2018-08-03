#pragma once
#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

struct Reading
{
	int hour;
	double temperature;
	bool is_celcius;
};

istream& operator>>(istream& is, Reading& r);
istream& operator>>(istream& is, vector<Reading>& vr);
ostream& operator<<(ostream& os, const Reading& r);
ostream& operator<<(ostream& os, const vector<Reading>& vr);