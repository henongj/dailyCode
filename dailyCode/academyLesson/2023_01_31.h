#include<iostream>

namespace lecture_2023_01_31
{
	void fLoopReview(void)
	{
		int nInput{};
		int nData{};
		int nRemainder{};

		scanf_s("%d", &nInput);

		nData = 1;
		while (nData <= nInput)
		{
			nRemainder = nInput % nData;
			if (nRemainder == 0)
				printf("%d\n", nData);
			nData++;
		}
	}
	void fLoop(void)
	{
		int nInput{};
		int nData{};
		int nRemainder{};

		scanf_s("%d", &nInput);

		nData = 1;
		while (nData <= nInput)
		{
			nRemainder = nInput % nData;
			if (nRemainder == 0)
				printf("%d\n", nData);
			nData++;
		}

	}

	void fLoop2(void)
	{
		int nInput{};
		int nData1{};
		int nData2{};
		int nDivisor{};

		scanf_s("%d", &nData1);
		scanf_s("%d", &nData2);
		nDivisor = 1;

		while (nDivisor <= nData1 || nDivisor <= nData2)
		{
			if (nData1 % nDivisor == 0 && nData2 % nDivisor == 0)
				printf("%d\n", nDivisor);
			nDivisor++;
		}
	}

	void fFindCommonDivisor(void)
	{
		int nData1{};
		int nData2{};
		int nDivisor1{};

		scanf_s("%d", &nData1);
		scanf_s("%d", &nData2);
		nDivisor1 = 1;

		while (nDivisor1 <= nData1 || nDivisor1 <= nData2)
		{
			if (nData1 % nDivisor1 == 0 && nData2 % nDivisor1 == 0)
				printf("%d\n", nDivisor1);
			nDivisor1++;
		}
	}
}