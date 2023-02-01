#include<iostream>

namespace academyLecture_2023_02_01
{
	void fGetFibonacchiNumberWithoutArray(void)
	{
		int nFibonacciNumber1{};
		int nFibonacciNumber2{};
		int nNthFibonacchiValue{};
		int nTargetNthFibonacchiNumber{};
		int nCount{};

		nFibonacciNumber1 = 0;
		nFibonacciNumber2 = 1;
		nTargetNthFibonacchiNumber = 15;

		nCount = 0;
		while (nCount < nTargetNthFibonacchiNumber)
		{
			nNthFibonacchiValue = nFibonacciNumber1 + nFibonacciNumber2;
			nFibonacciNumber1 = nFibonacciNumber2;
			nFibonacciNumber2 = nNthFibonacchiValue;
			printf("%d번째 피보나치 수 : %d\n", nCount, nNthFibonacchiValue);
			nCount++;
		}
	}

	void fDivideNumber(void)
	{
		int nInput{};
		int nDivisor{};
		int nRemainder{};
		int nQuotient{};
		int nNumberOfDigits{};

		printf("피제수(나눠질 수) : ");
		scanf_s("%d", &nInput);
		printf("제수 (나눌 값): ");
		scanf_s("%d", &nDivisor);
		nRemainder = nInput;

		nQuotient = nRemainder / nDivisor;
		nRemainder = nRemainder % nDivisor;
		printf("%d.", nQuotient);

		nNumberOfDigits = 0;
		while (nNumberOfDigits < 20)
		{
			while (nRemainder != 0 && nRemainder < nDivisor)
				nRemainder *= 10;

			nQuotient = nRemainder / nDivisor;
			nRemainder = nRemainder % nDivisor;

			printf("%d", nQuotient);
			nNumberOfDigits++;
		}
	}
	void fGetCommonDivisor(void)
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
				printf("공약수 %d\n", nDivisor);
			nDivisor++;
		}
	}
}