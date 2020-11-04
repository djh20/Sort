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

//////////////////////////////////////////////////////����////////////////////////////////////////////////////////


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


void CompareRaidxSort::exeRadixSortHexaBitwise()
{
	radixlog << "=============================================" << endl;
	radixlog << "������ ������ : radixSort(Hexa BitWise)" << endl;
	radixlog << "�ڷ��� : int" << endl;
	radixlog << "�迭�� ������ : " << capacity << endl;
	cout << "������ ������ : radixSort(Hexa BitWise)" << endl;
	cout << "�ڷ��� : int" << endl;
	cout << "�迭�� ������ : " << capacity << endl;
	clock_t begin, end;
	begin = clock();

	unsigned int max = arr[0]; //

	for (int i = 1; i < capacity; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	for (int shift = 0; (max >> shift) > 0; shift += 4) {
		if ((max >> shift) == max && shift != 0)
			break;
		RadixSortHexaBitwise(shift);
	}

	end = clock();
	radixlog << "����ð� : " << end - begin << "clock" << endl;
	radixlog << "=============================================" << endl;
}

void CompareRaidxSort::RadixSortHexaBitwise(int shift)
{

	int count[16] = { 0 };
	int *output = new int[capacity];
	int i, last;

	queue<int> container[16];
	for (i = 0; i < capacity; i++)
		container[(arr[i] >> shift) & 15].push(arr[i]);


	int idx = 0;
	for (int n = 0; n < 16; n++)
	{
		while (container[n].size() != 0)
		{
			arr[idx++] = container[n].front();
			container[n].pop();
		}
	}

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

void CompareRaidxSort::mergeSort_NonRecursive()
{
	radixlog << "=============================================" << endl;
	radixlog << "������ ������ : MergeSort(NonReculsive)" << endl;
	radixlog << "�ڷ��� : int" << endl;
	radixlog << "�迭�� ������ : " << capacity << endl;
	cout << "������ ������ : MergeSort(NonReculsive)" << endl;
	cout << "�ڷ��� : int" << endl;
	cout << "�迭�� ������ : " << capacity << endl;
	clock_t begin, end;
	begin = clock();
	unsigned int *temp = new unsigned int[capacity];
	int i, j, k, size, l1, h1, l2, h2; // l1, l2�� ���� ������ ó��,�� h1,h2�� ��ü���������� ù, �� index

	/*l1 lower bound of first pair and so on*/
	for (size = 1; size < capacity; size = size * 2)
	{
		l1 = 0;
		k = 0;  /*Index for temp array*/
		while (l1 + size < capacity)
		{
			h1 = l1 + size - 1;
			l2 = h1 + 1;
			h2 = l2 + size - 1;
			/* h2 exceeds the limlt of arr */
			if (h2 >= capacity)
				h2 = capacity - 1;

			/*Merge the two pairs with lower limits l1 and l2*/
			i = l1;
			j = l2;

			while (i <= h1 && j <= h2)
			{
				if (arr[i] <= arr[j])
					temp[k++] = arr[i++];
				else
					temp[k++] = arr[j++];
			}

			while (i <= h1)
				temp[k++] = arr[i++];
			while (j <= h2)
				temp[k++] = arr[j++];
			/**Merging completed**/
			/*Take the next two pairs for merging */
			l1 = h2 + 1;
		}/*End of while*/

		/*any pair left */
		for (i = l1; k < capacity; i++)
			temp[k++] = arr[i];

		for (i = 0; i < capacity; i++)
			arr[i] = temp[i];

	}/*End of for loop */
	delete[] temp;
	end = clock();
	radixlog << "����ð� : " << end - begin << "clock" << endl;
	radixlog << "=============================================" << endl;
}

