#include "Point.h"
#include <iostream>


class Circle
{
	Point center;
	double radius;
public:
	Circle() //Constructor with no parameter
	{
		Point c;
		center = c;
		radius = 0;
	}

	Circle(Point c, double r) : center(c), radius(r) //Constructor with 2 parameter
	{	}

	Circle(double x, double y, double r) //Constructor with 3 parameter
	{
		Point c{ x,y };
		center = c;
		radius = r;
	}

	~Circle()
	{
		std::cout << "Destruction of a class instance\n";
		std::cout << "Center: [" << center.getx() << ", " << center.gety() << "], Radius: " << radius << std::endl;
	}

	void info();
	double area();
	Point getcenter();
	double getradius();
	bool IsInside(Point p);
};

