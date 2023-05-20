#pragma once
#include<iostream>

int add(int nData1, int nData2);
int sub(int nData1, int nData2);
int mul(int nData1, int nData2);
int divide(int nData1, int nData2);
int mod(int nData1, int nData2);
int mainSpace04_20230515(void)
{
	int nData1{};
	int nData2{};
	int nFlag{};

	int(*funcArr[5])(int, int) {};

	funcArr[0] = &add;
	funcArr[1] = &sub;
	funcArr[2] = &mul;
	funcArr[3] = &divide;
	funcArr[4] = &mod;

	while (nFlag != 5)
	{
		printf("0 add, 1 sub, 2 mul, 3 divide, 4 mod ||| else break \n");
		std::cin >> nFlag;

		printf("input number1 : ");
		std::cin >> nData1;

		printf("input number2 :");
		std::cin >> nData2;

		printf("answer : %d\n", (*funcArr[nFlag])(nData1, nData2));

	}


	return 0;
}

int add(int nData1, int nData2)
{
	return nData1 + nData2;
}

int sub(int nData1, int nData2)
{
	return nData1 - nData2;
}

int mul(int nData1, int nData2)
{
	return nData1 * nData2;
}

int divide(int nData1, int nData2)
{
	return nData1 / nData2;
}

int mod(int nData1, int nData2)
{
	return nData1 % nData2;
}

