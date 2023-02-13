#include<iostream>

namespace academyLecture_2023_02_13
{
	void fBasicPointer(void)
	{
		int nData{};
		int* p{};

		nData = 120;
		p = &nData;
		// p �� ���
		// *p �� nData�� ��
		// &p�� p�� �ּ�

		// *p�� ����?
		printf("%d\n", *p);

		// *p�� �ּҸ� ����ϰ� �ʹٸ�?
		printf("%p\n", &(*p));
		// nData�� �ּҸ� ����ϰ� �ʹٸ�?
		printf("%p\n", &nData);

		{
			int nTemp{};
			nTemp = 100;
			p = &nTemp;
		}
		// p�� nTemp�� �ּҸ� ����Ű�� �ִ�.
		// �̰� �����Ŵ�. �׷��� ���ư���.
		printf("%d\n", *p);

		p = nullptr;

		int* p1{};
		int* p2{};
		// ���� ���� �����ϴ� ������
		p1 = p2 = new int{};

		*p1 = 100;
		// �׾���� �޸�
		delete p2;

		// �ٽ� ����
		*p1 = 9;

		// ���� �޸� ���. ������ ���.
		printf("%d\n", *p1);
		
		int* p3{};

		p1 = &nData;
		p2 = &nData;
		p3 = &nData;

		*p1 = 9;

		printf("%d\n", *p3);
		
	}
}