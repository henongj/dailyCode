#include<iostream>

namespace academyLecture_2023_02_02
{
	void fPrintStartWithDoNotModifyCodeWhenModifyShape(void)
	{
		// 1. 별을 출력하는 코드를 수정하지 않고, 별의 모양을 바꾸는 코드
		int nNumberOfStar{};
		int nAdd{};

		nNumberOfStar = 5;
		nAdd = -1;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < nNumberOfStar; j++)
				printf("*");

			printf("\n");
			nNumberOfStar += nAdd;
		}
	}
	void fPrintStar(void)
	{
		printf("*****\n");
		printf("*****\n");
		printf("*****\n");
		printf("*****\n");
		printf("*****\n");

		for (int i = 0; i < 5; i++)
		{
			printf("*****\n");
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	void fBasicForLoop(void)
	{
		int nTotal{};
		for (int i = 0; i < 5; i++)
		{
			nTotal += i;
		}

		printf("%d\n", nTotal);
	}

}