#include "utilwin32.h"
#include <iostream>
using namespace std;

class Object;
class Point;
class Rect
{
public:
	
	~Rect(void);
	Rect(const int left, const int top, const int right, const int bottom); // 建構元
	bool contains(const Point &pt) const; // 判斷是否包含傳入的點
	bool contains(const Object &obj) const; // 判斷是否包含傳入的整個物件
	//void draw() const; // 繪製矩形的邊界
	void drawBoundary()const;
	int orgX, orgY, width, height;
};

