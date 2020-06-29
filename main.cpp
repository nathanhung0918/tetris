#include "utilwin32.h"
//#include <conio.h>
#include <iostream>
#include "Point.h"
#include "Rect.h"
#include "Object.h"
#include <assert.h>
#include <time.h>
using namespace std;

int main()
{
	
	Point right(1,0);
	Point left(-1,0);
	int kb = -1;
	int count = 0;
	int points = 0;
	const int orgX = 10, orgY = 5, width = 25, height = 16;
	int check[width][height];
	for(int i = 0;i<width;i++)
		for(int j=0;j<height;j++)
			check[i][j] = 0;
	Rect canvas(orgX, orgY, width-1, height-1);
	clrscr();
	canvas.drawBoundary();
	const Point shape[7][4] = {{ Point(-1,0),Point(0,0)	,Point(0,1)	,Point(0,2)	},{ Point(0,0)	,Point(1,0)	,Point(0,1)	,Point(0,2)	},{ Point(0,0)	,Point(0,1)	,Point(0,2)	,Point(0,3)	},{ Point(0,0)	,Point(0,1)	,Point(0,2)	,Point(1,1)	},{ Point(0,0)	,Point(1,0)	,Point(0,1)	,Point(1,1)	},{ Point(0,1)	,Point(0,0)	,Point(1,1)	,Point(1,2)	},{ Point(0,1)	,Point(0,2)	,Point(1,1)	,Point(1,0)	}};	

	while(1){
		srand( (unsigned)time(NULL) );
		int shapenumber = rand()%7;
		Object obj('*', Point(orgX+width/2-1,orgY), shape,shapenumber);
		points = obj.checkline(check,points); //確認有沒有消排得分
		clrscr();
		canvas.drawBoundary();
		gotoxy(60,3);
		cout << "按上來旋轉方塊";
		gotoxy(60,4);
		cout << "按下來降到最下面";
		gotoxy(60,5);
		cout << "按左右來移動";
		gotoxy(60,6);
		cout << "按p來暫停";
		gotoxy(60,10);
		cout << "目前得分：" << points;
		if(points>0)
		{
		for(int i = 0;i<width;i++)
			check[i][height] = 0;
		
		}
		else
		obj.drawcheck(check,width,height,orgX,orgY); //印出已經觸碰到邊界的方塊
		obj.draw();
		while (1)
		{
			if(count++ % 6 == 0)//slow
			{
				if(!obj.checkdraw(check,Point(0,1))) //not downing
					break;
				if(!obj.move(Point(0,1), canvas))
					break;
			}
			delay(80);
			obj.checkkb(kb,left,right,canvas,check);
			if(!obj.checkdraw(check,Point(0,1)))
				break;
		}
		obj.check(check,orgX,orgY);
		if(!obj.checklose(check))
			break;
	}
	gotoxy(1,26); 
	cout << "你輸了:(    \n";
	system("pause");

	}





