#include<iostream>
#include "inheritanceConstructorCall.h"

C_PATRENT_20320329::C_PATRENT_20320329() :
	m_nData{}
{
	printf("Parent 호출\n");
}

C_PATRENT_20320329::~C_PATRENT_20320329()
{
	printf(" parent 소멸자 호출 \n");
}

C_CHILD_20320329::C_CHILD_20320329()
{
	printf("Child 호출\n");
}

C_CHILD_20320329::~C_CHILD_20320329()
{
	printf(" child 소멸자 호출 \n");
}
