#include<iostream>
#include "C20230331_PureVirtualFunctionTest.h"

C202303301_virtual::~C202303301_virtual()
{
	printf("�θ� Ŭ���� �Ҹ��� ȣ��\n");
}

void C202303301_virtual::printTest(void)
{
	printf("�θ� Ŭ���� abstract Function Print Test\n");
}

C202303301_test::~C202303301_test()
{
	printf("��� ���� test Ŭ���� �Ҹ��� ȣ��\n");
}

void C202303301_test::printTest(void)
{
	C202303301_virtual::printTest();

	printf("��� ���� test Ŭ���� Function Print Test\n");
}
