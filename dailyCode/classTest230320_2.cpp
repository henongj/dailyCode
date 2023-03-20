#include "classTest230320_2.h"

classTest230320_2::classTest230320_2(int nData1, int nData2)
{
	m_classTest230320_1.setData(nData1, nData2);
}

classTest230320_1* classTest230320_2::getTestClass230320_1(void)
{
	return &m_classTest230320_1;
}

void classTest230320_2::setData(int nData1, int nData2)
{
	m_classTest230320_1.setData(nData1, nData2);
}

void classTest230320_2::printData(void)
{
	m_classTest230320_1.printData();
}
