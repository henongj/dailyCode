#pragma once
#include<iostream>

void swapData_20230428(int& nData1, int& nData2);
void printData_20230428(const int* pData, int nLength);
void quickSortLogic_20230428(int* arrData, int nLength);
int mainSpace01_20230428(void)
{
	//4 6 7 5 9 8 2 1 3
	int arData[9] = { 4, 6, 7, 5, 9, 8, 2, 1, 3 };
	int nLength = 9;
	int nPivoit = 0;
	int nLow = 1;
	int nHigh = nLength - 1;

	quickSortLogic_20230428(arData, nLength);
	printData_20230428(arData, nLength);

	return 0;
}



void swapData_20230428(int& nData1, int& nData2)
{
	int nTemp = nData1;
	nData1 = nData2;
	nData2 = nTemp;
}

void printData_20230428(const int* pData, int nLength)
{
	for (int i = 0; i < nLength; i++)
		std::cout << pData[i] << " ";
	std::cout << std::endl;
}

void quickSortLogic_20230428(int* arrData, int nLength)
{
	if (nLength <= 1)
		return;

	int nPivoit = 0;
	int nLow = 1;
	int nHigh = nLength - 1;
	// nLow가 증가하다가 nHigh보다 1 크면 pivot과 nHigh가 교환
	while (nLow <= nHigh)
	{
		while (nLow < nLength && arrData[nLow] < arrData[nPivoit])
			nLow++;
		while (arrData[nHigh] > arrData[nPivoit])
			nHigh--;

		if (nLow < nHigh)
			swapData_20230428(arrData[nLow], arrData[nHigh]);
		else
			swapData_20230428(arrData[nPivoit], arrData[nHigh]);
	}

	quickSortLogic_20230428(arrData, nHigh);
	quickSortLogic_20230428(arrData + nLow, nLength - nLow);
}
