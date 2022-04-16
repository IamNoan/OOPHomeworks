#include "Point.h"
#include "Circle.h"
#include <iostream>

using namespace std;
int main(void) {

	/*double x, y;
	Point p{ 10.5, 20.99 };
	p.info();
	p.get(x, y);
	cout << x << ", " << y << endl;*/

	Circle c1;
	Circle c2{};
	Point p{ 10.5, 20.5 };
	Circle c3{ p, 20.0 };
	Circle c4{ 20.5, 10.5, 10.0 };
	cout << "c1.info: "; c1.info();
	cout << "c2.info: "; c2.info();
	cout << "c3.info: "; c3.info();
	cout << "c4.info: "; c4.info();

	Point ins{ 25.0,8.0 };

	Point cp{ ins };
	cout << "ins_cp.info: "; cp.info();

	cout << "\nArea of c3: " << c3.area() << endl;
	cout << "Center of c3: ";
	cout << "[" << p.getx() << ", " << p.gety()
		<< "]\n";
	cout << "Radius of c3: " << c3.getradius() << endl;
	cout << "IsInside: " << c4.IsInside(ins) << endl << endl;

	return 0;
}
