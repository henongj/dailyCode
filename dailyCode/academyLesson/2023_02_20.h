#pragma once
#include<iostream>


namespace academyLecture_2023_02_20
{
	void printData(const int* arData, int nLength);

	int funcMain(void)
	{
		int arMain1[3]{ 3,2,1 };
		int arMain2[5]{ 5,4,3,2,1 };
		printData(arMain1, 3);
		printData(arMain2, 5);


	}

	void printData(const int* arData, int nLength)
	{
		for (int i = 0; i < nLength; i++)
			printf("%d ", arData[i]);
		puts("");
	}
}