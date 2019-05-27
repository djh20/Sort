#ifndef SORT_H
#define SORT_H
 #include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;
#define INT_RANDMAX_COEFF 65000 // rand의 최대범위가 32767인 것을 감안해 곱햇을때 int 최대 범위에 근접할수 있게 만들어주는 계수
#define DOUBLE_DIVISOR 77777777 // 난수를 나눠줄 제수, 임의 값임의
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
	// 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
	for (i = 1; i < capacity; i++) {
		key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		// 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
		// j 값은 음수가 아니어야 되고
		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j]; // 레코드의 오른쪽으로 이동
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
void Sort<string>::setRandom() // 길이6
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