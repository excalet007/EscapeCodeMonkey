#include "stdafx.h"
#include "temp_stats.h"
#include <cmath>

using namespace std;

double Get_FahFromCel(double cel)
{
	return 1.8*cel + 32;
}

double Get_average(vector<Reading>& vr)
{
	double sum{ 0 };
	double count{ 0 };

	for (int i = 0; i < (int)vr.size(); i++)
	{
		count++;
		if (vr[i].is_celcius) sum += Get_FahFromCel(vr[i].temperature);
		else sum += vr[i].temperature;
	}
	return sum / count;
}

double Get_median(vector<Reading>& vr)
{
	double sum{ 0 };
	int f;
	int b;
	
	if (vr.size() == 1)
	{
		if (vr[0].is_celcius) sum += Get_FahFromCel(vr[0].temperature);
		else sum += vr[0].temperature;
		return sum;
	}
	else if (vr.size() % 2 == 0)
	{
		f = vr.size() / 2 - 1;
		b = vr.size() / 2;

	}
	else if (vr.size() % 2 != 0)
	{
		f = vr.size() / 2;
		b = vr.size() / 2 +1;
	}

	if (vr[f].is_celcius) sum += Get_FahFromCel(vr[f].temperature);
	else sum += vr[f].temperature;

	if (vr[b].is_celcius) sum += Get_FahFromCel(vr[b].temperature);
	else sum += vr[b].temperature;

	return sum / 2;
}
