#include "Rectangle.h"
using namespace std;
bool Rectangle::operator>(const Rectangle &operand) const
{
	if (this->getArea() > operand.getArea() == true)
		return true;
	else
		return false;
}

bool Rectangle::operator>=(Rectangle operand)
{
	if (this->getArea() >= operand.getArea() == true)
		return true;
	else
		return false;
}

bool Rectangle::operator<(Rectangle operand)
{
	if (this->getArea() < operand.getArea() == true)
		return true;
	else
		return false;
}

bool Rectangle::operator<=(Rectangle operand)
{
	if (this->getArea() <= operand.getArea() == true)
		return true;
	else
		return false;
}

bool Rectangle::operator==(Rectangle operand)
{
	if (this->getArea() == operand.getArea() == true)
		return true;
	else
		return false;
}

void Rectangle::operator=(Rectangle operand)
{
	this->height = operand.height;
	this->width = operand.width;
}

int Rectangle::getArea() const
{
	return height * width;
}


Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
	
}

ostream & operator<<(ostream & out, Rectangle operand)
{
	cout << operand.getArea();
	return out;
}
