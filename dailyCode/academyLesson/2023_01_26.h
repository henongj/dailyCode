#include<iostream>
namespace lecture_2023_01_25
{
	void fBasicConditionState(void)
	{
		int nData{};

		scanf_s("%d", &nData);

		if (nData > 50)
			printf("50보다 크다\n");
		else if (nData > 30)
			printf("20보다 크다\n");
		else
			printf("나머지\n");
	}

	void fIsOddOrEvenOrZero(void)
	{
		int nData{};
		int nQuotient{};
		int nRemainder{};

		scanf_s("%d", &nData);

		nQuotient = nData / 2;
		nRemainder = nData & 1;


		if (nRemainder == 0)
		{
			if (nQuotient == 0)
				printf("홀짝 판별 안 됨\n");
			if (nQuotient != 0)
				printf("짝수임\n");
		}
		if (nRemainder != 0)
			printf("홀수임\n");


	}

	void fIfElse(void)
	{
		int nNumber{};

		scanf_s("%d", &nNumber);

		if (nNumber < 60)
			printf("F\n");
		else if (nNumber < 70)
			printf("D\n");
		else if (nNumber < 80)
			printf("C\n");
		else if (nNumber < 90)
			printf("B\n");
		else if (nNumber <= 100)
			printf("A\n");

	}
	
}