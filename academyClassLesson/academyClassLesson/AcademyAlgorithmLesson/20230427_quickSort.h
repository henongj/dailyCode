#pragma once
#include<iostream>

void swapData_20230427(int& nData1, int& nData2);
void printData_20230427(const int* pData, int nLength);
void quickSortLogic_20230427(int* arrData, int nLength, int nPivoit, int nLow, int nHigh);
int mainSapce01_20230427(void)
{
	//4 6 7 5 9 8 2 1 3
	int arData[9] = { 4, 6, 7, 5, 9, 8, 2, 1, 3 };
	int nLength = 9;
	int nPivoit = 0;
	int nLow = 1;
	int nHigh = nLength - 1;

	quickSortLogic_20230427(arData, nLength, nPivoit, nLow, nHigh);

	return 0;
}



void swapData_20230427(int& nData1, int& nData2)
{
	int nTemp = nData1;
	nData1 = nData2;
	nData2 = nTemp;
}

void printData_20230427(const int* pData, int nLength)
{
	for (int i = 0; i < nLength; i++)
		std::cout << pData[i] << " ";
	std::cout << std::endl;
}

void quickSortLogic_20230427(int* arrData, int nLength, int nPivoit, int nLow, int nHigh)
{
	// nLow가 증가하다가 nHigh보다 1 크면 pivot과 nHigh가 교환
	while (nLow < nHigh)
	{
		while (arrData[nLow] < arrData[nPivoit])
			nLow++;
		while (arrData[nHigh] > arrData[nPivoit])
			nHigh--;

		if (nLow < nHigh)
			swapData_20230427(arrData[nLow], arrData[nHigh]);
		else
			swapData_20230427(arrData[nPivoit], arrData[nHigh]);

		printData_20230427(arrData, nLength);
	}

}
