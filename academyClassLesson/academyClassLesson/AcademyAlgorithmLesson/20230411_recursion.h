#pragma once
#include<iostream>

void f20230411_test01();
void f20230411_test02(int nTimes);
void f20230411_printNumberWithRecursion(int nData);
void f20230411_printNumberWithRecursion2(int nData);
void f20230411_printNumberAscendingOrderWithRecursion(int nData);
void f20230411_printNumberAwscendingOrderWithRecursion_logic(int nData, int nTimes);

int f20230411_mainSpace01(void)
{
	// f20230411_test01();
	// f20230411_test02(10);
	f20230411_printNumberWithRecursion(10);
	return 0;
}

void f20230411_test01()
{
	printf("test\n");
	// 오버플로우 
	// f20230411_test01();
}

void f20230411_test02(int nTimes)
{
	if (nTimes == 0)
		return;

	printf("%d\n", nTimes);
	f20230411_test02(nTimes - 1);
}

void f20230411_printNumberWithRecursion(int nData)
{
	if (nData == 0)
	{
		printf("\n");
		return;
	}

	printf("%d ", nData);

	f20230411_printNumberWithRecursion(nData - 1);
}


void f20230411_printNumberAscendingOrderWithRecursion(int nData)
{
	f20230411_printNumberAwscendingOrderWithRecursion_logic(nData, 1);
}

void f20230411_printNumberAwscendingOrderWithRecursion_logic(int nData, int nTimes)
{
	if (nData < nTimes)
	{
		printf("\n");
		return;
	}

	printf("%d ", nTimes);

	f20230411_printNumberAwscendingOrderWithRecursion_logic(nData, nTimes + 1);
}

void f20230411_printNumberWithRecursion2(int nData)
{
	if (nData == 0)
		return;

	f20230411_printNumberWithRecursion2(nData - 1);
	printf("%d ", nData);
}
