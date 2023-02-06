#include<iostream>


namespace academyLecture_2023_02_06
{
	void fArrBasic(void)
	{
		//배열을 이용한 반복문 예제
		int arData[5]{ 13,23,44,55,778 };
		int nSumOfArr{};
		float fAverageOfArr{};

		for (int i = 0; i < 5; i++)
		{
			nSumOfArr += arData[i];
		}
		fAverageOfArr = (float)nSumOfArr / (float)5;

		printf("배열의 합 : %d\n", nSumOfArr);
		printf("배열의 평균 : %f ", fAverageOfArr);
	}
}