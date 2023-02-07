#include<iostream>

namespace academyLecture_2023_02_07
{
	void fArrayBasic(void)
	{
		// 데이터에는 중복이 없다
		int arData[10]{ 23,88,51,123,91,9999,220,1346,349,10 };
		int nIndexContainingSmallestValue{};
		int nSmallestValueInArray{};

		nIndexContainingSmallestValue = arData[0];
		for (int i = 1; i < 10; i++)
		{
			if (arData[i] < nIndexContainingSmallestValue)
				nIndexContainingSmallestValue = i;
		}
		nSmallestValueInArray = arData[nIndexContainingSmallestValue];

		printf("배열 안에서 가장 작은 숫자 : %d\n", nSmallestValueInArray);

		// 문제가 되는 경우
		int arData2[]{ 1,2,3,4,5 }; // 어차피 네가 샌다 
		// 문제가 되는 경우2
		int nData{};
		printf("%zd\n", sizeof(nData));
		
	}
	void fSizeOfFunction(void)
	{
		// 잘못 사용하면 문제가 생긴다
		int nData[7]{ 1,2,3,4,5,6,7 };
		printf("%zd\n", sizeof(nData));
		printf("%zd\n", sizeof(int[7]));

		for (int i = 0; i < sizeof(nData) / sizeof(int); i++)
		{
			printf("%d ", nData[i]);
		}
	}
}