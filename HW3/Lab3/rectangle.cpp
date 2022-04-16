#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
    if ((ul.GetX() > lr.GetX()) && (ul.GetY() > lr.GetY()))
    { 
        m_upLeft = lr;
        m_lowRight = ul;
        return true;
    }
    else if ((ul.GetX() > lr.GetX()) || (ul.GetY() > lr.GetY()))
        return false;

    m_upLeft = ul;
    m_lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const {
    cout << "LeftTop: " << '[' << m_upLeft.GetX() << ", ";
    cout << m_upLeft.GetY() << ']' << endl;
    cout << "RightBottom: " << '[' << m_lowRight.GetX() << ", ";
    cout << m_lowRight.GetY() << ']' << endl << endl;
}

bool Rectangle::IsInside(const Point& pos)
{
    int x = pos.GetX();
    int y = pos.GetY();
    if (x<m_lowRight.GetX() && x>m_upLeft.GetX() && y>m_upLeft.GetY() && y<m_lowRight.GetY())
    {
        return true;
    }
    return false;
}