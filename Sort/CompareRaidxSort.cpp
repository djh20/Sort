#include "CompareRaidxSort.h"
using namespace std;
#define TEST_CASE 10000


CompareRaidxSort::CompareRaidxSort(int capacity)
{
	capacity = TEST_CASE;
	arr = new unsigned int[capacity];
	radixlog.open("radix.txt");
}


void CompareRaidxSort::resize(int capacity)
{
	delete[] arr;
	this->capacity = capacity;
	arr = new unsigned int[capacity];
}

CompareRaidxSort::~CompareRaidxSort()
{
}

void CompareRaidxSort::exeRadixSortDecimal()
{
	radixlog << "=============================================" << endl;
	radixlog << "정렬의 종류는 : radixSort(Decimal)" << endl;
	cout << "정렬의 종류는 : radixSort(Decimal)" << endl;
	clock_t begin, end;
	begin = clock();
	int maxRadix = 0, currentRadix = 0;

	maxRadix = (int)log10(arr[0]) + 1;
	for (int i = 1; i < 5; i++)
	{
		int tempRadix = log10(arr[i]) + 1;
		if (maxRadix < tempRadix)
			maxRadix = tempRadix;
	}


	radixSortDecimal(maxRadix, currentRadix);
	end = clock();
	radixlog << "수행시간 : " << end - begin << "clock" << endl;
	radixlog << "=============================================" << endl;
}


void CompareRaidxSort::radixSortDecimal(int maxRadix, int currentRadix)
{
	int from = 0;
	if (maxRadix < currentRadix) return;
	int R = 1;
	for (int i = 0; i < currentRadix; i++)
		R *= 10;

	queue<int> container[10];
	for (int i = from; i <= capacity; i++)
	{
		container[(arr[i] / R) % 10].push(arr[i]);
	}

	int idx = 0;
	for (int n = 0; n < 10; n++)
	{
		while (container[n].size() != 0)
		{
			arr[from + idx++] = container[n].front();
			container[n].pop();
		}
	}
	radixSortDecimal(maxRadix, currentRadix + 1);
}