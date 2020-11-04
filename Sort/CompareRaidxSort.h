#pragma once
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
class CompareRaidxSort
{
	unsigned int *arr;
	int capacity;
	ofstream radixlog;
public:
	void radixSortHexadecimal(); // radixSort ( HexaDecimal)
	void exeRadixSortHexaBitwise(); // RadixSort( HexaDecimal, Bitwise)
	void RadixSortHexaBitwise(int shift); // "
	void exeRadixSortDecimal(); // RadixSort (Decimal)
	void radixSortDecimal(int maxRadix, int currentRadix); // "
	void resize(int capacity);
	void print();
	void setRand();
	void mergeSort_NonRecursive(); // 비교정렬 중 비교대상
	CompareRaidxSort(int capacity);
	~CompareRaidxSort();
};

