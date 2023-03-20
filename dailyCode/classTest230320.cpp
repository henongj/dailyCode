#include "classTest230320.h"


classTest230320_1::classTest230320_1(int nData1, int nData2)
{
	m_nData = nData1;
	m_nData2 = nData2;

	printf("constructor 2parameter called\n");
}

void classTest230320_1::setData(int nData, int nData2)
{
	m_nData = nData;
	m_nData2 = nData2;
}

void classTest230320_1::printData(void)
{
	printf("m_nData: %d, m_nData2: %d\n", m_nData, m_nData2);
}


