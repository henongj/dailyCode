#include "object.h"

C_OBJECT::C_OBJECT() :
    m_nMeshId{}
{
    XMFLOAT3 f3Location(0.0f,0.0f,0.0f);
    m_vLocation = XMLoadFloat3(&f3Location);

    XMFLOAT3 f3Scale(1.0f, 1.0f, 1.0f);
    m_vScale  = XMLoadFloat3(&f3Scale);

    XMFLOAT3 f3Rotation(0.0f, 0.0f, 0.0f);
    m_vRotation= XMLoadFloat3(&f3Rotation);

    m_matWorld = XMMatrixIdentity();
}

void C_OBJECT::init(int nMeshId)
{
   m_nMeshId = nMeshId;
}

void C_OBJECT::setPosition(float fX, float fY, float fZ)
{
    XMFLOAT3 f3Position(fX, fY, fZ);
    m_vLocation = XMLoadFloat3(&f3Position);
}

CXMMATRIX C_OBJECT::getMatrix()
{
    return m_matWorld;
}

int C_OBJECT::getMeshId()
{
    return m_nMeshId;
}

void C_OBJECT::update()
{
    m_matWorld = XMMatrixScalingFromVector(m_vScale)* XMMatrixRotationRollPitchYawFromVector(m_vRotation);
    m_matWorld._41 = m_vLocation.m128_f32[0];
    m_matWorld._42 = m_vLocation.m128_f32[1];
    m_matWorld._43 = m_vLocation.m128_f32[2];
}

void* C_OBJECT::operator new(size_t size)
{
    return _aligned_malloc(size, 16);
}

void C_OBJECT::operator delete(void* p)
{
    _aligned_free(p);
}
