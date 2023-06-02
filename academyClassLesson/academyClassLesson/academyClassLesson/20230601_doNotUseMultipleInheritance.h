#pragma once

#include<iostream>
#include<set>
class C20230601_PA
{
public:
	void pA(void)
	{
		std::cout << "C20230601_PA::pA �Լ�ȣ��" << std::endl;
	}
};

class C20230601_PB
{
public:
	void pB(void)
	{
		std::cout << "C20230601_PB::pB �Լ�ȣ��" << std::endl;
	}
};

class C20230601_P_CHILD : public C20230601_PA, public C20230601_PB
{
public:
	void pChild(void)
	{
		std::cout << "C20230601_P_CHILD::pChild �Լ�ȣ��" << std::endl;
	}
};




int mainSpace01_20230601(void)
{
	C20230601_P_CHILD pChild{};

	pChild.pA();
	pChild.pB();
	pChild.pChild();

	C20230601_PA* pa = &pChild;
	C20230601_PB* pb = &pChild;

	return 0;
}