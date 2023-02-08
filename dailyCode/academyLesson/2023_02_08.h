#include<iostream>

namespace academyLecture_2023_02_07
{
	void fArrayWarning(void)
	{
		int arData[3][4]{};

		// 이거 굴러간다
		arData[1][4] = 99;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%d ", arData[i][j]);
			}
			printf("\n");
		}
	}
	void fArrayFill(void)
	{
		int arData[3][4]{};
		int nNumber{};

		nNumber = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arData[i][j] = nNumber;
				nNumber++;
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

		nNumber = 1;
		for (int i = 0; i < 12; i++)
		{
			int nIndex1 = i / 4;
			int nIndex2 = i % 4;
			arData[nIndex1][nIndex2] = nNumber;
			nNumber++;
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
}