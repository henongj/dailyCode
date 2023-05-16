#include "20230516_data.h"

void C20230516_DATA::setData(int nData)
{
	m_nData = nData;
}

int C20230516_DATA::getData()
{
	return m_nData;
}

void C20230516_DATA::printData()
{
	printf("m_nData: %d\n", m_nData);
}

void C20230516_DATA::testFunc()
{
	printf("test %d\n", m_nData * 2);
}
