#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
#include <math.h>     

using namespace std;

int main()
{
#pragma region 4.2

	//vector<double> temps;
	//for (double temp; cin >> temp; )
	//	temps.push_back(temp);

	//double sum = 0;
	//for (double x : temps) sum += x;
	//cout << "avg temp : " << sum / temps.size() << endl;

	//sort(temps.begin(), temps.end());
	//if (temps.size() % 2 == 1)
	//	cout << "middle temp : " << temps[temps.size() / 2] << endl;
	//else
	//{
	//	double sum = temps[temps.size() / 2 - 1] + temps[temps.size() / 2];
	//	double middle = sum / 2.0;
	//	cout << "middle temp : " << middle << endl;
	//}

#pragma endregion
	
#pragma region 4.9

	//int cur_squre = 0;
	//int cur_grain = 0;
	//int cum_grain = 0;
	//int tot_num;

	//cout << "input tot_num" << endl;
	//cin >> tot_num;

	//for (cur_squre = 1; cur_squre <= tot_num; cur_squre++)
	//{
	//	cur_grain = pow(2, cur_squre - 1);
	//	cum_grain += cur_grain;
	//	cout << "Square number : " << cur_squre << " | cur_grain : " << cur_grain << " |  cum_grain : " << cum_grain << endl;
	//}

#pragma endregion
	
#pragma region 4.10

	//vector<int> rand = { 7,34,7,8,43,2,4,5,7,89,5,43,2,5,86,34,2,3,65,5,1,2,3,6,8,7,54,3,32,2,34,6,5,78,6,3,23,3,4,3,4,2,1,4,6,5,7,8, };
	//int seed;

	//cout << "input seed number!" << endl;
	//cin >> seed;

	//sort(rand.begin(), rand.end());
	//int dev = rand[seed%rand.size()]/3;
	//char trial_com;
	//switch (dev)
	//{
	//case 0:
	//	trial_com = 'r';
	//	break;

	//case 1:
	//	trial_com = 's';
	//	break;

	//case 2:
	//	trial_com = 'p';
	//	break;
	//default:
	//	cout << "Fuck you noob programmer" << endl;
	//	break;
	//}


	//char trial;
	//cout << "Ok Let's play. input r,s,p" << endl;
	//cin >> trial;

	//switch (trial)
	//{
	//case 'r':
	//	if (trial == trial_com)
	//		cout << "Draw" << endl;
	//	else if (trial_com == 's')
	//		cout << "You win" << endl;
	//	else
	//		cout << "You lose" << endl;
	//	break;

	//case 's':
	//	if (trial == trial_com)
	//		cout << "Draw" << endl;
	//	else if (trial_com == 'p')
	//		cout << "You win" << endl;
	//	else
	//		cout << "You lose" << endl;
	//	break;

	//case 'p':
	//	if (trial == trial_com)
	//		cout << "Draw" << endl;
	//	else if (trial_com == 'r')
	//		cout << "You win" << endl;
	//	else
	//		cout << "You lose" << endl;
	//	break;
	//default:
	//	cout << "Fuck you wrong input" << endl;
	//	break;
	//}


#pragma endregion

#pragma region  4.11~12

//vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//vector<int> finds;
//
//int max;
//cout << "input max" << endl;
//cin >> max;
//
//for (int i = 2; i <= max; i++)
//{
//	bool isPrime = true;
//	for (int j = 2; j < i; j++)
//	{
//		if (i%j == 0)
//			isPrime = false;
//	}
//	if (isPrime == true)
//		finds.push_back(i);
//}
//
//for (int x : finds) cout << x << endl;

#pragma endregion

#pragma region  4.13

//vector <int> sieve;
//
//for (int i = 2; i <= 100; i++)
//	sieve.push_back(i);
//
//for (int i =2; i <= 100; i++)
//{
//	for (int j = i*i ; j <= 100; j++)
//	{
//		if (i != j)
//		{
//			if (j%i == 0)
//				sieve[j-2] = 0;
//		}
//	}
//}
//
//for (int x : sieve)
//{
//	if (x != 0)
//		cout << x << endl;
//}


#pragma endregion

#pragma region 4.15

//int n;
//vector <int> primes;
//
//cout << "input n!" << endl;
//cin >> n;
//
//int max = numeric_limits<int>::max();
//
//for (int i = 2; i <= max; i++)
//{
//	bool isPrime = true;
//	for (int j = 2; j < i; j++)
//	{
//		if (i%j == 0)
//			isPrime = false;
//	}
//	if (isPrime == true)
//		primes.push_back(i);
//
//	if (primes.size() == n)
//		break;
//}
//
//for (int x : primes)
//cout << x << endl;


#pragma endregion

#pragma region 4.16

//vector<int> sequance = { 1,5,6,4,3,6,5,3,3,3,3,3,3,3,3,3,32,34,3,1,45,1,32,5,5,21,2,3,5,7,8,67,5,4,3,6,7,5,3,2,54,6,5,3,2,54,4,5,3,23,3,4,7,4,2,34,5 };
//int mode = 0;
//int modeNum = 0;
//int tempMode = 0;
//int tempNum = 0;
//
//for (int i = 0; i < sequance.size(); i++)
//{
//	tempMode = sequance[i];
//	tempNum = 1;
//
//	for (int j = 0; j < sequance.size(); j++)
//	{
//		if (i != j && sequance[i] == sequance[j])
//		{
//			tempNum++;
//		}
//	}
//
//	if (mode == 0)
//	{
//		mode = tempMode;
//		modeNum = tempNum;
//	}
//	else
//	{
//		if (mode != tempMode && tempNum > modeNum)
//		{
//			mode = tempMode;
//			modeNum = tempNum;
//		}
//	}
//}
//
//cout << "mode is " << mode << ", repeated " << modeNum << "times" << endl;

#pragma endregion

#pragma region 4.18

//double a, b, c;
//double x1, x2;
//
//cout << "ax^2+bx+c = 0 solve" <<endl << "input a,b,c in order" << endl;
//cin >> a >> b >> c;
//
//double sqrtVal = sqrt(b*b - 4 * a*c);
//x1 = (-b + sqrtVal) / (2 * a);
//x2 = (-b - sqrtVal) / (2 * a);
//
//cout << "x1 is " << x1 << ", x2 is " << x2 << endl;

#pragma endregion

#pragma region  4.19~21

//vector<string> names;
//vector<int> numbers;
//
//string name;
//int number;
//
//while (name != "joy")
//{
//	cout << "input name , number" << endl;
//	cin >> name >> number;
//
//	for (string n : names)
//	{
//		if (name == n)
//		{
//			cout << "same name, Fuck you" << endl;
//			abort();
//			break;
//		}
//	}
//
//	if (name == "joy")
//		break;
//
//	names.push_back(name);
//	numbers.push_back(number);
//}
//
//for (int i = 0; i < names.size(); i++)
//{
//	cout << names[i] << " : " << numbers[i] << endl;
//}

#pragma endregion

	return 0;
}