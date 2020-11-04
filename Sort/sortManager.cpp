#include "sortManager.h"
#include "Sort.h"
#include "CompareRaidxSort.h"
constexpr int TEST_CASE[5]{500, 1000 ,5000 , 10000, 30000 }; // TestCase
#define RADIX_TESTCASE 100000
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
		case 5: radixSort(); break;
		}
	}
}

template <typename T>
void sorts()
{
	Sort<T> test(TEST_CASE[0]);
	for (int i = 0; i <= 4; i++)
	{
		cout << "----------------------------------------------" << endl;
		if (i != 0)
		{
			test.resize(TEST_CASE[i]);
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
	CompareRaidxSort test(RADIX_TESTCASE);
		cout << "----------------------------------------------" << endl;
		cout << "기수정렬과 mergeSort_NonRecursive의 수행실험을 시작합니다" << endl;
		test.setRand(); 
		test.exeRadixSortDecimal();
		test.setRand(); 
		test.radixSortHexadecimal();
		test.setRand(); 
		test.exeRadixSortHexaBitwise();
		test.setRand();
		test.mergeSort_NonRecursive();
		cout << "----------------------------------------------" << endl;


}