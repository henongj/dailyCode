#include<iostream>
namespace lecture_2023_01_20
{
	void getDividendAndDivisor(void)
	{
		int nDividend{};
		int nDivisor{};
		int nQuotient{};
		int nRemainder{};

		printf("���� �Է� : ");
		scanf_s("%d", &nDividend);
		printf("������ �Է� : ");
		scanf_s("%d", &nDivisor);

		nQuotient = nDividend / nDivisor;
		nRemainder = nDividend - (nDivisor * nQuotient);
		//nRemainder = nDividend % nDivisor;
		printf("�� : %d\n", nQuotient);
		printf("������ : %d\n", nRemainder);
	}
}