// NowWeCanUnderstandIOStream.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "custom.h"

using namespace std;

struct Point {
	double x;
	double y;
};

// Operator
istream& operator>>(istream& is, Point& p)
{
	char oBracket;

	if (is >> oBracket && oBracket != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
	}

	char cBracket;
	char comma;
	double xPoint;
	double yPoint;

	is >> xPoint >> comma >> yPoint >> cBracket;
	if (!is || cBracket != ')') error("잘못된 point 형식");

	p.x = xPoint;
	p.y = yPoint;

	return is;
}
istream& operator>>(istream& is, vector<Point>& vp)
{
	char oBracket;

	if (is >> oBracket && oBracket != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);
	}

	Point p1, p2, p3, p4, p5, p6, p7;
	char comma;
	char cBracket;

	is >> p1 >> comma >> p2 >> comma >> p3 >> comma >> p4 >> comma >> p5 >> comma >> p6 >> comma >> p7 >> cBracket;

	if (!is || cBracket != '}') error("잘못된 vector Point 형식");

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);
	vp.push_back(p6);
	vp.push_back(p7);

	return is;
}

ostream& operator<<(ostream& os, const Point& p)
{
	cout << "( " << p.x << ", " << p.y << " )";
	return os;
}
ostream& operator<<(ostream& os, const vector<Point>& vp)
{
	cout << "{ ";
	for (int i = 0; i < vp.size(); i++)
	{
		if (i == vp.size() - 1)
			cout << vp[i] << "}" << endl;
		else
			cout << vp[i] << ", ";
	}
	return os;
}


int main()
{
	// Initialize Vector
	vector<Point> original_points;
	original_points.clear();

	//Prompt
	cout << "Input 7 Vector Points, format { (x1, y1), (x2, y2), ... , (x7,y7) }" << endl;

	//Input
	cin >> original_points;
	cout << original_points;

	//Save

	//Load

	//Print

	//Compare	

    return 0;
}



//struct Reading {
//	int hour;
//	double temperature;
//};


//cout << "입력 파일 이름: ";
//string iname;
//cin >> iname;
//ifstream ist{ iname };
//if (!ist) error("입력 파일을 열 수 없엉...", iname);

//string oname;
//cout << "출력 파일 이름: ";
//cin >> oname;
//ofstream ost{ oname };
//if (!ost) error("출력 파일을 열 수 없엉...", oname);

//vector<Reading> temps;
//int hour;
//double temperature;
//while (ist >> hour >> temperature)
//{
//	if (hour < 0 || hour>23) error("시간이 아웃오브 범위요");
//	temps.push_back(Reading{ hour,temperature });
//}

//for (int i = 0; i < temps.size(); i++)
//{
//	ost << '(' << temps[i].hour << ',' << temps[i].temperature << ')' << endl;
//}