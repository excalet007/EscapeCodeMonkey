// SpaceChangerCH11Awesome.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "std_lib_facilities.h"


const int space = 32;
vector<int> space_asc{46,59,44,63,45,39};

istream& operator>> (istream& is, vector<int>& ascs)
{
	while (is.good())
	{
		int n = is.get();
		for (int x : space_asc)	if (n == x) n = space;
		cout << (char)n;
	}
	return is;
}

int main()
{
	cin >> space_asc;
    return 0;
}

