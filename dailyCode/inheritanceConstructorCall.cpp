#include<iostream>
#include "inheritanceConstructorCall.h"

C_PATRENT_20320329::C_PATRENT_20320329() :
	m_nData{}
{
	printf("Parent ȣ��\n");
}

C_PATRENT_20320329::~C_PATRENT_20320329()
{
	printf(" parent �Ҹ��� ȣ�� \n");
}

C_CHILD_20320329::C_CHILD_20320329()
{
	printf("Child ȣ��\n");
}

C_CHILD_20320329::~C_CHILD_20320329()
{
	printf(" child �Ҹ��� ȣ�� \n");
}
