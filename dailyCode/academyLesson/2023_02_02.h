#include<iostream>

namespace academyLecture_2023_02_02
{
	void fPrintStarWithDoNotModifyCodeWhenModifyShape2(void) {
		int nXCount{};
		int nOCount{};
		int nXIncrementValue{};
		int nOIncrementValue{};
		int nNumberOfLines{};

		nXCount = 4;
		nOCount = 1;
		nXIncrementValue = -1;
		nOIncrementValue = 1;
		nNumberOfLines = nXCount + nOCount;

		for (int i = 0; i < nNumberOfLines; i++)
		{
			for (int i = 0; i < nOCount; i++)
			{
				printf("O");
			}
			for (int i = 0; i < nXCount; i++)
			{
				printf("X");
			}

			nOCount += nOIncrementValue;
			nXCount += nXIncrementValue;
			printf("\n");
		}
	}

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