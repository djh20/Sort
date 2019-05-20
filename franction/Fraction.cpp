#include "Fraction.h"
Fraction* Fraction::reduction(Fraction * fraction) // 약분
{
	for (int i = fraction->denom; i >= 2; i--)
	{
		if (fraction->denom%i == 0 && fraction->numer%i == 0)
		{
			fraction->denom /= i;
			fraction->numer /= i;
		}
	}
	return fraction;
}

Fraction::Fraction()
{
}


Fraction::~Fraction()
{
}

Fraction Fraction::operator+(const Fraction & operand)
{
	Fraction result;
	result.denom = denom * operand.denom;
	result.numer = numer * operand.denom + operand.numer * denom;
	reduction(&result);
	return result;
}

Fraction Fraction::operator-(const Fraction & operand)
{
	Fraction *result = new Fraction;
	result->denom = denom * operand.denom;
	result->numer = numer * operand.denom - operand.numer * denom;
	reduction(result);
	return *result;
}

Fraction Fraction::operator/(const Fraction & operand)
{
	Fraction *result = new Fraction;
	result->denom = denom * operand.numer;
	result->numer = numer * operand.denom;
	reduction(result);
	return *result;
}

Fraction Fraction::operator*(const Fraction & operand)
{
	Fraction *result = new Fraction;
	result->denom = denom * operand.denom;
	result->numer = numer * operand.numer;
	reduction(result);
	return *result;
}

ostream & operator<<(ostream & outputStream, Fraction fraction)
{
	if (fraction.denom == 1)
		cout << fraction.numer;
	else if (fraction.denom - fraction.numer == 0 || fraction.denom + fraction.numer == 0) // 분자 분모가 같은경우
		cout << fraction.numer / fraction.denom;
	else if (fraction.numer == 0)
		cout << "0";
	else
		cout << fraction.numer << "/" << fraction.denom;
	return outputStream;
}

