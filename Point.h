#pragma once
#include "utilwin32.h"
#include <iostream>
using namespace std;

class Rect;
class Point{
public:
Point(); // �w�]�غc��
Point(const int x, const int y); // �غc��
Point operator+(const Point &rhs) const; // �p�����I���V�q�M
bool isInside(const Rect &rect) const; // �P�_�I�O�_�b�ǤJ���x�ΰ϶���
int mx,my;
void shaping();
};
