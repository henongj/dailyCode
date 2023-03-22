#include "20230322_class01.h"

C_20230322_class01::C_20230322_class01() :
	m_pData{}
{
	m_pData = new int{};
}

C_20230322_class01::C_20230322_class01(const C_20230322_class01& cInput) :
	m_pData{}
{
	m_pData = new int{};
	*m_pData = *cInput.m_pData;
}

C_20230322_class01::~C_20230322_class01()
{
	delete m_pData;
	m_pData = nullptr;
}

void C_20230322_class01::setData(int nData)
{
	*m_pData = nData;
}

int C_20230322_class01::getData()
{
	return *m_pData;
}
