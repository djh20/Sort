#pragma once
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Rectangle.h"
using namespace std;
#define INT_RANDMAX_COEFF 65000 // rand�� �ִ������ 32767�� ���� ������ �������� int �ִ� ������ �����Ҽ� �ְ� ������ִ� ���
#define DOUBLE_DIVISOR 77777777 // ������ ������ ����, ���� ������
#define NUM_OF_FUNC 20 // ���� �Լ��� �� ����
#define STRING "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >" // string�� Ÿ��id ����
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
	cout << "������ ������ : Insertion Sort" << endl;
	log << "������ ������ : Insertion Sort" << endl;
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
	log << "����ð� : " << end - begin << "clock" << endl;
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
	log << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		log << "string" << endl;
	else
		log << typeid(T).name() << endl;
	log << "�迭���� : ��������" << endl;
	log << "�׽�Ʈ ���� : " << capacity << endl;
	// ���Ͽ� ����
	cout << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "�׽�Ʈ �� ���� " << capacity << "���� �������� �迭������ �����׽�Ʈ�� �����մϴ�." << endl;
	//���� ���
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		if (m_pFunc[i] == nullptr)
			break;
		cout << "�۾��� ���� �迭�� ������������ �ʱ�ȭ�մϴ�..." << endl;
		setInc();
		cout << "�ʱ�ȭ�� �Ϸ��߽��ϴ�. ������ �����մϴ�..." << endl;
		(this->*m_pFunc[i])();
		cout << "���ĿϷ�, �� " << NUM_OF_FUNC << " �� " << i + 1 << "��° ���� �Ϸ�" << endl;
	}
	// ����
	cout << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "�׽�Ʈ �� ���� " << capacity << "���� �������� �迭������ �����׽�Ʈ�� ��Ĩ�ϴ�." << endl;
	log << "***********************************************************************" << endl;
	log << endl;
	// �Ϸ� ���
}

template<class T>
void Sort<T>::randVal_sort()
{
	log << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		log << "string" << endl;
	else
		log << typeid(T).name() << endl;
	log << "�迭���� : ����" << endl;
	log << "�׽�Ʈ ���� : " << capacity << endl;
	// ���Ͽ� ����
	cout << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "�׽�Ʈ �� ���� " << capacity << "���� �����迭������ �����׽�Ʈ�� �����մϴ�." << endl;
	//���� ���
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		if (m_pFunc[i] == nullptr)
			break;
		cout << "�۾��� ���� �迭�� �������� �ʱ�ȭ�մϴ�..." << endl;
		setRandom();
		cout << "�ʱ�ȭ�� �Ϸ��߽��ϴ�. ������ �����մϴ�..." << endl;
		(this->*m_pFunc[i])();
		cout << "���ĿϷ�, �� " << NUM_OF_FUNC << " �� " << i + 1 << "��° ���� �Ϸ�" << endl;
	}
	// ����
	cout << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "�׽�Ʈ �� ���� " << capacity << "���� �����迭������ �����׽�Ʈ�� ��Ĩ�ϴ�." << endl;
	log << "***********************************************************************" << endl;
	log << endl;
	// �Ϸ� ���
}

template<class T>
void Sort<T>::decVal_sort()
{
	log << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		log << "string" << endl;
	else
		log << typeid(T).name() << endl;
	log << "�迭���� : ��������" << endl;
	log << "�׽�Ʈ ���� : " << capacity << endl;
	// ���Ͽ� ����
	cout << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "�׽�Ʈ �� ���� " << capacity << "���� �������� �迭������ �����׽�Ʈ�� �����մϴ�." << endl;
	//���� ���
	for (int i = 0; i < NUM_OF_FUNC; i++)
	{
		if (m_pFunc[i] == nullptr)
			break;
		cout << "�۾��� ���� �迭�� ������������ �ʱ�ȭ�մϴ�..." << endl;
		setDec();
		cout << "�ʱ�ȭ�� �Ϸ��߽��ϴ�. ������ �����մϴ�..." << endl;
		(this->*m_pFunc[i])();
		cout << "���ĿϷ�, �� " << NUM_OF_FUNC << " �� " << i + 1 << "��° ���� �Ϸ�" << endl;
	}
	// ����
	cout << "�ڷ��� : ";
	if ((string)typeid(T).name() == STRING)
		cout << "string" << endl;
	else
		cout << typeid(T).name() << endl;
	cout << "�׽�Ʈ �� ���� " << capacity << "���� �������� �迭������ �����׽�Ʈ�� ��Ĩ�ϴ�." << endl;
	log << "***********************************************************************" << endl;
	log << endl;
	// �Ϸ� ���
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
		// ���Ұ� 1���� ���
		return;
	}

	int pivot = start;
	int i = pivot + 1; // ���� ��� ���� 
	int j = end; // ������ ��� ����
	int mid = (end - start) / 2;
	T temp;
	if (arr[start] > arr[mid]) swap(arr[start], arr[end]);
	if (arr[mid] > arr[end]) swap(arr[mid], arr[end]);
	if (arr[start] > arr[mid]) swap(arr[start], arr[end]);

	while (i <= j) {
		// �����Ͱ� ������������ �ݺ�
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}

		if (i > j) {
			// ������
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			// i��°�� j��°�� ����
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// ���� ���
	quickSort_Reculsive(start, j - 1);
	quickSort_Reculsive(j + 1, end);
}

template<class T>
void Sort<T>::exeQuickSort_Reculsive()
{
	log << "=============================================" << endl;
	log << "������ ������ : QuickSort_Reculsive" << endl;
	cout << "������ ������ : QuickSort_Reculsive" << endl;
	clock_t begin, end;
	begin = clock();
	quickSort_Reculsive(0, capacity-1);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::naturalMergeSort(int l, int r)
{
	int check_Cnt = 0;		// 2�� �϶� �պ�
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
	//�պ��� ����� ���� �迭�� �ű�� ���� ����� �ӽ� �迭. ũ��� �պ��� �� �迭 ��ŭ�� ũ��

	int i = l;
	int j = m + 1;
	int k = l;
	T *tempArray = new T[capacity];
	//l -> m, m+1 -> r������ �и��� �� �迭�� ���Ҹ� �տ��� �ϳ��� ���� ���ϰ� ū ���� ���� �ִ´�
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
	// ���࿡, �պ� �� �� �迭 �� �ϳ��� �� ������ ���ߴٸ� �׸� ������ �ش�.
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
	//�ӽ� �迭���� ���� �迭�� �ڸ��� �����Ѵ�.
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
	log << "������ ������ : MergeSort(Reculsive)" << endl;
	cout << "������ ������ : MergeSort(Reculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	mergeSort(0, capacity - 1);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;

}

template<class T>
void Sort<T>::exeNaturalMergeSort()
{
	log << "=============================================" << endl;
	log << "������ ������ : naturalMergeSort(Reculsive)" << endl;
	cout << "������ ������ : naturalMergeSort(Reculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	naturalMergeSort(0, capacity - 1);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
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
		if (first_index == first_Cnt + 1)		// ù��° �迭�� �� ���� �ι�° �迭�� �־��ָ� �Ǵ� ���
		{
			for (int j = i + 1; j < l + (first_Cnt + second_Cnt); j++)
				arr[j] = second_Arr[second_index++];
			break;
		}
		else if (second_index == second_Cnt + 1)		// �ι�° �迭�� �� ���� ù��° �迭�� �־��ָ� �Ǵ� ���
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
void Sort<string>::setRandom() // ����6
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
void Sort<T>::setInc() // ������ ���� ����
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