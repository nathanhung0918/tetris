#pragma once
#include "utilwin32.h"
#include "Point.h"
#include <iostream>
#include <vector>
using namespace std;

class Rect;

class Object{
public:
Object(const char face, const Point position, const Point data[][4],const int); // 建構元
bool move(const Point &offset, const Rect &boundary); // 移動 offset 位移
bool isInside(const Rect &rect) const; // 檢查物件是否在矩形區域 rect 中
void draw(bool show=true) const; // 繪製 (true), 清除 (false)
void pause(int);
//int check(const Rect &rect);
void check(int check[25][16],const int,const int);
bool checkdraw(const int check[25][16],Point &);
bool checkleft(const Rect &rect,const int check[25][16]);
bool checkright(const Rect &rect,const int check[25][16]);
bool checkdown(const Rect &rect,const int check[25][16]);
bool turnleft(Point&,Rect&);
bool turnright(Point&,Rect&);
void godown(Rect &boundary,const int check[25][16]);
void checkkb(int,Point&,Point&,Rect&,int check[25][16]);
int checkline(int check[25][16],int);
bool checklose(int check[25][16]);
void drawcheck(int check[25][16],const int,const int,const int,const int);
char mFace;
Point mData[4];
Point mPosition;
void swap();
};