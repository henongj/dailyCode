#pragma once


#include<iostream>

void func_20230515(int nData);
void test_20230515(int nData);
int mainSpace02_20230515(void)
{
	void (*pFunc)(int) {};
	pFunc = &func_20230515;

	void(*lambdaFunc)(int) = [](int nData) -> void
	{
		printf("lambdaFunc : %d\n", nData);
	};

	(void)(*pFunc)(99);
	lambdaFunc(90);

	pFunc = &test_20230515;
	(void)(*pFunc)(111);

	return 0;
}

void func_20230515(int nData)
{
	printf("func_20230515 : %d\n", nData);
}

void test_20230515(int nData)
{
	printf("test_20230515 : %d\n", nData * 2);
}
