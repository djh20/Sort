/*
made by: djh20@naver.com
last modified : 19/5/17
*/

#include "Fraction.h"
#include "menu.h"
using namespace std;

int main()
{
	cout << "�޴��� �Է��ϼ���" << endl;
	cout << "1. �м��� ��Ģ����" << endl;
	cout << "2. ���Ҽ��� ��Ģ����" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1: fraction(); break;
	case 2: complex(); break;
	}
}

