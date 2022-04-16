#include <iostream>
#include "Point.h"

void Point::info() {
	std::cout << "(x,y) = " << x << ", " << y << std::endl;
}

double Point::getx()
{
	return x;
}

double Point::gety()
{
	return y;
}

void Point::get(double& xinput, double& yinput)
{
	xinput = x;
	yinput = y;
}