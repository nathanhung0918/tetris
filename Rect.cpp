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
    gotoxy(1,23); // ���в��ʨ�������T�w���a��, 
}                 // �_�h�b�e���W�|�@���ݨ��Цb���P�a��{�ڰ{��


bool Rect::contains(const Point &pt) const // �P�_�O�_�]�t�ǤJ���I
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
