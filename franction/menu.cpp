#include "menu.h"
#include "Complex.h"
void fraction()
{
	Fraction f1, f2;
	readFraction(f1);
	readFraction(f2);
	cout << "�Էµ� ����" << f1 << "��" << f2 << endl << endl;
	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
}
void readFraction(Fraction& f1)
{
	string value;
	string numerString;
	string demonString;
	int numer; // ���� 
	int demon; // �и�

	do {
		cout << "�и� 0�� �ƴ� �м��� �Է��ϼ���" << endl;
		getline(cin, numerString, '/');
		getline(cin, demonString);
		numer = atoi(numerString.c_str());
		demon = atoi(demonString.c_str());
	} while (demon == 0);
	cout << "�ԷµǾ����ϴ�." << endl;
	if (demon < 0) // �и� ������ ��� �и� ����� ����� ���ڸ� ������ �������
	{
		demon *= -1;
		numer *= -1;
	}
	f1.setFraction(numer, demon);
}


void complex()
{
	Complex c1, c2;

	do { cout << "ù��° ���Ҽ��� �Ǽ��� ����� ������� �Է��ϼ��� : "; cin >> c1; }
	while (c1.validation() == false); // �Ǽ��� ����� ��� 0���� Ȯ��
	
	do { cout << "�ι�° ���Ҽ��� �Ǽ��� ����� ��������Է��ϼ��� : "; cin >> c2; }
	while (c2.validation() == false);
	cout << c1 << "+" << c2 << " = " << c1 + c2 << endl;
	cout << c1 << "-" << c2 << " = " << c1 - c2 << endl;
	cout << c1 << "*" << c2 << " = " << c1 * c2 << endl << endl;
}