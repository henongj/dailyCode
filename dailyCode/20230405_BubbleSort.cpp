#include "20230405_BubbleSort.h"
#include<stdio.h>
void N20230405_bubleSort::swapInt(int& nNumber1, int& nNumber2)
{
	int nTemp{};
	nTemp = nNumber1;
	nNumber1 = nNumber2;
	nNumber2 = nTemp;
}

void N20230405_bubleSort::bubbleSortingLogic(int* arrList, int nSize, bool bAscending)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if ( (bAscending && arrList[i] > arrList[i + 1]) || (!bAscending && arrList[i] < arrList[i+1]) )
			swapInt(arrList[i],arrList[i+1]);
	}
}

void N20230405_bubleSort::bubbleSort(int* arrList, int nSize, bool bAscending)
{
	while (nSize > 1)
	{
		bubbleSortingLogic(arrList, nSize, bAscending);
		nSize--;
	}
}

void N20230405_bubleSort::printArr(int* arrList, int nSize)
{
	for (int i = 0; i < nSize; i++)
		printf("%d ", arrList[i]);
}

int N20230405_bubleSort::runSpace(void)
{
	const int nArrSize = 9;
	bool bAscendingFlag{};
	int arr[nArrSize] = { 4,8,1,3,99,2,5,7,6 };

	bAscendingFlag = false;

	N20230405_bubleSort::bubbleSort(arr, nArrSize, bAscendingFlag);
	N20230405_bubleSort::printArr(arr, nArrSize);
	
	return 0;
}
