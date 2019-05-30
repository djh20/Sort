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
	radixlog << "������ ������ : radixSort(Decimal)" << endl;
	radixlog << "�ڷ��� : int" << endl;
	radixlog << "�迭�� ������ : " << capacity << endl;
	cout << "������ ������ : radixSort(Decimal)" << endl;
	cout << "�ڷ��� : int" << endl;
	cout << "�迭�� ������ : " << capacity << endl;
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
	radixlog << "����ð� : " << end - begin << "clock" << endl;
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
	const int number_digit = 16;	// LSB�� ����� ���� ����

	radixlog << "=============================================" << endl;
	radixlog << "������ ������ : radixSort(Hexadecimal)" << endl;
	radixlog << "�ڷ��� : int" << endl;
	radixlog << "�迭�� ������ : " << capacity << endl;
	cout << "������ ������ : radixSort(Hexadecimal)" << endl;
	cout << "�ڷ��� : int" << endl;
	cout << "�迭�� ������ : " << capacity << endl;
	clock_t begin, end;
	begin = clock();

	std::queue<int> radix[number_digit]; // �ڸ����� ���� ť �迭

	unsigned int max = arr[0];
	int d = 1; // �ִ��ڸ���

	// �ִ� �ڸ����� ���ϱ� ���ؼ� �ִ��� ã�Ƴ���.
	for (int i = 1; i < capacity; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	// �ִ� �ڸ����� ���س���.
	while (max / number_digit) {
		d *= number_digit;
		max /= number_digit;
	}

	unsigned long long mod = number_digit;
	unsigned long long dMin = 1;

	while (dMin <= d) {
		// �ڸ����� ���� ť�� ����ִ´�.
		for (int i = 0; i < capacity; i++) {
			radix[(arr[i] % mod) / dMin].push(arr[i]);
		}

		// ť�� �� ������ �ڸ��� ũ�� ������ �ٽ� �迭�� ����ִ´�.
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
	radixlog << "����ð� : " << end - begin << "clock" << endl;
	radixlog << "=============================================" << endl;
	
}
