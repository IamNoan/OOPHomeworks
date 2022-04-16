#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>

using namespace std;

class Point {

	double x;
	double y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double a, double b) : x(a), y(b)
	{}
	void info();
	double getx();
	double gety();
	void get(double&, double&);
};

#endif