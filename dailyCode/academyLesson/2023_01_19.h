#include<iostream>
namespace lecture_2023_01_19
{
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
	
}