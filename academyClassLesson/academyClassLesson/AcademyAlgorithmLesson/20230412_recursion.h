#pragma once
#include<iostream>

void f20230412_add01(int nData, int& nResult);
void f20230412_add02(int nData, int& nResult);
void f20230412_fibonacchi_1(int nData, int* pResult);
void f20230412_fibonacchi_2(int nData, int* pResult);
void f20230412_fibonacchi_3(int nData, int* pResult);
int GCD(int nData1, int nData2);
int GCD_2(int nData1, int nData2);
int mainSpace01_20230413(void)
{
	int nResult{};
	nResult = 0;

	f20230412_fibonacchi_1(5, &nResult);

	printf("fibonacchi 1 : %d\n", nResult);

	nResult = 0;
	f20230412_fibonacchi_2(5, &nResult);

	printf("fibonacchi 2 : %d\n", nResult);

	nResult = 0;
	f20230412_fibonacchi_3(5, &nResult);

	printf("fibonacchi 3 : %d\n", nResult);

	int nData1 = 42;
	int nData2 = 27;
	int result = GCD(nData1, nData2);
	printf("\nGCD : %d\n", result);

	int result2 = GCD_2(nData1, nData2);
	printf("GCD 2 : %d\n", result2);

	return 0;
}


void f20230412_fibonacchi_1(int nData, int* pResult)
{
	if (nData < 0)
		return;

	if (nData == 0)
		*pResult = *pResult + 1;

	f20230412_fibonacchi_1(nData - 2, pResult);
	f20230412_fibonacchi_1(nData - 1, pResult);
}

void f20230412_fibonacchi_2(int nData, int* pResult)
{
	if (nData == 0 || nData == 1)
	{
		*pResult = *pResult + 1;
		return;
	}

	f20230412_fibonacchi_2(nData - 2, pResult);
	f20230412_fibonacchi_2(nData - 1, pResult);
}

void f20230412_fibonacchi_3(int nData, int* pResult)
{
	if (nData == 0 || nData == 1)
	{
		*pResult = 1;
		return;
	}

	int nResult1{};
	int nResult2{};
	f20230412_fibonacchi_3(nData - 2, &nResult1);
	f20230412_fibonacchi_3(nData - 1, &nResult2);

	*pResult = nResult1 + nResult2;
}

int GCD(int nData1, int nData2)
{
	int nRemainder = nData1 % nData2;
	if (nRemainder == 0)
		return nData2;

	return GCD(nData2, nRemainder);
}

int GCD_2(int nData1, int nData2)
{
	return (nData1 % nData2) == 0 ? nData2 : GCD(nData2, nData1 % nData2);
}

void f20230412_add01(int nData, int& nResult)
{
	if (nData == 0)
		return;

	nResult += nData;
	f20230412_add01(nData - 1, nResult);
}

void f20230412_add02(int nData, int& nResult)
{
	if (nData == 0)
		return;

	f20230412_add02(nData - 1, nResult);
	nResult += nData;
}

