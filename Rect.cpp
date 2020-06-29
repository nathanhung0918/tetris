#include "Rect.h"
#include "Object.h"
#include "Point.h"




Rect::Rect(const int left, const int top, const int right, const int bottom)
{
	orgX = left;
	orgY = top;
	width = right;
	height = bottom;
}	

void Rect::drawBoundary()const
{
    int i;
    gotoxy(orgX-1, orgY-1);
    cout << '+';
    for (i=0; i<width; i++)
        cout << '-';
    cout << '+';

    for (i=0; i<height; i++)
    {
        gotoxy(orgX-1, orgY+i); cout << '|';
        gotoxy(orgX+width, orgY+i); cout << '|';
    }

    gotoxy(orgX-1, orgY+height);
    cout << '+';
    for (i=0; i<width; i++)
        cout << '-';
    cout << '+';
    gotoxy(1,23); // 把游標移動到視窗中固定的地方, 
}                 // 否則在畫面上會一直看到游標在不同地方閃啊閃的


bool Rect::contains(const Point &pt) const // 判斷是否包含傳入的點
{
	if(pt.mx <= orgX-1 || pt.mx >= orgX+width-1 || pt.my <= orgY || pt.my >= orgY+height-1)
	return false;
	return true;
}

bool Rect::contains(const Object &obj) const
{

if(obj.isInside(*this))
	{
	return true;
	}
	return false;
}


Rect::~Rect(void)
{
}
