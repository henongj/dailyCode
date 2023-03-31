#include<iostream>
#include "C20230331_PureVirtualFunctionTest.h"

C202303301_virtual::~C202303301_virtual()
{
	printf("부모 클래스 소멸자 호출\n");
}

void C202303301_virtual::printTest(void)
{
	printf("부모 클래스 abstract Function Print Test\n");
}

C202303301_test::~C202303301_test()
{
	printf("상속 받은 test 클래스 소멸자 호출\n");
}

void C202303301_test::printTest(void)
{
	C202303301_virtual::printTest();

	printf("상속 받은 test 클래스 Function Print Test\n");
}
