#include<iostream>

namespace cppExercise_2023_02_02
{
	void loopExercise(void)
	{
		int nStarCount{};
		int nIncrementOfStars{};
		int nBlankCount{};
		int nIncrementOfBlanks{};
		int nLineCount{};

		nLineCount = 4;
		nStarCount = 1;
		nBlankCount = 5;
		nIncrementOfStars = 1;
		nIncrementOfBlanks = 0;


		for (int i = 0; i < nLineCount; i++)
		{
			for (int j = 0; j < nBlankCount; j++)
				printf(" ");

			for (int j = 0; j < nStarCount; j++)
				printf("*");

			printf("\n");
			nStarCount += nIncrementOfStars;
			nBlankCount += nIncrementOfBlanks;

		}

		nLineCount = 3;
		nStarCount = 3;
		nBlankCount = 5;
		nIncrementOfStars = -1;
		nIncrementOfBlanks = 0;


		for (int i = 0; i < nLineCount; i++)
		{
			for (int j = 0; j < nBlankCount; j++)
				printf(" ");

			for (int j = 0; j < nStarCount; j++)
				printf("*");

			printf("\n");
			nStarCount += nIncrementOfStars;
			nBlankCount += nIncrementOfBlanks;

		}
	}
	void betterPrintStar2(void)
	{
		int nStarCount{};
		int nIncrementOfStars{};
		int nBlankCount{};
		int nIncrementOfBlanks{};
		int nLineCount{};

		nLineCount = 5;
		nStarCount = 1;
		nBlankCount = 4;
		nIncrementOfStars = 2;
		nIncrementOfBlanks = -1;


		for (int i = 0; i < nLineCount; i++)
		{
			for (int j = 0; j < nBlankCount; j++)
				printf(" ");

			for (int j = 0; j < nStarCount; j++)
				printf("*");

			printf("\n");
			nStarCount += nIncrementOfStars;
			nBlankCount += nIncrementOfBlanks;

		}
	}
	void betterPrintStar(void)
	{
		int nNumberOfStar{};
		int nAdd{};

		nNumberOfStar = 5;
		nAdd = -1;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < nNumberOfStar; j++)
				std::printf("*");

			std::printf("\n");
			nNumberOfStar += nAdd;
		}

		std::printf("\n");

		nNumberOfStar = 1;
		nAdd = 1;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < nNumberOfStar; j++)
				std::printf("*");

			std::printf("\n");
			nNumberOfStar += nAdd;
		}

		std::printf("\n");
	}
}