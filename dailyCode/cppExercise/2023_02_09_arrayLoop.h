#include<iostream>

namespace cppExercise_2023_02_09
{
	void fArrayFillZigzagWithAI(void)
	{
		// make array 5 by 5 fill by zigzag list { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
		int arr[5][5] = { 0, };
		int num = 1;
		int x = 0, y = 0;
		int dir = 1;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				arr[y][x] = num;
				num++;
				x += dir;
			}
			dir *= -1;
			x += dir;
			y++;
		}

		//3자리수 단위로 출력해라
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				std::cout.width(3);
				std::cout << arr[i][j];
			}
			std::cout << std::endl;
		}
	}

	void fArrayFillZigzag2(void)
	{
		int arData[5][4]{};
		int nData{};
		int nIndex1{};
		int nIndex2{};
		int nAddForIndex2{};
		int nAddForData{};

		nAddForIndex2 = 4;
		nAddForData = 1;

		nData++;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arData[i][j] = nData;

				nData += nAddForData;
			}
			arData[i][3] = nData;
			nData += nAddForIndex2;

			nAddForData *= -1;
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