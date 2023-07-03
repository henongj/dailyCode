#include "direct2D.h"

C_DIRECT2D* C_DIRECT2D::m_pAPI = nullptr;

void C_DIRECT2D::createDirect2D()
{
	if (m_pAPI == nullptr)
		m_pAPI = new C_DIRECT2D{};
}

void C_DIRECT2D::releaseDirect2D()
{
	if (m_pAPI)
	{
		delete m_pAPI;
		m_pAPI = nullptr;
	}
}

C_DIRECT2D* C_DIRECT2D::getDirect2D()
{
	return m_pAPI;
}

void C_DIRECT2D::init(void)
{
	//make single thread factory
	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pFactory);
	
}
