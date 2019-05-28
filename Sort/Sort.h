#pragma once
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Rectangle.h"
using namespace std;
#define INT_RANDMAX_COEFF 65000 // rand의 최대범위가 32767인 것을 감안해 곱햇을때 int 최대 범위에 근접할수 있게 만들어주는 계수
#define DOUBLE_DIVISOR 77777777 // 난수를 나눠줄 제수, 임의 값임의
#define NUM_OF_FUNC 20 // 정렬 함수의 총 갯수
#define STRING "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >" // string의 타입id 네임
template <class T>
class Sort
{
	T* arr;
	int capacity;
	void(Sort::*m_pFunc[NUM_OF_FUNC])();
	ofstream log;
public:
	void resize(int capacity);
	void setInc();
	void setRandom();
	void insertionSort();
	void print();
	void incVal_sort();
	void randVal_sort();
	void decVal_sort();
	void setDec();
	void quickSort_Reculsive(int start, int end);
	void exeQuickSort_Reculsive();
	Sort();
	Sort(int capacity);
	~Sort();
};

template<class T>
inline void Sort<T>::insertionSort()
{
	log << "정렬의 종류는 : Insertion Sort" << endl;
	clock_t begin, end;
	begin = clock();
	int i, j;
	T key;
	for (i = 1; i < capacity; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j]; 
		}
		arr[j + 1] = key;
	}
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
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
void Sort<T>::incVal_sort()
{
	log << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		log << "string" << endl;
	else
		log << typeid(T).name() << endl;
	log << "배열형태 : 오름차순" << endl;
	log << "테스트 갯수 : " << capacity << endl;
	// 파일에 저장
	cout << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "테스트 값 개수 " << capacity << "개의 오름차순 배열에대한 정렬테스트를 시작합니다." << endl;
	//시작 출력
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		if (m_pFunc[i] == nullptr)
			break;
		cout << "작업을 위해 배열을 오름차순으로 초기화합니다..." << endl;
		setInc();
		cout << "초기화를 완료했습니다. 정렬을 진행합니다..." << endl;
		(this->*m_pFunc[i])();
		cout << "정렬완료, 총 " << NUM_OF_FUNC << " 중 " << i + 1 << "번째 정렬 완료" << endl;
	}
	// 실행
	cout << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "테스트 값 개수 " << capacity << "개의 오름차순 배열에대한 정렬테스트를 마칩니다." << endl;
	// 완료 출력
}

template<class T>
void Sort<T>::randVal_sort()
{
	log << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		log << "string" << endl;
	else
		log << typeid(T).name() << endl;
	log << "배열형태 : 랜덤" << endl;
	log << "테스트 갯수 : " << capacity << endl;
	// 파일에 저장
	cout << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "테스트 값 개수 " << capacity << "개의 랜덤배열에대한 정렬테스트를 시작합니다." << endl;
	//시작 출력
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		if (m_pFunc[i] == nullptr)
			break;
		cout << "작업을 위해 배열을 랜덤으로 초기화합니다..." << endl;
		setRandom();
		cout << "초기화를 완료했습니다. 정렬을 진행합니다..." << endl;
		(this->*m_pFunc[i])();
		cout << "정렬완료, 총 " << NUM_OF_FUNC << " 중 " << i + 1 << "번째 정렬 완료" << endl;
	}
	// 실행
	cout << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "테스트 값 개수 " << capacity << "개의 랜덤배열에대한 정렬테스트를 마칩니다." << endl;
	// 완료 출력
}

template<class T>
void Sort<T>::decVal_sort()
{
	log << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		log << "string" << endl;
	else
		log << typeid(T).name() << endl;
	log << "배열형태 : 내림차순" << endl;
	log << "테스트 갯수 : " << capacity << endl;
	// 파일에 저장
	cout << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "테스트 값 개수 " << capacity << "개의 내림차순 배열에대한 정렬테스트를 시작합니다." << endl;
	//시작 출력
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		if (m_pFunc[i] == nullptr)
			break;
		cout << "작업을 위해 배열을 내림차순으로 초기화합니다..." << endl;
		setDec();
		cout << "초기화를 완료했습니다. 정렬을 진행합니다..." << endl;
		(this->*m_pFunc[i])();
		cout << "정렬완료, 총 " << NUM_OF_FUNC << " 중 " << i + 1 << "번째 정렬 완료" << endl;
	}
	// 실행
	cout << "자료형 : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "테스트 값 개수 " << capacity << "개의 내림차순 배열에대한 정렬테스트를 마칩니다." << endl;
	// 완료 출력
}

template<class T>
inline void Sort<T>::setDec()
{
	int i, j;
	T key;
	for (i = 1; i < capacity; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] < key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

template<class T>
void Sort<T>::quickSort_Reculsive(int start, int end)
{
	if (start >= end) {
		// 원소가 1개인 경우
		return;
	}
	int pivot = start;
	int i = pivot + 1; // 왼쪽 출발 지점 
	int j = end; // 오른쪽 출발 지점
	T temp;

	while (i <= j) {
		// 포인터가 엇갈릴때까지 반복
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}

		if (i > j) {
			// 엇갈림
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			// i번째와 j번째를 스왑
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	// 분할 계산
	quickSort_Reculsive(start, j - 1);
	quickSort_Reculsive(j + 1, end);
	cout << "실행완료";
}

template<class T>
inline void Sort<T>::exeQuickSort_Reculsive()
{
	quickSort_Reculsive(0, capacity-1);
}

template<class T>
inline Sort<T>::Sort()
{

}

template<class T>
inline Sort<T>::Sort(int capacity)
{
	this->capacity = capacity;
	arr = new T[capacity];
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		m_pFunc[i] = nullptr;
	}
	m_pFunc[0] = &Sort<T>::insertionSort;
	m_pFunc[1] = &Sort<T>::exeQuickSort_Reculsive;
	

	string dataFile;
	if ((string)typeid(T).name() == STRING)
		dataFile = "string.txt";
	else if ((string)typeid(T).name() == "int")
		dataFile = "int.txt";
	else if ((string)typeid(T).name() == "class Rectangle")
		dataFile = "Rectangle.txt";
	else if ((string)typeid(T).name() == "double")
		dataFile = "double.txt";
	else
		dataFile = "error.txt";
	log.open(dataFile);
}

template<>
void Sort<string>::setRandom() // 길이6
{
	srand((unsigned int)time(NULL)); 
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

template<class T>
void Sort<T>::resize(int capacity)
{
	delete[] arr;
	this->capacity = capacity;
	arr = new T[capacity];
}

template<class T>
void Sort<T>::setInc() // 정렬을 통해 구현
{
	int i, j;
	T key;
	for (i = 1; i < capacity; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
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
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = rand() * INT_RANDMAX_COEFF;
	}
}

template<>
void Sort<double>::setRandom()
{
	srand((unsigned int)time(NULL));
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