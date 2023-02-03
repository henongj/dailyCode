#include<iostream>

namespace academyLecture_2023_02_03
{
	void fPrintOXWithTwoFor(void)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == j || i + j == 4)
					printf("X");
				else
					printf("O");
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i <= j)
					printf("X");
				else
					printf("O");
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i >= j)
					printf("X");
				else
					printf("O");
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i < j)
					printf("O");
				else
					printf("X");
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i > j)
					printf("O");
				else
					printf("X");
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i + j <= 3 || (9 / 2) < j - i)
					printf("O");
				else
					printf("X");

			}
			printf("\n");
		}
	}
}