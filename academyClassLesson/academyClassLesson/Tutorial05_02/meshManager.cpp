
#include"meshMGR.h"

void C_MESHMGR::load(void)
{
	m_nBufferLength = 3;
	m_ppBuffer = new C_MESH * [m_nBufferLength] {};

	for(int i = 0 ; i <  3 ; i++)
	{
		m_ppBuffer[i] = new C_MESH{};
	}

	m_ppBuffer[0]->load("cube.txt");
	m_ppBuffer[1]->load("triangle.txt");
	m_ppBuffer[2]->load("quad.txt");
}

C_MESH* C_MESHMGR::getMesh(int nMeshIndex)
{
	if (m_nBufferLength <= nMeshIndex)
		return nullptr;
	
	return m_ppBuffer[nMeshIndex];
}

void C_MESHMGR::release(void)
{
	for (int i = 0; i < m_nBufferLength; i++)
	{
		m_ppBuffer[i]->release();
		delete m_ppBuffer[i];
	}

	delete[] m_ppBuffer;
}