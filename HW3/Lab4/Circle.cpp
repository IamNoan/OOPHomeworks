#include "Circle.h"
#include <iostream>
#include <cmath>
# define MY_PI 3.14159265358979323846

void Circle::info() 
{
	std::cout << "Center: [" << center.getx() << ", " << center.gety() << "], Radius: " << radius << std::endl;
}

double Circle::area()
{
	double a = MY_PI * radius * radius;
	return a;
}

Point Circle::getcenter()
{
	return Point();
}

double Circle::getradius()
{
	return radius;
}

bool Circle::IsInside(Point p)
{
	if (p.getx()<(center.getx() + radius) && p.getx() > (center.getx() - radius)
		&& p.gety() < (center.gety() + radius) && p.gety() > (center.gety() - radius))
	{
		return true;
	}
	return false;
}
