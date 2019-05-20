/*
made by: djh20@naver.com
last modified : 19/5/17
*/

#include "Fraction.h"
#include "menu.h"
using namespace std;

int main()
{
	cout << "메뉴를 입력하세요" << endl;
	cout << "1. 분수의 사칙연산" << endl;
	cout << "2. 복소수의 사칙연산" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1: fraction(); break;
	case 2: complex(); break;
	}
}

