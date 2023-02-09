#pragma once

#include<iostream>

namespace academyLecture_2023_02_09
{
	void fArrayFillZigzag2(void)
	{
		int arData[5][4]{};
		int nAdd{};
		int nIndex1{};
		int nIndex2{};
		int nEndIncresingIndex2{};
		int nEndDecresingIndex2{};
		int nData{};

		nData = 1;
		nIndex1 = 0;
		nIndex2 = 0;
		nEndDecresingIndex2 = -1;
		nEndIncresingIndex2 = 4;
		nAdd = 1;
		for (int i = 0; i < 5; i++)
		{
			while (nIndex2 < nEndIncresingIndex2 && nIndex2 > nEndDecresingIndex2)
			{
				arData[nIndex1][nIndex2] = nData;

				nIndex2 += nAdd;
				nData++;
			}

			nIndex1++;
			if (nIndex2 > 3)
				nIndex2 = 3;
			else
				nIndex2 = 0;
			nAdd *= -1;
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%3d ", arData[i][j]);
			}
			printf("\n");
		}
	}
	void fRemindArrayLoop(void)
	{
		int arData[3][4]{};
		int nIndex1{};
		int nIndex2{};
		int nData{};

		nData = 1;
		for (int i = 0; i < 12; i++)
		{
			arData[nIndex1][nIndex2] = nData;

			nData++;
			nIndex2++;
			if (nIndex2 == 4)
			{
				nIndex2 = 0;
				nIndex1++;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%3d ", arData[i][j]);
			}
			printf("\n");
		}

	}
	
	void fArrayMagicField(void)
	{
		int arData[5][5]{};
		int nIndex1{};
		int nIndex2{};
		int nData{};

		nIndex1 = 0;
		nIndex2 = 2;
		nData = 1;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arData[nIndex1][nIndex2] = nData;

				if (nIndex1 <= 0)
					nIndex1 = 4;
				else
					nIndex1--;
				if (nIndex2 >= 4)
					nIndex2 = 0;
				else
					nIndex2++;
				nData++;
			}

			arData[nIndex1][nIndex2] = nData;
			if (nIndex1 <= 4)
				nIndex1 = 0;
			else
				nIndex1++;
			nData++;
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%3d ", arData[i][j]);
			}
			puts("");
		}
	}
}
