#pragma once
#include<iostream>


namespace academyLecture_2023_02_16
{

	void func(int nData);
	void funcP(int* pData);
	void func2(int nData);
	void func3(int* nData);
	int mainSpace(void)
	{
		int nData{};
		int nDataMain{};

		nData = 99;
		nDataMain = 25;

		func2(nDataMain);
		printf("%d\n", nDataMain);

		func3(&nDataMain);
		printf("%d\n", nDataMain);


	}

	void func(int nData)
	{
		printf("%d\n", nData);
	}

	void funcP(int* pData)
	{
		printf("%d\n", *pData);
	}

	void func2(int nData)
	{
		// 값이 안 바뀐다
		nData = 100;
	}

	void func3(int* nData)
	{
		// 값이 바뀐다
		*nData = 100;
	}

}