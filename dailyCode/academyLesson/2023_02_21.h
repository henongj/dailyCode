#pragma once
#include<iostream>


namespace academyLecture_2023_02_21
{

	int func();
	int add(int nData1, int nData2);

	int mainFunc(void)
	{
		// ���ϵǴ� ���� ������� �ʾƵ� �ȴ�
		func();

		int nData0{};

		nData0 = func();
		printf("%d\n", nData0);


		int nData1{};
		int nData2{};
		int nTotal1{};
		int nTotal2{};

		nTotal1 = add(10, 20);
		nTotal2 = add(add(23, 1), (add(20, 5)));
		printf("%d\n", nTotal1);
		printf("%d\n", nTotal2);


		// �̰� �� 10�� ��Ų�Ű�
		for (int i = 0; i < 10; i++)
			printf("%d", add(10, 20));

		// �̰� �� 1�� �� ��
		int nTotal3{};
		nTotal3 = add(10, 20);
		// 10�� �����ذž� �̰� �ξ� ����
		for (int i = 0; i < 10; i++)
			printf("%d", nTotal3);

	}

	int func()
	{
		return 120;
	}

	int add(int nData1, int nData2)
	{
		int nTotal{};

		nTotal = nData1 + nData2;
		return nTotal;
	}



	void divide(int nDst, int nSrc, int* pQuotient);

	int mainFunc2(void)
	{
		bool bTest{};
		int nData1{};
		int nData2{};
		int nResult{};

		scanf_s("%d", &nData1);
		scanf_s("%d", &nData2);

		divide(nData1, nData2, &nResult);

		printf("%d\n", nResult);
	}

	void divide(int nDst, int nSrc, int* pQuotient)
	{
		*pQuotient = nDst / nSrc;
	}
}