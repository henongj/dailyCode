#include<iostream>

namespace lecture_2023_01_30
{
	void fWrongLoopTest1(void)
	{
		int nData{};

		scanf_s("%d", &nData);

		while (nData < 10)
		{
			printf("Âü");
			nData = 10;
		}
	}

	void fBasicLoopTest1(void)
	{
		int nData{};

		scanf_s("%d", &nData);
		while (nData < 10)
		{
			printf("%d\n", nData);
			nData++;
		}

		for (int i = 0; i < 10; i++)
		{
			printf("%d\n", i);
		}
	}

	void fBasicLoop2(void)
	{
		int nBigNumber{};
		int nSmallNumber{};

		scanf_s("%d", &nSmallNumber);
		scanf_s("%d", &nBigNumber);

		if (nBigNumber < nSmallNumber)
		{
			int nNumberForSwap = nBigNumber;
			nBigNumber = nSmallNumber;
			nSmallNumber = nNumberForSwap;
		}

		int nIterator = nSmallNumber;
		while (nIterator <= nBigNumber)
		{
			printf("while : %d\n", nIterator);

			nIterator++;
		}

		for (int nIterator = nSmallNumber; nIterator <= nBigNumber; nIterator++)
			printf("for : %d\n", nIterator);
	}

	void fGetAllDivisor(void)
	{
		int nData{};
		int nDivisor{};
		int nDividend{};

		scanf_s("%d", &nData);
		nDivisor = 1;
		nDividend = nData;

		while (nDivisor <= nDividend)
		{
			if (nDividend % nDivisor == 0)
				printf("¾à¼ö : %d\n", nDivisor);
			nDivisor++;
		}
	}
}