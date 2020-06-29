#include"Point.h"
#include"Rect.h"


const int change[4] = {0,-1,1,0};
Point::Point()
{

}

Point::Point(int x,int y)
{
	mx = x;
	my = y;
}

Point Point::operator+(const Point &rhs) const
{
	Point temp(mx+rhs.mx,my+rhs.my);
	return temp;
}

bool Point::isInside(const Rect &rect) const
{
if (mx <= rect.orgX || mx >= rect.orgX+rect.width || my <= rect.orgY || my >= rect.orgY+rect.height)
	return false;
return true;
}


void Point::shaping()
{
	int temp1 = mx*change[0] + my*change[1];
	int temp2 = mx*change[2] + my*change[3];
	mx = temp1;
	my = temp2;
}