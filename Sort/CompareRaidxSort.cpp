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

//////////////////////////////////////////////////////정렬////////////////////////////////////////////////////////


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


void CompareRaidxSort::exeRadixSortHexaBitwise()
{
	radixlog << "=============================================" << endl;
	radixlog << "정렬의 종류는 : radixSort(Hexa BitWise)" << endl;
	radixlog << "자료형 : int" << endl;
	radixlog << "배열의 사이즈 : " << capacity << endl;
	cout << "정렬의 종류는 : radixSort(Hexa BitWise)" << endl;
	cout << "자료형 : int" << endl;
	cout << "배열의 사이즈 : " << capacity << endl;
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
	radixlog << "수행시간 : " << end - begin << "clock" << endl;
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

void CompareRaidxSort::mergeSort_NonRecursive()
{
	radixlog << "=============================================" << endl;
	radixlog << "정렬의 종류는 : MergeSort(NonReculsive)" << endl;
	radixlog << "자료형 : int" << endl;
	radixlog << "배열의 사이즈 : " << capacity << endl;
	cout << "정렬의 종류는 : MergeSort(NonReculsive)" << endl;
	cout << "자료형 : int" << endl;
	cout << "배열의 사이즈 : " << capacity << endl;
	clock_t begin, end;
	begin = clock();
	unsigned int *temp = new unsigned int[capacity];
	int i, j, k, size, l1, h1, l2, h2; // l1, l2는 나눈 구간의 처음,끝 h1,h2는 전체구간에서의 첫, 끝 index

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
	radixlog << "수행시간 : " << end - begin << "clock" << endl;
	radixlog << "=============================================" << endl;
}

