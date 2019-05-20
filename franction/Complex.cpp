#include "Complex.h"



bool Complex::validation() // 둘다 0인지 검사
{
	if (real == 0 && imag == 0)
		return false;
	else
		return true;
}



Complex Complex::operator+(const Complex &operand)
{
	Complex *result = new Complex;
	result->real = real + operand.real;
	result->imag = imag + operand.imag;
	return *result;
}

Complex  Complex::operator-(const Complex &operand)
{
	Complex *result = new Complex;
	result->real = real - operand.real;
	result->imag = imag - operand.imag;
	return *result;
}

Complex  Complex::operator*(const Complex &operand)
{
	Complex *result = new Complex;
	result->real = real * operand.real + (imag * operand.imag)*-1;
	result->imag = imag * operand.real + operand.imag * real;
	return *result;
}

Complex::Complex()
{
}


Complex::~Complex()
{
}

istream& operator>>(istream & in, Complex &complex)
{
	cin >> complex.real;
	cin >> complex.imag;
	return in;
}

ostream & operator<<(ostream & out, Complex complex)
{
	if (complex.real != 0 && complex.imag != 0)
		cout << "(";
	if (complex.real != 0)
		cout << complex.real;

	if (complex.imag != 0)
	{
		if (complex.real != 0 && complex.imag > 0)
			cout << "+";
		cout << complex.imag << "i";
	}
	if (complex.real != 0 && complex.imag != 0)
		cout << ")";
	if (complex.real == 0 && complex.imag == 0)
		cout << "0";
	return out;
}