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

	void fIsPrimeNumber(void)
	{
		int nInput{};
		int nNumOfDivisor = 0;
		int nDivisor2{};
		
		scanf_s("%d", &nInput);

		nDivisor2 = 1;
		while (nDivisor2 <= nInput)
		{
			if (nInput % nDivisor2 == 0)
				nNumOfDivisor++;

			nDivisor2++;
		}
		if (nNumOfDivisor == 2)
			printf("Prime Number\n");
		else
			printf("Not Prime Number\n");
	}

	void fIsPrimeNumber2(void)
	{
		int nInput{};
		int rootOfInput{};
		int nNumOfDivisor{};
		int divisor{};

		scanf_s("%d", &nInput);
		rootOfInput = (int)sqrt((double)nInput);

		divisor = 2;
		while (nNumOfDivisor < 1 && divisor <= rootOfInput)
		{
			if (nInput % divisor == 0)
				nNumOfDivisor++;

			divisor++;
		}

		if (nNumOfDivisor == 0)
			printf("소수입니다.\n");
		else
			printf("소수가 아닙니다.\n");

	}
}