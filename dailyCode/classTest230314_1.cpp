#include "classTest230314_1.h"

classTest230314_1::classTest230314_1(int nTestData)
{
	setTestData(nTestData);
}

classTest230314_0* classTest230314_1::getTestData(void)
{
	return &m_cClassTest230314_0;
}

void classTest230314_1::setTestData(int nTestData)
{
	m_cClassTest230314_0.setTestData(nTestData);
}
