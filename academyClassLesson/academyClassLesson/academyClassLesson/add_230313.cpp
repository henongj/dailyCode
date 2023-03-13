#include"add_230313.h"

void C_ADD::setData(int nData1, int nData2)
{
	m_nData1 = nData1;
	m_nData2 = nData2;
}

void C_ADD::update()
{
	m_nSum = m_nData1 + m_nData2;
}

int C_ADD::getSum()
{
	return m_nSum;
}
