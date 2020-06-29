#pragma once
#include "utilwin32.h"
#include <iostream>
using namespace std;

class Rect;
class Point{
public:
Point(); // 預設建構元
Point(const int x, const int y); // 建構元
Point operator+(const Point &rhs) const; // 計算兩個點的向量和
bool isInside(const Rect &rect) const; // 判斷點是否在傳入的矩形區間內
int mx,my;
void shaping();
};
