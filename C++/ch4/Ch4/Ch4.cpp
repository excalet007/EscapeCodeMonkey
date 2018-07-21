// Ch4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	vector<string> words;
	for (string temp; cin >> temp;)
		words.push_back(temp);


	cout << "num of words : " << words.size() << endl;

	sort(words.begin(), words.end());


	int words_size = words.size();

	for (int i = 0; i < words_size; i++)
	{
		if (i == 0 || words[i - 1] != words[i])
			cout << words[i] << endl;
	}

	//vector<double> temps;
	//for (double temp; cin >> temp; )
	//	temps.push_back(temp);

	//double sum = 0;
	//for (double x : temps) sum += x;
	//cout << "avg temp : " << sum / temps.size() << endl;

	//sort(temps.begin(), temps.end());
	//cout << "middle temp : " << temps[temps.size() / 2] << endl;
		
	return 0;
}

