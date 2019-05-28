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
	Sort();
	Sort(int capacity);
	~Sort();
};

template<class T>
inline void Sort<T>::insertionSort()
{
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
	T temp;

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
	cout << "����Ϸ�";
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