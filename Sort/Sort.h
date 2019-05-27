#ifndef SORT_H
#define SORT_H
 #include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;
#define INT_RANDMAX_COEFF 65000 // rand�� �ִ������ 32767�� ���� ������ �������� int �ִ� ������ �����Ҽ� �ְ� ������ִ� ���
#define DOUBLE_DIVISOR 77777777 // ������ ������ ����, ���� ������
template <class T>
class Sort
{
	T* arr;
	int capacity;
public:
	void setInc();
	void setRandom();
	void insertionSort();
	void print();
	Sort();
	Sort(int capacity);
	~Sort();
};

template<class T>
inline void Sort<T>::insertionSort()
{

	int i, j;
	T key;
	// ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
	for (i = 1; i < capacity; i++) {
		key = arr[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

		// ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
		// j ���� ������ �ƴϾ�� �ǰ�
		// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j]; // ���ڵ��� ���������� �̵�
		}
		arr[j + 1] = key;
	}

}

template<class T>
inline void Sort<T>::print()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << arr[i] << endl;
	}
}

template<class T>
inline Sort<T>::Sort()
{
}

template<class T>
inline Sort<T>::Sort(int capacity)
{
	arr = new string[capacity];
}

template<>
void Sort<string>::setRandom() // ����6
{
	srand((unsigned int)time(NULL)); 
	this->capacity = capacity;
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = rand()%25 + 97;
		arr[i] += rand() % 25 + 97;
		arr[i] += rand() % 25 + 97;
		arr[i] += rand() % 25 + 97;
		arr[i] += rand() % 25 + 97;
		arr[i] += rand() % 25 + 97;
	}
}

template<>
void Sort<int>::setInc()
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = i;
	}
}

template<>
void Sort<string>::setInc()
{
	setRandom();
	insertionSort();
}

template<>
void Sort<Rectangle>::setRandom()
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i].setHeight(rand());
		arr[i].setWidth(rand());
	}
}

template<>
void Sort<int>::setRandom()
{
	srand((unsigned int)time(NULL));
	this->capacity = capacity;
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = rand() * INT_RANDMAX_COEFF;
	}
}

template<>
void Sort<double>::setRandom()
{
	srand((unsigned int)time(NULL));
	this->capacity = capacity;
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = double(rand()) / DOUBLE_DIVISOR;
	}
}

template<class T>
inline Sort<T>::~Sort()
{
	delete[] arr;
}
#endif