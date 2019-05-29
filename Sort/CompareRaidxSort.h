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
	void exeRadixSortDecimal();
	void radixSortDecimal(int maxRadix, int currentRadix);
	CompareRaidxSort(int capacity);
	void resize(int capacity);
	~CompareRaidxSort();
};

