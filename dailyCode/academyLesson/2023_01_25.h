#include<iostream>
namespace lecture_2023_01_25
{
	void fGetSmallestNumberOfIntegers(void)
	{
		int nNumber1{};
		int nNumber2{};
		int nNumber3{};
		int nNumber4{};
		int nSmallestNumber{};

		scanf_s("%d", &nNumber1);
		scanf_s("%d", &nNumber2);
		scanf_s("%d", &nNumber3);
		scanf_s("%d", &nNumber4);

		nSmallestNumber = nNumber1;

		if (nNumber2 < nSmallestNumber)
			nSmallestNumber = nNumber2;
		if (nNumber3 < nSmallestNumber)
			nSmallestNumber = nNumber3;
		if (nNumber4 < nSmallestNumber)
			nSmallestNumber = nNumber4;

		printf("���� ���� �� : %d", nSmallestNumber);
	}

	void testAndOr(void)
	{
		int nData1{};
		int nData2{};
		int nData3{};

		nData1 = 10;
		nData2 = 15;
		nData3 = 7;

		if (nData2 > 0 && nData1 > 0)
			printf("�� �� ���\n");

		if (nData1 < 20 && nData1 < 0)
			printf("��");

		if (nData3 == 0 || nData3 & 1)
			printf("���ڰ� 0�̰ų� Ȧ��");

	}
}