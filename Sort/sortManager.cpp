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
		cout << "�����Ͻ� �ڷ����� �����ϼ���" << endl;
		cout << "1. int(����)" << endl;
		cout << "2. double(�ε��Ҽ�)" << endl;
		cout << "3. string(���ڿ�, 6�ڸ�)" << endl;
		cout << "4. Rectangle(���簢��, ���̸� ����ؼ� ����)" << endl;
		cout << "5. Radix Sort �ð���" << endl;
		cout << "-1 : ����" << endl;
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
			test.setRandom(); //�迭�� �������� �ʱ�ȭ����
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