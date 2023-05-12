#include "20230512_Data.h"


C20230512_DATA* C20230512_DATA::m_pInstance = nullptr;

void C20230512_DATA::setData(int nData)
{
	m_nData = nData;
}

int C20230512_DATA::getData()
{
	return m_nData;
}

void C20230512_DATA::init(int nData)
{
	setData(nData);
}

void C20230512_DATA::createInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance = new C20230512_DATA{};
}

C20230512_DATA* C20230512_DATA::getInstance()
{	
	return m_pInstance;
}

void C20230512_DATA::releaseInstance()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
