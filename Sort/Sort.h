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
	void naturalMergeSort(int l, int r);
	void merge(int l,int m, int r);
	void mergeSort(int l, int r);
	void exeMergeSort();
	void exeNaturalMergeSort();
	void naturalMerge(int l, int r, int divide);
		
	
	Sort();
	Sort(int capacity);
	~Sort();
};

template<class T>
inline void Sort<T>::insertionSort()
{
	log << "=============================================" << endl;
	cout << "정렬의 종류는 : Insertion Sort" << endl;
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
	log << "***********************************************************************" << endl;
	log << endl;
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
	log << "***********************************************************************" << endl;
	log << endl;
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
	log << "***********************************************************************" << endl;
	log << endl;
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
	int mid = (end - start) / 2;
	T temp;
	if (arr[start] > arr[mid]) swap(arr[start], arr[end]);
	if (arr[mid] > arr[end]) swap(arr[mid], arr[end]);
	if (arr[start] > arr[mid]) swap(arr[start], arr[end]);

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
}

template<class T>
void Sort<T>::exeQuickSort_Reculsive()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : QuickSort_Reculsive" << endl;
	cout << "정렬의 종류는 : QuickSort_Reculsive" << endl;
	clock_t begin, end;
	begin = clock();
	quickSort_Reculsive(0, capacity-1);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::naturalMergeSort(int l, int r)
{
	int check_Cnt = 0;		// 2개 일때 합병
	int first_Merge_start = 1;
	int check_Point;
	int sw = 0;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			check_Cnt++;
			sw = 1;
			if (check_Cnt == 1)
				check_Point = i - 1;
		}
		if (check_Cnt == 2)
		{
			naturalMerge(first_Merge_start, i - 1, check_Point);
			check_Cnt = 0;
			first_Merge_start = i;
		}
		if (i == r && check_Cnt == 1)
			naturalMerge(first_Merge_start, i, check_Point);
	}
	if (sw == 1)
		naturalMergeSort(1, capacity-1);
}

template<class T>
void Sort<T>::merge(int l, int m, int r)
{
	//합병할 결과를 원래 배열로 옮기기 전에 사용할 임시 배열. 크기는 합병할 두 배열 만큼의 크기

	int i = l;
	int j = m + 1;
	int k = l;
	T *tempArray = new T[capacity];
	//l -> m, m+1 -> r까지의 분리된 두 배열의 원소를 앞에서 하나씩 꺼내 비교하고 큰 값을 집어 넣는다
	while (i <= m && j <= r) {
		if (arr[i] < arr[j]) {
			tempArray[k] = arr[i];
			i++;
			k++;
		}
		else {
			tempArray[k] = arr[j];
			j++;
			k++;
		}
	}
	// 만약에, 합병 할 두 배열 중 하나가 다 쓰이지 못했다면 그를 정리해 준다.
	if (i > m) {
		for (int p = j; p <= r; p++) {
			tempArray[k] = arr[p];
			k++;
		}
	}
	else {
		for (int p = i; p <= m; p++) {
			tempArray[k] = arr[p];
			k++;
		}
	}
	//임시 배열에서 원래 배열의 자리로 복사한다.
	for (int i = l; i <= r; i++) {
		arr[i] = tempArray[i];
	}

	delete[] tempArray;
}

template<class T>
void Sort<T>::mergeSort(int l, int r)
{
	if (r > l) {
		int m = (r + l) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

template<class T>
void Sort<T>::exeMergeSort()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : MergeSort(Reculsive)" << endl;
	cout << "정렬의 종류는 : MergeSort(Reculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	mergeSort(0, capacity - 1);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;

}

template<class T>
void Sort<T>::exeNaturalMergeSort()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : naturalMergeSort(Reculsive)" << endl;
	cout << "정렬의 종류는 : naturalMergeSort(Reculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	naturalMergeSort(0, capacity - 1);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::naturalMerge(int l, int r, int divide)
{
	T *first_Arr = new T[capacity];
	//int first_Arr[N + 1];
	int first_Cnt = 0;
	T *second_Arr = new T[capacity];
	//int second_Arr[N + 1];
	int second_Cnt = 0;
	for (int i = l; i <= divide; i++)
		first_Arr[++first_Cnt] = arr[i];
	for (int i = divide + 1; i <= r; i++)
		second_Arr[++second_Cnt] = arr[i];
	int first_index = 1;
	int second_index = 1;
	int present_Position = 0;
	for (int i = l; i < l + (first_Cnt + second_Cnt); i++)
	{
		arr[i] = first_Arr[first_index] > second_Arr[second_index] ? second_Arr[second_index++] : first_Arr[first_index++];
		if (first_index == first_Cnt + 1)		// 첫번째 배열이 다 들어가서 두번째 배열만 넣어주면 되는 경우
		{
			for (int j = i + 1; j < l + (first_Cnt + second_Cnt); j++)
				arr[j] = second_Arr[second_index++];
			break;
		}
		else if (second_index == second_Cnt + 1)		// 두번째 배열이 다 들어가서 첫번째 배열만 넣어주면 되는 경우
		{
			for (int j = i + 1; j < l + (first_Cnt + second_Cnt); j++)
				arr[j] = first_Arr[first_index++];
			break;
		}
	}
	delete[] first_Arr;
	delete[] second_Arr;
	first_Arr = NULL;
	second_Arr = NULL;
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
	m_pFunc[2] = &Sort<T>::exeNaturalMergeSort;
	m_pFunc[3] = &Sort<T>::exeMergeSort;
	

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