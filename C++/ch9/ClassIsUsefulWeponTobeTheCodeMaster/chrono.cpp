#include "stdafx.h"
#include "chrono.h"
#include <iostream>

namespace Chrono {

	Month operator++(Month& m)
	{
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
		return m;
	}

	Day operator++(Day& day)
	{
		day = (day == Day::saturday) ? Day::sunday : Day(int(day) + 1);
		return day;
	}


	// member Fuction
	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	const Date& default_date()
	{
		static Date dd{ 1970,Month::jan,1};
		return dd;
	}

	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{

	}

	void Date::add_day(int n)
	{
		for (int i = 0; i < n; i++)
		{
			switch (m)
			{
			case Chrono::Month::apr:
			case Chrono::Month::jun:
			case Chrono::Month::sep:
			case Chrono::Month::nov:
				++d;
				if (d > 30) ++m;
				break;

			case Chrono::Month::jan:
			case Chrono::Month::mar:
			case Chrono::Month::may:
			case Chrono::Month::jul:
			case Chrono::Month::aug:
			case Chrono::Month::oct:
				++d;
				if (d > 31) ++m;
				break;

			case Chrono::Month::feb:
				++d;
				if (leapyear(y) && d > 29) ++m;
				if (!leapyear(y) && d > 28) ++m;
				break;

			case Chrono::Month::dec:
				++d;
				if (d > 30) ++m;
				++y;
				break;

			default:
				std::cout << "오류닷 ㅄ" << std::endl;
				break;
			}
		}
	}

	void Date::add_month(int n)
	{
		// ㅈ까
	}

	void Date::add_year(int n)
	{
		// 올해가 윤년에 29일이냐는 의미임
		if (m == Month::feb && d == 29 && !leapyear(y + n))
		{
			m = Month::mar;
			d = 1;
		}
		y += n;
	}
	
	// helper function
	bool is_date(int y, Month m, int d)
	{
		// let y is valid

		if (d <= 0) return false;
		if (m<Month::jan || m> Month::dec) return false;

		int days_in_month = 31;

		switch (m)
		{
		case Chrono::Month::feb:
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Chrono::Month::apr:
		case Chrono::Month::jun:
		case Chrono::Month::sep:
		case Chrono::Month::nov:
			days_in_month = 30;
			break;
		}

		if (d > days_in_month) return false;

		return true;
	}

	bool leapyear(int y)
	{
		bool is_leap = false;

		if (y % 4 == 0)
		{
			is_leap = true;
			if (y % 100 == 0)
			{
				is_leap = false;
				if (y % 400 == 0)
				{
					is_leap = true;
				}
			}
		}

		return is_leap;
	}

	bool operator==(const Date&a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator!=(const Date&a, const Date& b)
	{
		return !(a == b);
	}

	//Operator 

	std::ostream& operator<< (std::ostream& os, const Month& m)
	{
		return os << int(m);
	}

	std::ostream& operator<< (std::ostream& os, const Date& d)
	{
		return os << "(" << d.year() << ", " << d.month() << ", " << d.day() << ")";
	}

	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		dd = Date(y, Month(m), d);

		return is;
	}





	Day day_of_week(const Date& d)
	{
		Date originDate{ 1,Month::jan,1 };
		Day originDay{ Day::monday };

		Date copy{ d.year(), d.month(), d.day() };
		int repeater = 0;

		while (originDate.year() < copy.year() || (int)originDate.month < (int)copy.month() || originDate.day < copy.day())
		{
			originDate.add_day(1);
			++originDay;
			++repeater;
		}

		std::cout << repeater;
		return originDay;
	}

	//Date next_Sunday(const Date& d)
	//{

	//}

	//Date next_weekday(const Date&d)
	//{

	//}

}