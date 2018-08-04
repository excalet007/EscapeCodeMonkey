#include "Graph.h"
#include "Simple_window.h"


int main()
{

	Point tl(150, 150);
	Simple_window win(tl, 800, 600, "My window");

	Axis xa{ Axis::x, Point{20, 400}, 280, 10, "x axis" };
	Axis ya{ Axis::y, Point{ 20, 400 }, 280, 10, "y axis" };

	xa.set_color(Color::black);
	ya.set_color(Color::black);

	Function sine{ sin, 0,100, Point{20,150}, 1000,50 };
	sine.set_color(Color::red);

	Image ig{ Point{30,50}, "image.jpg" };
	win.attach(ig);

	Graph_lib::Rectangle r{ Point {200,200}, 100, 50 };
	r.set_color(Color::blue);
	r.set_fill_color(Color::blue);
	r.set_style(Line_style(Line_style::dash, 4));

	//Graph_lib::Text aa{ POINT{ 150,150 }, "HelloWorld" };
	//win.attach(aa);


	win.attach(r);
	win.attach(sine);
	win.attach(xa);
	win.attach(ya);

	win.wait_for_button();
}