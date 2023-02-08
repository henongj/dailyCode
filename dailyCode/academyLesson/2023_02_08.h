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
}