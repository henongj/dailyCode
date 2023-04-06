#include "bubbleSort.h"
#include<stdio.h>
void n20230406_bubbleSort::swapInt(int& nData1, int& nData2)
{
	int nTemp{};
	nTemp = nData1;
	nData1 = nData2;
	nData2 = nTemp;
}

void n20230406_bubbleSort::bubbleSort(int* pArrayList, int nArrayLength)
{
	while (nArrayLength > 1)
	{
		bubbleSortLogic(pArrayList, nArrayLength);
		nArrayLength--;
	}
}

void n20230406_bubbleSort::bubbleSortLogic(int* pArrayList, int nArrayLength)
{
	for (int i = 0; i < nArrayLength - 1; i++)
	{
		if (pArrayList[i] > pArrayList[i + 1])
			swapInt(pArrayList[i], pArrayList[i + 1]);
	}
}

void n20230406_bubbleSort::printArray(int* pArrayList, int nArrayLength)
{
	for (int i = 0; i < nArrayLength; i++)
		printf("%d ", pArrayList[i]);
	printf("\n");
}

void n20230406_bubbleSort::runSpace(void)
{
	const int nArrayLength = 10;
	int nArrayList[nArrayLength] = { 5, 66, 12, 4, 9, 11, 16, 652, 97, 10 };
	
	printArray(nArrayList, nArrayLength);
	bubbleSort(nArrayList, nArrayLength);
	printArray(nArrayList, nArrayLength);
}
