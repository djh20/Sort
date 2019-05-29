#ifndef RECT
#define RECT
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;
class Rectangle
{
	int height;
	int width;
public:
	int getArea() const;
	void setWidth(int value) { width = value; };
	void setHeight(int value) { height = value; };
	friend ostream& operator <<(ostream &out, Rectangle operand);
	bool operator>(const Rectangle &operand) const;
	bool operator>=(Rectangle operand);
	bool operator<(Rectangle operand);
	bool operator<=(Rectangle operand);
	bool operator==(Rectangle operand);
	void operator=(Rectangle operand);

	Rectangle();
	~Rectangle();
};
#endif
