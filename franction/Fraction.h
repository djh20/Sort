#pragma once
#include <iostream>
using namespace std;
class Fraction
{
	int numer; // 분자
	int denom; // 분모
	friend class ofstream;
public:
	Fraction* reduction(Fraction *fraction); //약분
	Fraction();
	~Fraction();
	void setFraction(int numer, int denom) { this->numer = numer; this->denom = denom; };
	friend ostream& operator << (ostream& outputStream, Fraction fraction);
	Fraction operator +(const Fraction& operand);
	Fraction operator -(const Fraction& operand);
	Fraction operator /(const Fraction& operand);
	Fraction operator *(const Fraction& operand);
};

