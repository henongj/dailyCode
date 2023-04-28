#pragma once
 
#include<iostream>

void printData02_20230428(const int* pData, int nLength);
void mergeSort01_20230428(int* pArr, int nLength, int* pDestArr);


int mainSpace01_20230428(void)
{

	//4 6 7 5 9 8 2 1 3
	int arData[9] = { 3,5,6,7, 1, 2, 4, 8, 9 };
	int arrTemp[9] = { };
	int* pData = arData;
	int* pArrTemp = arrTemp;

	int nLength = 9;

	int* pLeftData = pData;
	int nLeftLength = nLength / 2;

	int* pRightData = pData + nLeftLength;
	int nRightLength = nLength - nLeftLength;

	printData02_20230428(pLeftData, nLeftLength);
	printData02_20230428(pRightData, nRightLength);


	{
		int nTempArrIndex = 0;
		int nLeftIndex = 0;
		int nRightIndex = 0;
		while (nTempArrIndex < nLength)
		{
			int* nSmall = &pLeftData[nLeftIndex];
			int* pBigDataIndex = &nLeftIndex;
			if ((nLeftIndex >= nLeftLength) || (pLeftData[nLeftIndex] > pRightData[nRightIndex]))
			{
				nSmall = &pRightData[nRightIndex];
				pBigDataIndex = &nRightIndex;
			}

			pArrTemp[nTempArrIndex] = *nSmall;

			(*pBigDataIndex)++;
			nTempArrIndex++;
		}
	}

	printData02_20230428(arrTemp, nLength);

	return 0;
}

void printData02_20230428(const int* pData, int nLength)
{
	for (int i = 0; i < nLength; i++)
		printf("%d ", pData[i]);
	printf("\n");
}

void mergeSort01_20230428(int* pArr, int nLength, int* pDestArr)
{
	int nLength = 9;

	int* pLeftData = pArr;
	int nLeftLength = nLength / 2;

	int* pRightData = pArr + nLeftLength;
	int nRightLength = nLength - nLeftLength;

	int nTempArrIndex = 0;
	int nLeftIndex = 0;
	int nRightIndex = 0;
	while (nTempArrIndex < nLength)
	{
		int* nSmall = &pLeftData[nLeftIndex];
		int* pBigDataIndex = &nLeftIndex;
		if ((nLeftIndex >= nLeftLength) || (pLeftData[nLeftIndex] > pRightData[nRightIndex]))
		{
			nSmall = &pRightData[nRightIndex];
			pBigDataIndex = &nRightIndex;
		}

		pDestArr[nTempArrIndex] = *nSmall;

		(*pBigDataIndex)++;
		nTempArrIndex++;
	}
}
