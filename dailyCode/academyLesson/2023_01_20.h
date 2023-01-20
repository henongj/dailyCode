#include<iostream>
namespace lecture_2023_01_20
{
	void getDividendAndDivisor(void)
	{
		int nDividend{};
		int nDivisor{};
		int nQuotient{};
		int nRemainder{};

		printf("제수 입력 : ");
		scanf_s("%d", &nDividend);
		printf("피제수 입력 : ");
		scanf_s("%d", &nDivisor);

		nQuotient = nDividend / nDivisor;
		nRemainder = nDividend - (nDivisor * nQuotient);
		//nRemainder = nDividend % nDivisor;
		printf("몫 : %d\n", nQuotient);
		printf("나머지 : %d\n", nRemainder);
	}
}