#include <iostream>

class Point
{
public:
	void output()
	{

	}

	static void init()
	{
		x = 0;
		y = 0;
	}

private:
	//int x, y;
	static int x, y;
};

int Point::x = 0;
int Point::y = 0;

void main()
{
	//Point pt;
	//pt.init();
	//pt.output();

	Point::init();
	//Point::output();
}