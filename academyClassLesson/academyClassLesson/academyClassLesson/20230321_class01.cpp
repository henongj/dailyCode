#include "20230321_class01.h"
#include<iostream>
/*
C20230321_01::C20230321_01(const C20230321_01& c20230321_01) : 
	m_nData{}
{
	printf("복사생성지\n");
}
*/
void C20230321_01::setData(int nData)
{
	m_nData = nData;
}

int C20230321_01::getData(void)
{
	return m_nData;
}

void printC20230321_01(C20230321_01 c20230321_01)
{
	
	printf("printC20230321_01\n");
	printf("c20230321_01.m_nData : %d\n", c20230321_01.getData());
}
