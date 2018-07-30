#include "stdafx.h"
#include <iostream>

namespace Chrono {

	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	class Date {
	public:
		// construction
		class Invalid {};
		Date(int y, Month m, int d);
		Date();

		//const operation
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		//non-const operation
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		Day day_of_week(const Date& d);

	private :
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Month m, int d);
	bool leapyear(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<< (std::ostream& os, const Date& d);
	std::istream& operator>> (std::istream& is, const Date& d);

}