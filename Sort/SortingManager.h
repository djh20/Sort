#ifndef SORTINGMANAGER_H
#define SORTINGMANAGER_H

#include "Sort.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
class SortingManager
{
	ofstream intdata;
	ofstream stringdata;
	ofstream doubledata;
	ofstream rectangledata;
public:
	template<typename T>
	void sortInc(int capacity);
	template<typename T>
	void sortRand(int capacity);
	void measureSort(void(*fptr)(int), int capacity);
	SortingManager();
	~SortingManager();
};

template<typename T>
void SortingManager::sortInc(int capacity)
{

}

template<typename T>
void SortingManager::sortRand(int capacity)
{
	Sort<T> test(capacity);
	test.setRandom();
	measureSort(test.insertionSort(), capacity);
}
#endif