#include "20230324_operator.h"

void C20230324_C_DATA::setData(int nIndex, int nData)
{
	m_arData[nIndex] = nData;
}

int& C20230324_C_DATA::operator[](int nIndex)
{
	return m_arData[nIndex];
}

C20230324_C_DATA_02::C20230324_C_DATA_02(int nData)
{
	m_nData = nData;
}

void C20230324_C_DATA_02::setData(int nData)
{
	m_nData = nData;
}

int C20230324_C_DATA_02::getData()
{
	return m_nData;
}

C20230324_C_DATA_02& C20230324_C_DATA_02::operator++()
{
	m_nData++;
	return *this;
}
/*
const C20230324_C_DATA_02& C20230324_C_DATA_02::operator++(int)
{
	printf("»ƒ¡ı∞°\n");
	
	int nBackup = m_nData;
	m_nData++;
	
	return C20230324_C_DATA_02(nBackup);
}
*/