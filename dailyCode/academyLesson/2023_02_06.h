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

	void fInputArr(void)
	{
		/*
		Ư�� �������� Ư�� �������� �Է��� ����� �ִ´�
		�� Ư�� �������� Ư�� ��������, �Էµ� ���� ���� �����ǰ�, ������ �ڹٲ� �۵��ȴ�
		start���� end�� ������ ����� Ŀ����
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

			// do while�� bool ���� �ϳ� �� ��������� �ذ��� �ȴ�
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