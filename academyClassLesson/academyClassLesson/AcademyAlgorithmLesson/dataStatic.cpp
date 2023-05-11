#include "20230511_dataStatic.h"

int C20230511_DATA::m_nDataStatic = 0;

void C20230511_DATA::setDataClass(int nData)
{
	m_nDataClass = nData;
}

int C20230511_DATA::getDataClass()
{
	return m_nDataClass;
}

void C20230511_DATA::setDataStatic(int nData)
{
	m_nDataStatic = nData;
}

int C20230511_DATA::getDataStatic()
{
	return m_nDataStatic;
}

