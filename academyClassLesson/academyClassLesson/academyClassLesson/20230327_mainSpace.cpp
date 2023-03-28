#include<iostream>

#include"20230327_child01.h"
#include"20230327_parent02.h"

int mainSpace_20230327_01(void)
{
	C20230327_CHILD01 cChild01{};
	cChild01.printParent01();
	return 0;
}

int mainSpace_20230327_02(void)
{
	C20230327_CHILD02 cChild02{};
	C20230327_CHILD03 cChild03{};
	C20230327_CHILD04 cChild04{};

	// 부모 클래스의 포인터로 자식을 가리킬 수 있다.
	C20230327_PARENT02* pChild02 = &cChild02;

	pChild02->printParent02();

	return 0;
}

