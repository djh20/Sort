#include "sortManager.h"
#include <iostream>


void insertionSort(int capacity)
{
	cout << "(int)";
	Sort<int> test_A(capacity);
	test_A.insertionSort();
	cout << "(double)";
	Sort<double> test_B(capacity);
	test_B.insertionSort();
	cout << "(string)";
	Sort<string> test_C(capacity);
	test_C.insertionSort();
	cout << "(Rectangle)";
	Sort<Rectangle> test_D(capacity);
	test_D.insertionSort();

}