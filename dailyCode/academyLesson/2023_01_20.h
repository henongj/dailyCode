#include<iostream>
namespace lecture_2023_01_20
{
	void getDividendAndDivisor(void)
	{
		int nDividend{};
		int nDivisor{};
		int nQuotient{};
		int nRemainder{};

		printf("���� �Է� : ");
		scanf_s("%d", &nDividend);
		printf("������ �Է� : ");
		scanf_s("%d", &nDivisor);

		nQuotient = nDividend / nDivisor;
		nRemainder = nDividend - (nDivisor * nQuotient);
		//nRemainder = nDividend % nDivisor;
		printf("�� : %d\n", nQuotient);
		printf("������ : %d\n", nRemainder);
	}

	void isOdd(void)
	{
		int nNumber{};
		int nRemainderOfTwo{};

		printf("���� �Է� : ");
		scanf_s("%d", &nNumber);

		nRemainderOfTwo = nNumber % 2;

		if (nRemainderOfTwo == 0)
			printf("¦��\n");
		if (nRemainderOfTwo == 1)
			printf("Ȧ��\n");
	}

	void operatePlusMinus(void)
	{
		int nData{};

		/* �̷��� ��������, ������ ����, �������� �����Ϸ����� �޶� Ȯ�������� �ʴ� */
		printf("%d\n", nData++);
		printf("%d\n", nData);
		printf("%d\n", ++nData);

		/* �̷��� ����, �������� */
		nData++;
		printf("%d\n", nData);
		nData++;

		/*�̰� �����Ϸ�, �Լ� ȣ�� �Ծึ�� �޶� �𸥴�, ������ ������ ��������*/
		int nData2{};
		printf("%d %d %d\n", ++nData2, ++nData2, ++nData2);
		int nData3{};
		printf("%d %d %d\n", nData3++, nData3++, nData3++);

		// ++nData++ �ϸ� �� �Ǵ� ������ �����ϱ�?
		// ������ �۾� �� ���� �ӽú����� const�� ������ �� �ȴ�
	}
}