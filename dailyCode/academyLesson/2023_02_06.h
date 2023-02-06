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

	void fInputArr(void)
	{
		/*
		특정 번지부터 특정 번지까지 입력한 배수를 넣는다
		단 특정 번지부터 특정 번지까지, 입력된 값에 따라 결정되고, 순서가 뒤바뀌어도 작동된다
		start에서 end로 갈수록 배수가 커진다
	*/
		int arData[10]{};
		int nMultipleValue{};
		int nStartIndex{};
		int nEndIndex{};
		int nIncrementValue{};
		int nInputValue{};
		bool bBreaker{};

		scanf_s("%d", &nMultipleValue);
		scanf_s("%d", &nStartIndex);
		scanf_s("%d", &nEndIndex);
		nInputValue = nMultipleValue;

		nIncrementValue = 1;
		if (nStartIndex > nEndIndex)
			nIncrementValue = -1;
		for (int i = nStartIndex; bBreaker != true; i += nIncrementValue)
		{
			arData[i] = nInputValue;
			nInputValue += nMultipleValue;

			// do while은 bool 변수 하나 더 집어넣으면 해결이 된다
			if (i == nEndIndex)
				bBreaker = true;
		}

		/*
		for (int i = nStartIndex; bBreaker != true ; i += nIncrementValue)
		{
			arData[i] = nInputValue;
			nInputValue += nMultipleValue;
		}
		arData[nEndIndex] = nInputValue;
		*/

		/*
		while (nStartIndex != nEndIndex)
		{
			arData[nStartIndex] = nInputValue;
			nInputValue += nMultipleNumber;

			nStartIndex += nIncrementValue;
		}
		arData[nEndIndex] = nInputValue;
		do
		{
			arData[nStartIndex] = nInputValue;
			nInputValue += nMultipleNumber;

			nStartIndex += nIncrementValue;
		}
		while (nStartIndex != nEndIndex);
		*/
		for (int i = 0; i < 10; i++)
			printf("%d ", arData[i]);
		printf("\n");
	}
}