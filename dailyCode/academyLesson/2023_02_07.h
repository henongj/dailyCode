#include<iostream>

namespace academyLecture_2023_02_07
{
	void fArrayBasic(void)
	{
		// �����Ϳ��� �ߺ��� ����
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

		printf("�迭 �ȿ��� ���� ���� ���� : %d\n", nSmallestValueInArray);

		// ������ �Ǵ� ���
		int arData2[]{ 1,2,3,4,5 }; // ������ �װ� ���� 
		// ������ �Ǵ� ���2
		int nData{};
		printf("%zd\n", sizeof(nData));
		
	}
	void fSizeOfFunction(void)
	{
		// �߸� ����ϸ� ������ �����
		int nData[7]{ 1,2,3,4,5,6,7 };
		printf("%zd\n", sizeof(nData));
		printf("%zd\n", sizeof(int[7]));

		for (int i = 0; i < sizeof(nData) / sizeof(int); i++)
		{
			printf("%d ", nData[i]);
		}
	}
}