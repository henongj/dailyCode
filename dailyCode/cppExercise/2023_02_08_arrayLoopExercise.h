#include<iostream>

namespace cppExercise_2023_02_08
{
	void fArrayFillToZigzag(void)
	{
		int arData[5][5]{};
		int nData{};
		int nIndex2{};
		int nIncrementValue{};
		int nEndIndex1{};
		int nEndIndex2{};

		nEndIndex1 = -1;
		nEndIndex2 = 5;

		nData = 1;
		nIndex2 = 0;
		nIncrementValue = 1;

		for (int i = 0; i < 5; i++)
		{
			while (nIndex2 != nEndIndex1 && nIndex2 != nEndIndex2)
			{
				arData[i][nIndex2] = nData;

				nData++;
				nIndex2 += nIncrementValue;
			}

			if (nIndex2 == nEndIndex1)
				nIndex2++;
			else
				nIndex2--;
			nIncrementValue *= -1;
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