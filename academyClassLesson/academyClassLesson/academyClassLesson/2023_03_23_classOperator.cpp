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
	//�̰͵� ���� ���� ���� ���� �Ȱ��� ������ ��
	printf("Ŀ���� ���� ������\n");
	m_nData = cData.m_nData;
	return *this;
}
