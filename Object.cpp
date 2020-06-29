#include"Object.h"
#include"Rect.h"
#include <conio.h>

Object::Object(const char face, const Point position, const Point data[][4],const int number)
{
	 mFace = face;
	 mPosition.mx = position.mx;
	 mPosition.my = position.my;
	 for(int i=0;i<4;i++){
	 mData[i].mx = data[number][i].mx;
	 mData[i].my = data[number][i].my;
	 }
}
void Object::draw(bool show) const
{
	if(show==true)
	{
		for(int i =0; i < 4; i++)
		{
			Point temp = mPosition.operator+(mData[i]);
			gotoxy(temp.mx,temp.my);
			cout << mFace;
		}
	}
	else
	{
		for(int i =0; i < 4; i++)
		{
			Point temp = mPosition.operator+(mData[i]);
			gotoxy(temp.mx,temp.my);
			cout << " ";
		}
	}


}
bool Object::move(const Point &offset, const Rect &boundary)
{
	draw(false);	
	mPosition = mPosition.operator+(offset);
	if(!isInside(boundary))
		return false;
	draw();
	return true;
}
void Object::check(int check[25][16],const int orgX,const int orgY)
{
	for(int i =0; i < 4; i++)
	{
		Point temp = mPosition.operator+(mData[i]);
		check[temp.mx-orgX+1][temp.my-orgY+1] = 1;
	}
}
bool Object::isInside(const Rect &rect) const
{
	for(int i = 0 ; i < 4; i++)
	{
		Point temp = mPosition.operator+(mData[i]);		
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
void Object::swap() //轉方向囉方塊們
{
	for(int i = 0; i < 4; i++)
	{
		mData[i].shaping();
	}
}
bool Object::checkdraw(const int check[25][16],Point &checkplace)
{
	Point temp1 = mPosition.operator+(checkplace);
	for(int i = 0; i < 4;i++)
	{
		Point temp = temp1.operator+(mData[i]);
		if(check[temp.mx-9][temp.my-4] == 1)
			return false;
	}
	return true;
}
bool Object::checkleft(const Rect &rect,const int check[25][16])
{
	for(int i = 0 ; i < 4; i++)
	{
		Point temp = mPosition.operator+(mData[i]);
		temp = temp.operator+(Point(-1,0));
		if(!checkdraw(check,Point(-1,0)))
			return false;
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
bool Object::checkright(const Rect &rect,const int check[25][16])
{
	for(int i = 0 ; i < 4; i++)
	{
		Point temp = mPosition.operator+(mData[i]);
		temp = temp.operator+(Point(1,0));
		if(!checkdraw(check,Point(1,0)))
			return false;
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
bool Object::checkdown(const Rect &rect,const int check[25][16])
{
	for(int i = 0 ; i < 4; i++)
	{
		Point temp = mPosition.operator+(mData[i]);
		temp = temp.operator+(Point(0,1));
		if(!checkdraw(check,Point(0,1)))
			return false;
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
bool Object::turnright(Point &right,Rect &boundary)
{
	draw(false);
	mPosition = mPosition.operator+(right);
	if(!isInside(boundary))
		return false;
	draw();
	return true;
}
bool Object::turnleft(Point &left,Rect &boundary)
{
	draw(false);
	mPosition = mPosition.operator+(left);
	if(!isInside(boundary))
		return false;
	draw();
	return true;
}
void Object::godown(Rect &boundary,const int check[25][16])
{
	while(true)
	{
		if(!checkdraw(check,Point(0,1)))
			break;
		if(!checkdown(boundary,check))
			break;
		if(!move(Point(0,1), boundary))
			break;
	}
}
void Object::checkkb(int kb,Point &left,Point &right,Rect &boundary,int check[25][16])
{
	while(kbhit())
	{
		kb = getch();
		if(kb == 72) //up key
		{
			if(checkleft(boundary,check))
				if(checkright(boundary,check))
				{
					draw(false);
					swap();
					draw();
				}
				gotoxy(1,26);
				cout << "你按了上鍵\n";
		}
		else if(kb == 75) //left key
		{
			if(checkleft(boundary,check))
				turnleft(left,boundary);
			gotoxy(1,26);
			cout << "你按了左鍵\n";
		}
		else if(kb == 77) // right key
		{
			if(checkright(boundary,check))
				turnright(right,boundary);
			gotoxy(1,26);
			cout << "你按了右鍵\n";
		}
		else if(kb == 80) //down key
		{
			godown(boundary,check);
			gotoxy(1,26);
			cout << "你按了下鍵\n";
		}
		else if(kb == 'p' || kb == 'P')
		{

			gotoxy(60,8);
			cout << "=暫停中=";
			gotoxy(1,26);
			cout << "你按了P或p鍵\n";
			pause(kb);
		}
	}
}
int Object::checkline(int check[25][16],int points)
{
	int i = 16;
	while(i >= 0 )
	{
		if(check[1][i] == 1 && check[2][i] == 1 && check[3][i] == 1 && check[4][i] == 1 && check[5][i] == 1 && check[6][i] == 1 && check[7][i] == 1 && check[8][i] == 1 && check[9][i] == 1 && check[10][i] == 1 && check[11][i] == 1  && check[12][i] == 1 && check[13][i] == 1 &&check[14][i] == 1 && check[15][i] == 1 && check[16][i] == 1 && check[17][i] == 1 && check[18][i] == 1 && check[19][i] == 1 && check[20][i] == 1 && check[21][i] == 1 && check[22][i] == 1 && check[23][i] == 1 && check[24][i] == 1)
		{
			for(int k = i;k >= 0;k--){
				for(int j = 0;j<25;j++)
				{
					if(i != 0)
						check[j][k] = check[j][k-1] ;
					else
						check[k][j] = 0;
				}
			}
			points++;
		}
		else
			i--;
	}
	return points;
}
bool Object::checklose(int check[25][16])
{
	for(int i = 0; i < 25; i++)
	{
		if(check[i][1] == 1)
			return false;
	}
	return true;
}
void Object::pause(int kb)
{
	while(true)
	{
		if(kbhit())
		{
			kb = getch();
			if(kb == 'p' || kb == 'P')
			{
				gotoxy(60,8);
				cout << "           ";
				break;
			}
		}
	}
}
void Object::drawcheck(int check[25][16],const int width,const int height,const int orgX,const int orgY)
{
	for(int i = 0; i < width;i++)
		for(int j = 0; j < height;j++)
		{
			if(check[i][j] == 1)
			{
				gotoxy(i+9,j+4);
				cout << mFace;
			}
		}
}