#pragma once
#include<stdio.h>
void printData_20230515(const int* pData, int nLength, int nPivot, bool (*pCompare)(int, int));

bool greater(int nDst, int nSrc);
bool less(int nDst, int nSrc);

int mainSpace03_20230515(void)
{
	int arrData[9] = { 17, 20, 33, 42, 55, 6, 7, 81, 9 };

	printData_20230515(arrData, 9, 40, &greater);
	printData_20230515(arrData, 9, 40, &less);
}

void printData_20230515(const int* pData, int nLength, int nPivot, bool(*pCompare)(int, int))
{
	for (int i = 0; i < nLength; i++)
	{
		if (pCompare(pData[i], nPivot))
			printf("%d ", pData[i]);
	}
	printf("\n");
}

bool greater(int nDst, int nSrc)
{
	return nDst > nSrc;
}

bool less(int nDst, int nSrc)
{
	return nDst < nSrc;
}
