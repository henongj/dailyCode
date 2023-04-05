#include "insertionSort.h"
#include<iostream>
void n20230405_intersionLogic::insertionSortLogic(int* arrList, int nLength, int nInsertData)
{
	int nIndex{};
	nIndex = nLength - 2;

	while (nIndex >= 0 && arrList[nIndex] > nInsertData)
	{
		arrList[nIndex + 1] = arrList[nIndex];
		nIndex--;
	}

	arrList[nIndex + 1] = nInsertData;
}

void n20230405_intersionLogic::insertionSort(int* arrList, int nLength)
{
	int nSortLength = 2;
	while (nSortLength <= nLength)
	{
		insertionSortLogic(arrList, nSortLength, arrList[nSortLength - 1]);
		nSortLength++;
	}
}

void n20230405_intersionLogic::printArr(const int* arr, int nLength)
{
	for (int i = 0; i < nLength; i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

int n20230405_intersionLogic::run()
{
	int arData[9] = { 4, 91, 75, 1, 33, 25, 5, 4, 7 };

	int* arrList = arData;
	int nLength = 9;

	printArr(arrList, nLength);

	insertionSort(arrList, nLength);

	printArr(arrList, nLength);
	return 0;
}
