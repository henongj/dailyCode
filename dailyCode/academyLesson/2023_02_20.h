#pragma once
#include<iostream>


namespace academyLecture_2023_02_20
{
	void printData(const int* arData, int nLength);
	
	// 자 int** p 에서 *p가 배열일까 **p가 배열일까.
	void exampleFunc1(int** p, int nSize);
	// 자료형이 꼬일 것 같으면 이렇게 해준다. 그리고 이러면 번거로우니 이렇게 안 만든다
	void exampleFunc2(int(*p)[], int nSize);

	void getSmallestNumber(int nNumber1, int nNumber2, int nNumber3, int* nSmallest);
	void getSumOfArray(const int* arrNumbers, const int nSize, int* nSum);
	void swapTwoNumber(int* nNumber1, int* nNumber2);

	int funcMain(void)
	{
		int arMain1[3]{ 3,2,1 };
		int arMain2[5]{ 5,4,3,2,1 };
		printData(arMain1, 3);
		printData(arMain2, 5);

		int nSmallest{};
		int nN{};
		nN = 23;
		getSmallestNumber(13, 5, 7, &nSmallest);
		printf("Smallest number is %d\n", nSmallest);

		getSumOfArray(arMain2, 5, &nSmallest);
		printf("Sum of array is %d\n", nSmallest);

		swapTwoNumber(&nSmallest, &nN);
		printf("Swapped number is %d, %d\n", nSmallest, nN);
	}

	void printData(const int* arData, int nLength)
	{
		for (int i = 0; i < nLength; i++)
			printf("%d ", arData[i]);
		puts("");
	}

	void getSmallestNumber(int nNumber1, int nNumber2, int nNumber3, int* nSmallest)
	{
		*nSmallest = nNumber1;
		if (*nSmallest > nNumber2)
			*nSmallest = nNumber2;
		if (*nSmallest > nNumber3)
			*nSmallest = nNumber3;
	}

	void getSumOfArray(const int* arrNumbers, int nSize, int* nSum)
	{
		*nSum = 0;
		for (int i = 0; i < nSize; i++)
			*nSum += arrNumbers[i];
	}

	void swapTwoNumber(int* nNumber1, int* nNumber2)
	{
		int nTemp = *nNumber1;
		*nNumber1 = *nNumber2;
		*nNumber2 = nTemp;
	}

}