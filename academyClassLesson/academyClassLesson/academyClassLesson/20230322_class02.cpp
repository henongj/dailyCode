#include "20230322_class02.h"

void C20230322_class02::init(int* pData)
{
	m_pData = pData;
}

void C20230322_class02::setData(int nData)
{
	*m_pData = nData;
}

int C20230322_class02::getData()
{
	return *m_pData;
}
