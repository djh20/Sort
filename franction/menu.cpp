#include "menu.h"
#include "Complex.h"
void fraction()
{
	Fraction f1, f2;
	readFraction(f1);
	readFraction(f2);
	cout << "입력된 값은" << f1 << "과" << f2 << endl << endl;
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
	int numer; // 분자 
	int demon; // 분모

	do {
		cout << "분모가 0이 아닌 분수를 입력하세요" << endl;
		getline(cin, numerString, '/');
		getline(cin, demonString);
		numer = atoi(numerString.c_str());
		demon = atoi(demonString.c_str());
	} while (demon == 0);
	cout << "입력되었습니다." << endl;
	if (demon < 0) // 분모가 음수일 경우 분모를 양수로 만들고 분자를 음수로 만들어줌
	{
		demon *= -1;
		numer *= -1;
	}
	f1.setFraction(numer, demon);
}


void complex()
{
	Complex c1, c2;

	do { cout << "첫번째 복소수의 실수와 허수를 순서대로 입력하세요 : "; cin >> c1; }
	while (c1.validation() == false); // 실수와 허수가 모두 0인지 확인
	
	do { cout << "두번째 복소수의 실수와 허수를 순서대로입력하세요 : "; cin >> c2; }
	while (c2.validation() == false);
	cout << c1 << "+" << c2 << " = " << c1 + c2 << endl;
	cout << c1 << "-" << c2 << " = " << c1 - c2 << endl;
	cout << c1 << "*" << c2 << " = " << c1 * c2 << endl << endl;
}