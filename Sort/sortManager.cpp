#include "sortManager.h"
#include "Sort.h"
#include "CompareRaidxSort.h"
#define TEST_SIZE 1000
void menu()
{
	int select = 0;

	while (select != -1)
	{
		cout << "----------------------------------------------" << endl;
		cout << "정렬하실 자료형을 선택하세요" << endl;
		cout << "1. int(정수)" << endl;
		cout << "2. double(부동소수)" << endl;
		cout << "3. string(문자열, 6자리)" << endl;
		cout << "4. Rectangle(직사각형, 넓이를 계산해서 정렬)" << endl;
		cout << "5. Radix Sort 시간비교" << endl;
		cout << "-1 : 종료" << endl;
		cout << "----------------------------------------------" << endl;
		cin >> select;
		switch (select)
		{
		case 1: sorts<int>(); break;
		case 2: sorts<double>(); break;
		case 3: sorts<string>(); break;
		case 4: sorts<Rectangle>(); break;
		case 5:  break;
		}
	}
}

template <typename T>
void sorts()
{
	Sort<T> test(TEST_SIZE);
	for (int i = TEST_SIZE; i <= TEST_SIZE*100; i*=10)
	{
		cout << "----------------------------------------------" << endl;
		if (i != TEST_SIZE)
		{
			test.resize(i);
			test.setRandom(); //배열을 랜덤으로 초기화해줌
		}
		test.randVal_sort();
		cout << "----------------------------------------------" << endl;
		test.incVal_sort();
		cout << "----------------------------------------------" << endl;
		test.decVal_sort();
	}
}
void radixSort()
{


}