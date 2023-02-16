#pragma once
#include<iostream>

namespace academyLecture_2023_02_10
{
	void fArrayFillZigzag3(void)
	{
		int arData[5][4]{};
		int nData{};
		int nIndex1{};
		int nIndex2{};
		int nAdd{};

		nAdd = 1;

		nData++;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arData[nIndex1][nIndex2] = nData;

				nData++;
				nIndex2 += nAdd;
			}
			nIndex1++;
			nAdd *= -1;
			nIndex2 += nAdd;
		}

		//print arData
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%3d ", arData[i][j]);
			}
			puts("");
		}

	}

	void fFillArrayZigzag(void)
	{
		int arData[5][4]{};
		int nData{};
		int nIncrementvalue{};

		nData = 1;
		nIncrementvalue = 1;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//데이터 입력 후 1 or -1 증가
				arData[i][j] = nData;

				nData += nIncrementvalue;
			}
			// 데이터 입력 후 4증가
			nIncrementvalue *= -1;
			arData[i][3] = nData;
			nData += 4;
		}


		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%3d ", arData[i][j]);
			}
			puts("");
		}
	}
}