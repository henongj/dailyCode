#include "meshMgr.h"

void C_MESHMGR::load()
{
    // ���Ϸκ��� ����� �о �����.
    m_nBufferLength = 3;
    m_ppBuffer = new C_MESH *[3] {};
    
    for (int i = 0; i < m_nBufferLength; i++)
    {
        m_ppBuffer[i] = new C_MESH{};
    }
    m_ppBuffer[0]->load("cube.dat");
    m_ppBuffer[1]->load("triangle.dat");
    m_ppBuffer[2]->load("zombie.dat");
}

C_MESH* C_MESHMGR::getMesh(int nMeshIndex)
{
    if (nMeshIndex >= m_nBufferLength)
        return nullptr;

    return m_ppBuffer[nMeshIndex];
}

void C_MESHMGR::clear()
{
    for (int i = 0; i < m_nBufferLength; i++)
    {
        m_ppBuffer[i]->release();
        delete m_ppBuffer[i];
    }
    delete[] m_ppBuffer;
}
