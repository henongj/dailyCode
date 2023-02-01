#include<iostream>

namespace academyLecture_2023_02_01
{
	void getCommonDivisor(void)
	{
		int nBigNumber{};
		int nSmallNumber{};
		int nNumberForSwap{};
		int nDivisor{};
		int nRemainder1{};
		int nRemainder2{};

		scanf_s("%d", &nBigNumber);
		scanf_s("%d", &nSmallNumber);

		if (nBigNumber < nSmallNumber)
		{
			nNumberForSwap = nBigNumber;
			nBigNumber = nSmallNumber;
			nSmallNumber = nNumberForSwap;
		}

		nDivisor = 1;
		while (nDivisor <= nSmallNumber)
		{
			nRemainder1 = nBigNumber % nDivisor;
			nRemainder2 = nSmallNumber % nDivisor;
			if (nRemainder1 == 0 && nRemainder2 == 0)
				printf("°ø¾à¼ö %d\n", nDivisor);
			nDivisor++;
		}
	}
}