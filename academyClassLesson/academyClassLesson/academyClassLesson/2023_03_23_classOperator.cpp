#include <iostream>
#include "2023_03_23_classOperator.h"
void C20230323ClassOperator::setData(int nData)
{
	m_nData = nData;
}

void C20230323ClassOperator::printData(void)
{
	printf("m_nData = %d\n", m_nData);
}

C20230323ClassOperator& C20230323ClassOperator::operator+(int nData)
{
	m_nData += nData;

	return *this;
}

C20230323ClassOperator& C20230323ClassOperator::operator=(int nData)
{
	m_nData = nData;

	return *this;
}

C20230323ClassOperator& C20230323ClassOperator::operator=(C20230323ClassOperator& cData)
{
	//이것도 얕은 복사 깊은 복사 똑같이 따져야 해
	printf("커스텀 대입 연산자\n");
	m_nData = cData.m_nData;
	return *this;
}
