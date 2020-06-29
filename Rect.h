#include "utilwin32.h"
#include <iostream>
using namespace std;

class Object;
class Point;
class Rect
{
public:
	
	~Rect(void);
	Rect(const int left, const int top, const int right, const int bottom); // �غc��
	bool contains(const Point &pt) const; // �P�_�O�_�]�t�ǤJ���I
	bool contains(const Object &obj) const; // �P�_�O�_�]�t�ǤJ����Ӫ���
	//void draw() const; // ø�s�x�Ϊ����
	void drawBoundary()const;
	int orgX, orgY, width, height;
};

