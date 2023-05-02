#pragma once


#include<iostream>

void printData02_20230502(const int* pData, int nLength);
void mergeSort01_20230502(int* pArr, int nLength, int* pDestArr);

int mainSpace01_20230502(void)
{

	//4 6 7 5 9 8 2 1 3
	int arData[9] = { 5,7,9,8,1,3,2,4,6 };
	int arrTemp[9] = { };
	int nLength = 9;
	
	int* pData = arData;
	int* pArrTemp = arrTemp;


	int* pLeftData = pData;
	int nLeftLength = nLength / 2;

	int* pRightData = pData + nLeftLength;
	int nRightLength = nLength - nLeftLength;

	printData02_20230502(pLeftData, nLeftLength);
	printData02_20230502(pRightData, nRightLength);


	int nLeftIndex{};
	int nRightIndex{};

	nLeftIndex = 0;
	nRightIndex = 0;
	
	mergeSort01_20230502(pData, nLength, pArrTemp);

	printData02_20230502(arrTemp, nLength);

	return 0;
}

void printData02_20230502(const int* pData, int nLength)
{
	for (int i = 0; i < nLength; i++)
		printf("%d ", pData[i]);
	printf("\n");
}

//must pTmpLength >= nLength
void mergeSort01_20230502(int* pArr, int nLength, int* pDestArr)
{
	if (nLength <= 1)
		return;
	
	int* pData = pArr;
	int* pArrTemp = pDestArr;

	int* pLeftData = pData;
	int nLeftLength = nLength / 2;

	int* pRightData = pData + nLeftLength;
	int nRightLength = nLength - nLeftLength;

	mergeSort01_20230502(pLeftData, nLeftLength, pArrTemp);
	mergeSort01_20230502(pRightData, nRightLength, pArrTemp);
	
	int nLeftIndex{};
	int nRightIndex{};

	nLeftIndex = 0;
	nRightIndex = 0;

	for (int i = 0; i < nLength; i++)
	{
		int* pSmall = pLeftData;
		int* pTempIndex = &nLeftIndex;

		if ((nLeftIndex >= nLeftLength) || 
			(  (nRightIndex < nRightLength) && (pLeftData[nLeftIndex] > pRightData[nRightIndex])  ) )
		{
			pSmall = pRightData;
			pTempIndex = &nRightIndex;
		}

		pArrTemp[i] = pSmall[*pTempIndex];
		(*pTempIndex)++;
	}

	//임시공간에 있는 정렬 내용을 원본에 집어넣어 준다
	for (int i = 0; i < nLength; i++)
	{
		pArr[i] = pArrTemp[i];
	}
}
