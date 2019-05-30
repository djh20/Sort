#include "CompareRaidxSort.h"
using namespace std;
#define UNSIGNED_INT_RANDMAX_COEFF 80000

CompareRaidxSort::CompareRaidxSort(int capacity)
{
	arr = new unsigned int[capacity];
	radixlog.open("radix.txt");
	this->capacity = capacity;
}


void CompareRaidxSort::resize(int capacity)
{
	delete[] arr;
	this->capacity = capacity;
	arr = new unsigned int[capacity];
}

void CompareRaidxSort::print()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << arr[i] << " ";
	}
}

void CompareRaidxSort::setRand()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = rand() *  UNSIGNED_INT_RANDMAX_COEFF;
	}
}

CompareRaidxSort::~CompareRaidxSort()
{
}

void CompareRaidxSort::exeRadixSortDecimal()
{
	radixlog << "=============================================" << endl;
	radixlog << "정렬의 종류는 : radixSort(Decimal)" << endl;
	radixlog << "자료형 : int" << endl;
	radixlog << "배열의 사이즈 : " << capacity << endl;
	cout << "정렬의 종류는 : radixSort(Decimal)" << endl;
	cout << "자료형 : int" << endl;
	cout << "배열의 사이즈 : " << capacity << endl;
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

void CompareRaidxSort::radixSortHexadecimal()
{
	const int number_digit = 16;	// LSB로 사용할 진수 정의

	radixlog << "=============================================" << endl;
	radixlog << "정렬의 종류는 : radixSort(Hexadecimal)" << endl;
	radixlog << "자료형 : int" << endl;
	radixlog << "배열의 사이즈 : " << capacity << endl;
	cout << "정렬의 종류는 : radixSort(Hexadecimal)" << endl;
	cout << "자료형 : int" << endl;
	cout << "배열의 사이즈 : " << capacity << endl;
	clock_t begin, end;
	begin = clock();

	std::queue<int> radix[number_digit]; // 자리수에 대한 큐 배열

	unsigned int max = arr[0];
	int d = 1; // 최대자리수

	// 최대 자리수를 구하기 위해서 최댓값을 찾아낸다.
	for (int i = 1; i < capacity; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	// 최대 자리수를 구해낸다.
	while (max / number_digit) {
		d *= number_digit;
		max /= number_digit;
	}

	unsigned long long mod = number_digit;
	unsigned long long dMin = 1;

	while (dMin <= d) {
		// 자리수에 따라 큐에 집어넣는다.
		for (int i = 0; i < capacity; i++) {
			radix[(arr[i] % mod) / dMin].push(arr[i]);
		}

		// 큐에 들어간 값들을 자리수 크기 순으로 다시 배열에 집어넣는다.
		for (int i = 0, j = 0; i < number_digit;) {
			if (radix[i].size()) {
				arr[j++] = radix[i].front();
				radix[i].pop();
			}
			else i++;
		}

		dMin *= number_digit;
		mod *= number_digit;
	}
	end = clock();
	radixlog << "수행시간 : " << end - begin << "clock" << endl;
	radixlog << "=============================================" << endl;
	
}
