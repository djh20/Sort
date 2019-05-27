#include "SortingManager.h"

void SortingManager::measureSort(void(*fptr)(int), int capacity)
{
	clock_t begin, end;
	begin = clock();
	fptr(capacity);
	end = clock();
	cout << "����ð� : " << double((end - begin)) / CLOCKS_PER_SEC << "s" << endl;
}



SortingManager::SortingManager()
{
	
}


SortingManager::~SortingManager()
{
}
