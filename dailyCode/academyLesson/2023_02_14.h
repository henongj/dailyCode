#pragma once
#include<iostream>

namespace academyLecture_2023_02_14
{
	void fGetMin(void)
	{

		int arData[5]{ 4,7,1,3,2 };
		int* pMin{};

		pMin = &arData[0];
		for (int i = 0; i < 5; i++)
		{
			if (*pMin > arData[i])
				pMin = &arData[i];
		}
	}
	void fAccessMatrixByPointer(void)
	{
		// make matrix and print it by pointer
		int nMatrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
		int* pMatrix = nMatrix[0];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d ", pMatrix[i * 3 + j]);
			}
			printf("\n");
		}
	}
	void fGetSmallestNumber(void)
	{
		int nInput1{};
		int nInput2{};
		int nInput3{};
		int* pSmallestInput{};

		scanf_s("%d", &nInput1);
		scanf_s("%d", &nInput2);
		scanf_s("%d", &nInput3);

		pSmallestInput = &nInput1;
		if (*pSmallestInput > nInput2)
			pSmallestInput = &nInput2;
		if (*pSmallestInput > nInput3)
			pSmallestInput = &nInput3;

		printf("Smallest input in three : %d", *pSmallestInput);
	}

	void fPointerAndArray(void)
	{
		int arData[5]{ 5,4,3,2,1 };
		int arMatrix[3][3] = { {9,8,7},{6,5,4},{3,2,1} };
		int* p{};

		p = &arData[2];

		// print
		printf("%d \n", *p);
		printf("%d \n", *p + 1);
		printf("%d \n", *(p + 1));
		printf("%d \n", *(p - 1));

		int** ppMatrix{};
		int* pMatrix{};

		ppMatrix = &pMatrix;
		pMatrix = arMatrix[0];

		for (int i = 0; i < 3; i++)
		{
			printf("%d ", p[i]);
		}
		printf("%d ", p[-2]);
		printf("%d ", p[-1]);
	}
}