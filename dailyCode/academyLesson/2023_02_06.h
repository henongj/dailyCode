#include<iostream>


namespace academyLecture_2023_02_06
{
	void fArrBasic(void)
	{
		//�迭�� �̿��� �ݺ��� ����
		int arData[5]{ 13,23,44,55,778 };
		int nSumOfArr{};
		float fAverageOfArr{};

		for (int i = 0; i < 5; i++)
		{
			nSumOfArr += arData[i];
		}
		fAverageOfArr = (float)nSumOfArr / (float)5;

		printf("�迭�� �� : %d\n", nSumOfArr);
		printf("�迭�� ��� : %f ", fAverageOfArr);
	}
}