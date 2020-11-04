#pragma once
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> // std:: sort
#include "Rectangle.h"
#include <functional>
#include "Stack.h"
#include <list>
using namespace std;
#define INT_RANDMAX_COEFF 6000 // rand�� �ִ������ 32767�� ���� ������ �������� int �ִ� ������ �����Ҽ� �ְ� ������ִ� ���
#define DOUBLE_DIVISOR 77777777 // ������ ������ ����, ���� ������
#define NUM_OF_FUNC 13 // ���� �Լ��� �� ����
#define STRING "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >" // string�� Ÿ��id ����
#define ASC_FIRST 33 // �ƽ�Ű�ڵ� Ư������ ó�� : '!' 
#define ASC_LAST 126 // �ƽ�Ű�ڵ� Ư������ ������ : '~' 
#define CANT_MEASURE 50000// insertion, seletion, bubble�� �����Ұ�(�ð��� �ʹ� �����ɸ�)
template <class T>
class Sort
{
	T* arr;
	int capacity;
	void(Sort::*sort_Func[NUM_OF_FUNC])();
	ofstream log;
	struct Node {
		T data;
		struct Node *next;
	};
public:
	void resize(int capacity);
	void setInc();
	void setRandom();
	void incVal_sort(); 
	void randVal_sort();
	void decVal_sort();
	void setDec();
	void print();
	void insertionSort(); // Insertion Sort
	void insertionList(); // Insertion Sort (linkedList)
	void exeShellSort(); // ShellSort
	void shellSort(int first, int last, int gap); // 
	void exeQuickSort_Reculsive_Median(); // QuickSort(recursive Median)
	void exeQuickSort_Reculsive_NonMedian(); // QuickSort(recursive First Pivot)
	void quickSort_Reculsive(int start, int end, bool isMedian = false); // "
	void quickSort_NonReculsive(); // QuickSort(nonRecursive)
	void quickSort_NonReculsive_Insertion(T a[], int n); // "
	void exeMergeSort(); // Merge(recursive)
	void merge(int l,int m, int r);// "
	void mergeSort(int l, int r);// "
	void exeNaturalMergeSort(); // Merge(Natural)
	void naturalMergeSort(int capacity); // "
	void naturalMerge(T workArray[], int begin1, int end1, int begin2, int end2);//"
	void copyArray_Nmerge(int iBegin, int iEnd, T workArray[]);// "
	void mergeSort_NonRecursive(); // Merge(nonRecursive)
	void stdSort(); // std::Sort
	void selectionSort(); // SelectionSort
	void heapSort(); // heapSort
	void heapify(int n, int i); // "
	void bubbleSort(); // BubbleSort
	Sort();
	Sort(int capacity);
	~Sort();
};




template<class T>
void Sort<T>::print()
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
		if (sort_Func[i] == nullptr)
			break;
		cout << "�۾��� ���� �迭�� ������������ �ʱ�ȭ�մϴ�..." << endl;
		setInc();
		cout << "�ʱ�ȭ�� �Ϸ��߽��ϴ�. ������ �����մϴ�..." << endl;
		(this->*sort_Func[i])();
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
		if (sort_Func[i] == nullptr)
			break;
		cout << "�۾��� ���� �迭�� �������� �ʱ�ȭ�մϴ�..." << endl;
		setRandom();
		cout << "�ʱ�ȭ�� �Ϸ��߽��ϴ�. ������ �����մϴ�..." << endl;
		(this->*sort_Func[i])();
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
		if (sort_Func[i] == nullptr)
			break;
		cout << "�۾��� ���� �迭�� ������������ �ʱ�ȭ�մϴ�..." << endl;
		setDec();
		cout << "�ʱ�ȭ�� �Ϸ��߽��ϴ�. ������ �����մϴ�..." << endl;
		(this->*sort_Func[i])();
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
		sort_Func[i] = nullptr;
	}
	sort_Func[0] = &Sort<T>::insertionSort;
	sort_Func[1] = &Sort<T>::exeQuickSort_Reculsive_Median;
	sort_Func[2] = &Sort<T>::exeQuickSort_Reculsive_NonMedian;
	sort_Func[3] = &Sort<T>::quickSort_NonReculsive;
	sort_Func[4] = &Sort<T>::exeNaturalMergeSort;
	sort_Func[5] = &Sort<T>::exeMergeSort;
	sort_Func[6] = &Sort<T>::mergeSort_NonRecursive;
	sort_Func[7] = &Sort<T>::stdSort;
	sort_Func[8] = &Sort<T>::selectionSort;
	sort_Func[9] = &Sort<T>::heapSort;
	sort_Func[10] = &Sort<T>::exeShellSort;
	sort_Func[11] = &Sort<T>::bubbleSort;
	sort_Func[12] = &Sort<T>::insertionList;

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

template<class T>
inline Sort<T>::~Sort()
{
	delete[] arr;
}


template<>
void Sort<string>::setRandom() // ����6
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = 34 + rand() % 94;
		arr[i] += 34 + rand() % 94;
		arr[i] += 34 + rand() % 94;
		arr[i] += 34 + rand() % 94;
		arr[i] += 34 + rand() % 94;
		arr[i] += 34 + rand() % 94;
	}
}

template<class T>
void Sort<T>::resize(int capacity)
{
	delete[] arr;
	this->capacity = capacity;
	arr = new T[capacity];
}

template<>
void Sort<int>::setInc() // ������ ���� ����
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = i;
	}
}

template<>
void Sort<string>::setInc() // ������ ���� ����
{
	arr[0] = ASC_FIRST;
	for (int i = 1; i < capacity; i++)
	{
		string tmpS = arr[i - 1];
		if (tmpS.back() < ASC_LAST)
		{
			char tmpC;
			tmpC = tmpS.back();
			tmpS.pop_back();
			tmpS.push_back(tmpC + 1);
			arr[i] = tmpS;
		}
		else
		{
			arr[i] = tmpS + char(ASC_FIRST);
		}
	}
}

template<>
void Sort<double>::setInc() // ������ ���� ����
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = (double)i / DOUBLE_DIVISOR;
	}
}

template<>
void Sort<Rectangle>::setInc() // ������ ���� ����
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i].setHeight(i + 1);
		arr[i].setWidth(i + 1);
	}
}

template<>
void Sort<int>::setDec()
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = capacity - i;
	}
}

template<>
void Sort<double>::setDec()
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = double((capacity - i)) / DOUBLE_DIVISOR;
	}
}

template<>
void Sort<Rectangle>::setDec()
{
	for (int i = 0; i < capacity; i++)
	{
		for (int i = 0; i < capacity; i++)
		{
			arr[i].setHeight(capacity - i);
			arr[i].setWidth(capacity - i);
		}
	}
}

template<>
void Sort<string>::setDec()
{
	arr[capacity - 1] = ASC_FIRST;
	for (int i = capacity - 2; i >= 0; i--)
	{
		string tmpS = arr[i + 1];
		if (tmpS.back() < ASC_LAST)
		{
			char tmpC;
			tmpC = tmpS.back();
			tmpS.pop_back();
			tmpS.push_back(tmpC + 1);
			arr[i] = tmpS;
		}
		else
		{
			arr[i] = tmpS + char(ASC_FIRST);
		}
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

//////////////////////////////////////////////////////����////////////////////////////////////////////////////////


template<class T>
void Sort<T>::insertionSort()
{

	log << "=============================================" << endl;
	cout << "������ ������ : Insertion Sort" << endl;
	log << "������ ������ : Insertion Sort" << endl;
	if (capacity >= CANT_MEASURE)
	{
		cout << "�����Ұ�" << endl;
		log << "�����Ұ�" << endl;
		log << "=============================================" << endl;
		return;
	}
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
void Sort<T>::insertionList()
{
	log << "������ ������ : Insertion Linked List" << endl;
	cout << "������ ������ : Insertion Linked List" << endl;
	clock_t begin, end;
	begin = clock();
	list<T> list;
	for (int i = 0; i < capacity; i++) {
		list.push_front(arr[i]);
	}
	list.sort();
	for (int i = 0; i < capacity; i++) {
		arr[i] = list.front();
		list.pop_front();
	}
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}


template<class T>
void Sort<T>::exeShellSort()
{
	log << "=============================================" << endl;
	log << "������ ������ : ShellSort" << endl;
	cout << "������ ������ : ShellSort" << endl;
	clock_t begin, end;
	begin = clock();
	int i, gap;
	for (gap = capacity / 2; gap > 0; gap = gap / 2) { // ���� shell ũ�� : capacity/2
		if ((gap % 2) == 0)
			gap++; // gap�� Ȧ���� �����.

		// �κ� ����Ʈ�� ������ gap�� ����.
		for (i = 0; i < gap; i++) {
			// �κ� ����Ʈ�� ���� ���� ���� ����
			shellSort(i, capacity - 1, gap);
		}
	}
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}


template<class T>
void Sort<T>::shellSort(int first, int last, int gap) {
	// gap��ŭ ������ ��ҵ��� ���� ����
	// ������ ������ first���� last����
	int i, j;
	T key;

	for (i = first + gap; i <= last; i = i + gap) {
		key = arr[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

		// ���� ���ĵ� �迭�� i-gap�����̹Ƿ� i-gap��°���� �������� �����Ѵ�.
		// j ���� first �̻��̾�� �ϰ�
		// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+gap��°�� �̵�
		for (j = i - gap; j >= first && arr[j] > key; j = j - gap) {
			arr[j + gap] = arr[j]; // ���ڵ带 gap��ŭ ���������� �̵�
		}

		arr[j + gap] = key;
	}
}


template<class T>
void Sort<T>::exeQuickSort_Reculsive_Median()
{
	log << "=============================================" << endl;
	log << "������ ������ : QuickSort_Reculsive(Median of Three)" << endl;
	cout << "������ ������ : QuickSort_Reculsive(Median of Three)" << endl;
	clock_t begin, end;
	begin = clock();
	quickSort_Reculsive(0, capacity - 1, true);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::exeQuickSort_Reculsive_NonMedian()
{
	log << "=============================================" << endl;
	log << "������ ������ : QuickSort_Reculsive(first pivot)" << endl;
	cout << "������ ������ : QuickSort_Reculsive(first pivot)" << endl;
	clock_t begin, end;
	begin = clock();
	quickSort_Reculsive(0, capacity - 1, false);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::quickSort_Reculsive(int start, int end, bool isMedian)
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
	//Median-Of-Three
	if (isMedian == true)
	{
		if (arr[start] > arr[mid]) swap(arr[start], arr[end]);
		if (arr[mid] > arr[end]) swap(arr[mid], arr[end]);
		if (arr[start] > arr[mid]) swap(arr[start], arr[end]);
	}

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
	if (isMedian == true)
	{
		quickSort_Reculsive(start, j - 1, true);
		quickSort_Reculsive(j + 1, end, true);
	}
	else
	{
		quickSort_Reculsive(start, j - 1);
		quickSort_Reculsive(j + 1, end);
	}

}


template<class T>
void Sort<T>::quickSort_NonReculsive()
{
	log << "������ ������ : quickSort_NonReculsive(median of three)" << endl;
	cout << "������ ������ : quickSort_NonReculsive(median of three)" << endl;
	Stack stack(capacity);
	clock_t begin, end;
	begin = clock();
	T p;
	T T_t;
	int int_t;
	int i, j;
	int l, r;
	stack.init_stack();
	l = 0;
	r = capacity - 1;
	stack.push(r);
	stack.push(l);
	while (!stack.is_stack_empty()) {
		l = stack.pop();
		r = stack.pop();
		if (r - l + 1 > 200) {
			int_t = (r + 1) >> 1; // ������ 2�� �ǹ�
			if (arr[l] > arr[int_t]) {
				p = arr[l];
				arr[l] = arr[int_t];
				arr[int_t] = p;
			}
			if (arr[l] > arr[r]) {
				p = arr[l];
				arr[l] = arr[r];
				arr[r] = p;
			}
			if (arr[int_t] > arr[r]) {
				p = arr[int_t];
				arr[int_t] = arr[r];
				arr[r] = p;
			}
			p = arr[int_t];
			arr[int_t] = arr[r - 1];
			arr[r - 1] = p;
			i = l - 1;
			j = r;
			while (1) {
				while (arr[++i] < p);
				while (arr[--j] > p);
				if (i >= j)
					break;
				T_t = arr[i];
				arr[i] = arr[j];
				arr[j] = T_t;
			}
			T_t = arr[i];
			arr[i] = arr[r];
			arr[r] = T_t;
			stack.push(r);
			stack.push(i + 1);
			stack.push(i - 1);
			stack.push(l);
		} // if
		else
			quickSort_NonReculsive_Insertion(arr + l, r - l + 1);
	} // while
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::quickSort_NonReculsive_Insertion(T a[], int n)
{
	int i, j;
	T t;
	for (i = 1; i < n; i++) {
		t = a[i];
		j = i;
		while (j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
	return;
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
void Sort<T>::merge(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	T *L = new T[n1];
	T *R = new T[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;

}

template<class T>
void Sort<T>::mergeSort(int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(l, m);
		mergeSort(m + 1, r);

		merge(l, m, r);
	}
}


template<class T>
void Sort<T>::exeNaturalMergeSort()
{

	log << "=============================================" << endl;
	log << "������ ������ : naturalMergeSort(Reculsive)" << endl;
	cout << "������ ������ : naturalMergeSort(Reculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	naturalMergeSort(capacity);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::naturalMergeSort(int capacity)
{
	if (capacity < 2)
		return;

	T *workArray = new T[capacity];
	int isSortedFlag = 0;
	while (isSortedFlag == 0) {
		int begin1 = 0,
			end1 = 0,
			begin2 = 0,
			end2 = 0;
		while (end1 < (capacity - 1)) {
			if (arr[end1] <= arr[end1 + 1]) {
				end1++;
			}
			else {
				for (begin2 = end2 = (end1 + 1); end2 < (capacity - 1); end2++) {
					if (arr[end2] <= arr[end2 + 1]) {
						continue;
					}
					else {
						break;
					}
				}
				naturalMerge(workArray, begin1, end1, begin2, end2);
				copyArray_Nmerge(begin1, end2, workArray);
				begin1 = end1 = (end2 + 1);
			}

		}
		if ((begin2 == 0) && (end2 == 0)) {
			isSortedFlag = 1;
		}
	}
}


template<class T>
void Sort<T>::naturalMerge(T workArray[], int begin1, int end1, int begin2, int end2)
{
	int counter1 = begin1, counter2 = begin2;
	for (int counter3 = begin1; counter3 <= end2; counter3++) {
		if ((counter1 <= end1) && ((counter2 > end2) || arr[counter1] <= arr[counter2])) {
			workArray[counter3] = arr[counter1];
			counter1++;
		}
		else {
			workArray[counter3] = arr[counter2];
			counter2++;
		}
	}


}


template<class T>
void Sort<T>::copyArray_Nmerge(int iBegin, int iEnd, T workArray[])
{
	for (int counter = iBegin; counter <= iEnd; counter++) {
		arr[counter] = workArray[counter];
	}
}

template<class T>
void Sort<T>::mergeSort_NonRecursive()
{
	log << "=============================================" << endl;
	log << "������ ������ : MergeSort(NonReculsive)" << endl;
	cout << "������ ������ : MergeSort(NonReculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	T *temp = new T[capacity];
	int i, j, k, size, l1, h1, l2, h2; // l1, l2�� ���� ������ ó��,�� h1,h2�� ��ü���������� ù, �� index

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
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}


template<class T>
void Sort<T>::stdSort()
{
	log << "=============================================" << endl;
	log << "������ ������ : std::sort" << endl;
	cout << "������ ������ : std::sort" << endl;
	clock_t begin, end;
	begin = clock();
	sort(arr, arr + capacity);
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::selectionSort()
{
	log << "=============================================" << endl;
	log << "������ ������ : selectionSort" << endl;
	cout << "������ ������ : selectionSort" << endl;
	if (capacity >= CANT_MEASURE)
	{
		cout << "�����Ұ�" << endl;
		log << "�����Ұ�" << endl;
		log << "=============================================" << endl;
		return;
	}
	clock_t begin, end;
	begin = clock();

	int i, j, least;

	// ������ ���ڴ� �ڵ����� ���ĵǱ� ������ (���� ����-1) ��ŭ �ݺ��Ѵ�.
	for (i = 0; i < capacity - 1; i++) {
		least = i;

		// �ּڰ��� Ž���Ѵ�.
		for (j = i + 1; j < capacity; j++) {
			if (arr[j] < arr[least])
				least = j;
		}

		// �ּڰ��� �ڱ� �ڽ��̸� �ڷ� �̵��� ���� �ʴ´�.
		if (i != least) {
			T temp = arr[i];
			arr[i] = arr[least];
			arr[least] = temp;
		}
	}

	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}







template<class T>
void Sort<T>::heapSort()
{
	clock_t begin, end;
	log << "������ ������ : Heap Sort" << endl;
	cout << "������ ������ : Heap Sort" << endl;
	begin = clock();
	for (int i = capacity / 2 - 1; i >= 0; i--) {
		heapify(capacity, i);
	}
	for (int i = capacity - 1; i > 0; i--) {
		T temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(i, 0);
	}
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::heapify(int n, int i)
{
	int p = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if (l < n && arr[p] < arr[l]) {
		p = l;
	}
	if (r < n && arr[p] < arr[r]) {
		p = r;
	}
	if (i != p) {
		T temp = arr[p];
		arr[p] = arr[i];
		arr[i] = temp;
		heapify(n, p);
	}
}

template<class T>
void Sort<T>::bubbleSort()
{
	log << "������ ������ : Bubble Sort" << endl;
	cout << "������ ������ : Bubble Sort" << endl;
	if (capacity >= CANT_MEASURE)
	{
		cout << "�����Ұ�" << endl;
		log << "�����Ұ�" << endl;
		log << "=============================================" << endl;
		return;
	}
	clock_t begin, end;
	begin = clock();
	int i, j;
	T temp;

	for (i = capacity - 1; i > 0; i--) {
		// 0 ~ (i-1)���� �ݺ�
		for (j = 0; j < i; j++) {
			// j��°�� j+1��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	end = clock();
	log << "����ð� : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}