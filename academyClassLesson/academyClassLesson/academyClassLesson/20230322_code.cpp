#include<iostream>

#include"20230322_class01.h"

#include"20230322_class02.h"

void _callByValueFunc(C_20230322_class01 c20230322_class01);
void _callByValueFunc02(C20230322_class02 c20230322_class02);

int _20230322mainSpace_01(void)
{
	C_20230322_class01 c20230322_class01{};

	c20230322_class01.setData(100);
	printf("%d\n", c20230322_class01.getData());

	//���� ����� ������ ��? �Լ��� �θ��� �����鼭 �Ҹ��ڰ� ȣ��ǰ�, main�� �����鼭 �� delete�ϱ� ������
	_callByValueFunc(c20230322_class01);

	return 0;
}

void _20230322mainSpace_02(void)
{
	int* pMain{};
	pMain = new int{};
	*pMain = 100;

	C20230322_class02 c20230322_class02{};
	c20230322_class02.init(pMain);

	c20230322_class02.setData(200);

	printf("%d\n", c20230322_class02.getData());
	printf("%d\n", *pMain);
	//�̷��� �� �ȴ�. �ֳĸ� ������ �޸𸮸� �ܺ� �Լ��� �����ϴ� ���̴�.
	_callByValueFunc02(c20230322_class02);

	delete pMain;

}

void _callByValueFunc(C_20230322_class01 c20230322_class01)
{
	printf("%d\n", c20230322_class01.getData());
}
void _callByValueFunc02(C20230322_class02 c20230322_class02)
{
	printf("%d\n", c20230322_class02.getData());
}
