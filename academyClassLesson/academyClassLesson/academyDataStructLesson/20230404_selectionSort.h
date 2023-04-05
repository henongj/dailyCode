#include<iostream>


int findMinimumDataIndex(const int* arrList, int nLength);
void selectionSortLogic(int* arrList, int nLength);
void selectionSort(int* arrList, int nLength);
void swapData(int& nData1, int& nData2);
void printData(const int* pData, int nLength);

void runSpace(void)
{
	const int nArrayLength = 9;
	int arrayData[nArrayLength] = { 71,4,2,4,0,9,6,5,11 };

	std::cout << findMinimumDataIndex(arrayData, nArrayLength) << "\n\n";

	{
		selectionSort(arrayData, nArrayLength);
		printData(arrayData, nArrayLength);
	}
}


void selectionSortLogic(int* arrList, int nLength)
{
	swapData(arrList[0], arrList[findMinimumDataIndex(arrList,nLength)]);
}

void selectionSort(int* arrList, int nLength)
{
	while (nLength > 1)
	{
		selectionSortLogic(arrList, nLength);
		arrList++;
		nLength--;
	}
}

int findMinimumDataIndex(const int* arrList, int nLength)
{
	int nMinimumIndex{};

	for (int i = 1; i < nLength; i++)
	{
		if (arrList[nMinimumIndex] > arrList[i])
			nMinimumIndex = i;
	}
	return nMinimumIndex;
}


void swapData (int& nData1, int& nData2)
{
	int nTemp{};
	nTemp = nData1;
	nData1 = nData2;
	nData2 = nTemp;
}

void printData(const int* pData, int nLength)
{
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", pData[i]);
	}
	printf("\n");
}
