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
#define INT_RANDMAX_COEFF 6000 // rand의 최대범위가 32767인 것을 감안해 곱햇을때 int 최대 범위에 근접할수 있게 만들어주는 계수
#define DOUBLE_DIVISOR 77777777 // 난수를 나눠줄 제수, 임의 값임의
#define NUM_OF_FUNC 13 // 정렬 함수의 총 갯수
#define STRING "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >" // string의 타입id 네임
#define ASC_FIRST 33 // 아스키코드 특수문자 처음 : '!' 
#define ASC_LAST 126 // 아스키코드 특수문자 마지막 : '~' 
#define CANT_MEASURE 50000// insertion, seletion, bubble이 측정불가(시간이 너무 오래걸림)
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
		if (sort_Func[i] == nullptr)
			break;
		cout << "작업을 위해 배열을 오름차순으로 초기화합니다..." << endl;
		setInc();
		cout << "초기화를 완료했습니다. 정렬을 진행합니다..." << endl;
		(this->*sort_Func[i])();
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
		if (sort_Func[i] == nullptr)
			break;
		cout << "작업을 위해 배열을 랜덤으로 초기화합니다..." << endl;
		setRandom();
		cout << "초기화를 완료했습니다. 정렬을 진행합니다..." << endl;
		(this->*sort_Func[i])();
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
		if (sort_Func[i] == nullptr)
			break;
		cout << "작업을 위해 배열을 내림차순으로 초기화합니다..." << endl;
		setDec();
		cout << "초기화를 완료했습니다. 정렬을 진행합니다..." << endl;
		(this->*sort_Func[i])();
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
void Sort<string>::setRandom() // 길이6
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
void Sort<int>::setInc() // 정렬을 통해 구현
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = i;
	}
}

template<>
void Sort<string>::setInc() // 정렬을 통해 구현
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
void Sort<double>::setInc() // 정렬을 통해 구현
{
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = (double)i / DOUBLE_DIVISOR;
	}
}

template<>
void Sort<Rectangle>::setInc() // 정렬을 통해 구현
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

//////////////////////////////////////////////////////정렬////////////////////////////////////////////////////////


template<class T>
void Sort<T>::insertionSort()
{

	log << "=============================================" << endl;
	cout << "정렬의 종류는 : Insertion Sort" << endl;
	log << "정렬의 종류는 : Insertion Sort" << endl;
	if (capacity >= CANT_MEASURE)
	{
		cout << "측정불가" << endl;
		log << "측정불가" << endl;
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
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::insertionList()
{
	log << "정렬의 종류는 : Insertion Linked List" << endl;
	cout << "정렬의 종류는 : Insertion Linked List" << endl;
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
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}


template<class T>
void Sort<T>::exeShellSort()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : ShellSort" << endl;
	cout << "정렬의 종류는 : ShellSort" << endl;
	clock_t begin, end;
	begin = clock();
	int i, gap;
	for (gap = capacity / 2; gap > 0; gap = gap / 2) { // 최초 shell 크기 : capacity/2
		if ((gap % 2) == 0)
			gap++; // gap을 홀수로 만든다.

		// 부분 리스트의 개수는 gap과 같다.
		for (i = 0; i < gap; i++) {
			// 부분 리스트에 대한 삽입 정렬 수행
			shellSort(i, capacity - 1, gap);
		}
	}
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}


template<class T>
void Sort<T>::shellSort(int first, int last, int gap) {
	// gap만큼 떨어진 요소들을 삽입 정렬
	// 정렬의 범위는 first에서 last까지
	int i, j;
	T key;

	for (i = first + gap; i <= last; i = i + gap) {
		key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		// 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
		// j 값은 first 이상이어야 하고
		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
		for (j = i - gap; j >= first && arr[j] > key; j = j - gap) {
			arr[j + gap] = arr[j]; // 레코드를 gap만큼 오른쪽으로 이동
		}

		arr[j + gap] = key;
	}
}


template<class T>
void Sort<T>::exeQuickSort_Reculsive_Median()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : QuickSort_Reculsive(Median of Three)" << endl;
	cout << "정렬의 종류는 : QuickSort_Reculsive(Median of Three)" << endl;
	clock_t begin, end;
	begin = clock();
	quickSort_Reculsive(0, capacity - 1, true);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::exeQuickSort_Reculsive_NonMedian()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : QuickSort_Reculsive(first pivot)" << endl;
	cout << "정렬의 종류는 : QuickSort_Reculsive(first pivot)" << endl;
	clock_t begin, end;
	begin = clock();
	quickSort_Reculsive(0, capacity - 1, false);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::quickSort_Reculsive(int start, int end, bool isMedian)
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
	//Median-Of-Three
	if (isMedian == true)
	{
		if (arr[start] > arr[mid]) swap(arr[start], arr[end]);
		if (arr[mid] > arr[end]) swap(arr[mid], arr[end]);
		if (arr[start] > arr[mid]) swap(arr[start], arr[end]);
	}

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
	log << "정렬의 종류는 : quickSort_NonReculsive(median of three)" << endl;
	cout << "정렬의 종류는 : quickSort_NonReculsive(median of three)" << endl;
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
			int_t = (r + 1) >> 1; // 나누기 2의 의미
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
	log << "수행시간 : " << end - begin << "clock" << endl;
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
	log << "정렬의 종류는 : naturalMergeSort(Reculsive)" << endl;
	cout << "정렬의 종류는 : naturalMergeSort(Reculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	naturalMergeSort(capacity);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
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
	log << "정렬의 종류는 : MergeSort(NonReculsive)" << endl;
	cout << "정렬의 종류는 : MergeSort(NonReculsive)" << endl;
	clock_t begin, end;
	begin = clock();
	T *temp = new T[capacity];
	int i, j, k, size, l1, h1, l2, h2; // l1, l2는 나눈 구간의 처음,끝 h1,h2는 전체구간에서의 첫, 끝 index

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
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}


template<class T>
void Sort<T>::stdSort()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : std::sort" << endl;
	cout << "정렬의 종류는 : std::sort" << endl;
	clock_t begin, end;
	begin = clock();
	sort(arr, arr + capacity);
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}

template<class T>
void Sort<T>::selectionSort()
{
	log << "=============================================" << endl;
	log << "정렬의 종류는 : selectionSort" << endl;
	cout << "정렬의 종류는 : selectionSort" << endl;
	if (capacity >= CANT_MEASURE)
	{
		cout << "측정불가" << endl;
		log << "측정불가" << endl;
		log << "=============================================" << endl;
		return;
	}
	clock_t begin, end;
	begin = clock();

	int i, j, least;

	// 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
	for (i = 0; i < capacity - 1; i++) {
		least = i;

		// 최솟값을 탐색한다.
		for (j = i + 1; j < capacity; j++) {
			if (arr[j] < arr[least])
				least = j;
		}

		// 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
		if (i != least) {
			T temp = arr[i];
			arr[i] = arr[least];
			arr[least] = temp;
		}
	}

	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}







template<class T>
void Sort<T>::heapSort()
{
	clock_t begin, end;
	log << "정렬의 종류는 : Heap Sort" << endl;
	cout << "정렬의 종류는 : Heap Sort" << endl;
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
	log << "수행시간 : " << end - begin << "clock" << endl;
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
	log << "정렬의 종류는 : Bubble Sort" << endl;
	cout << "정렬의 종류는 : Bubble Sort" << endl;
	if (capacity >= CANT_MEASURE)
	{
		cout << "측정불가" << endl;
		log << "측정불가" << endl;
		log << "=============================================" << endl;
		return;
	}
	clock_t begin, end;
	begin = clock();
	int i, j;
	T temp;

	for (i = capacity - 1; i > 0; i--) {
		// 0 ~ (i-1)까지 반복
		for (j = 0; j < i; j++) {
			// j번째와 j+1번째의 요소가 크기 순이 아니면 교환
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	end = clock();
	log << "수행시간 : " << end - begin << "clock" << endl;
	log << "=============================================" << endl;
}