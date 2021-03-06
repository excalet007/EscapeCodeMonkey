
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ch.5_q14

int main()
{
	vector<int> nums(7);
	
	vector<string> mon = { "Monday", "Mon", "monday", "mon" };
	vector<string> tues= {"Tuesday", "Tues", "tuesday", "tues" };
	vector<string> wed = {"Wednesday", "Wed", "wednesday", "wed"};
	vector<string> thur = {"Thursday", "Thur", "thursday", "thur"};
	vector<string> fri = {"Friday", "Fri", "friday", "fri"};
	vector<string> sat = { "Saturday", "Sat", "saturday", "sat"};
	vector<string> sun = {"Sunday", "Sun", "sunday", "sun" };

	vector<vector<string>> week = { mon, tues, wed, thur, fri, sat, sun };

	string day;
	int num;
	int deny = 0;

	while (cin)
	{
		cout << "input Day and Numbers" << endl;
		cin >> day >> num;
		
		bool isMatch = false;
		int index = 0;

		for (vector<string> x : week)
		{
			for (string y : x)
			{
				if (day == y)
				{
					isMatch = true;
					break;
				}
			}
			
			if (isMatch)
			{
				nums[index] += num;
				break;
			}

			index++;
		}

		if (!isMatch)
			deny++;

		day = "";
		num = 0;
	}

	cout << "Mon : " << nums[0] << "| Tues : " << nums[1] << "| Wed  : " << nums[2] << "| Thur : " << nums[3] 
		<< "| Fri : " << nums[4] << "| Sat : " << nums[5] << "| Sun : " << nums[6] << endl;


	cout << "Denied value Count : " << deny << endl;

    return 0;
}

