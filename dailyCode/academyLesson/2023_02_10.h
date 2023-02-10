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
}