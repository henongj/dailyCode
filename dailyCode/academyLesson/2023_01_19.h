#include<iostream>
namespace lecture_2023_01_19
{
	//캐스팅 재확인
	// 조건문
	void remind(void)
	{
		int nDestination{};
		int nSource{};
		float fResult{};

		nDestination = 100;
		nSource = 7;

		fResult = (float)nDestination / (float)nSource;

		printf("fResult = %f\n", fResult);
		cin >> nSource;
	}
	
	void remind2(void)
	{
		int nCircleRadius{};
		float fCircleRound{};
		float fCircleArea{};
		const float fPi{ 3.14f };

		printf_s("input radius: ");
		scanf_s("%d", &nCircleRadius);

		fCircleArea = (float)nCircleRadius * (float)nCircleRadius * fPi;
		fCircleRound = (float)nCircleRadius * 2.0f * fPi;

		printf_s("fCircleArea = %f\n", fCircleArea);
		printf_s("fCircleRound = %f\n", fCircleRound);

	}
	
	void conditionTest(void)
	{
		int nData{};

		scanf_s("%d", &nData);

		if (nData % 2 != 0)
		{
			printf("홀수임 \n");
		}

		if (nData % 2 == 0)
		{
			printf("짝수임 \n");
		}

		if (0 < nData)
		{
			printf("양수임 \n");
		}

		if (nData < 0)
		{
			printf("음수임 \n");
		}

		if (10 <= nData)
		{
			printf("두 자리 이상인 수임 \n");
		}

		if (nData <= 999)
		{
			printf("1000보다 작네\n");
		}


	}
	void conditionTest2(void)
	{
		int nData1{};
		scanf_s("%d", &nData1);

		if (nData1 == 100)
		{
			printf("참\n");
		}
		if (nData1 == 0)
		{
			printf("nData1 = 0하면 nData1이 0이 되서 무조건 거짓임\n");
		}
	}
}