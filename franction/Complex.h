#pragma once
#include <iostream>
using namespace std;
class Complex
{
	double real; //실수
	double imag; //허수
public:
	bool validation();
	friend istream& operator >>(istream& in, Complex &complex);
	friend ostream& operator <<(ostream& out, Complex complex);
	Complex operator+(const Complex &operand);
	Complex operator-(const Complex &operand);
	Complex operator*(const Complex &operand);
	Complex();
	~Complex();
};

