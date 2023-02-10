#pragma once

#include<iostream>

namespace cppExercise_2023_02_10
{
		
	void fFillArraySpiralOrder(void)
	{
		int arData[5][5]{};
		int nData{};
		int arClockDirection[4][2]{ {0,1},{1,0},{0,-1},{-1,0} };
		int nIndex1{};
		int nIndex2{};
		int nIndexClockDirection{};

		int nLength{};
		int nLoop{};

		nLoop = 1;
		nLength = 5;
		nData = 1;
		nIndex1 = 0;
		nIndex2 = -1;
		nIndexClockDirection = 0;

		while (nData <= 25)
		{
			for (int i = 0; i < nLoop; i++)
			{
				for (int j = 0; j < nLength; j++)
				{
					nIndex1 += arClockDirection[nIndexClockDirection][0];
					nIndex2 += arClockDirection[nIndexClockDirection][1];
					arData[nIndex1][nIndex2] = nData;
					nData++;
				}
				nIndexClockDirection = (nIndexClockDirection + 1) % 4;
			}

			nLength--;
			if (nLoop == 1)
				nLoop = 2;

		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%3d ", arData[i][j]);
			}
			printf("\n");
		}
	}
}