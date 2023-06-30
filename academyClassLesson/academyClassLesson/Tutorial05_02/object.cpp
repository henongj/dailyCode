#include"object.h"

C_OBJECT::C_OBJECT() :
	m_nMeshId{}
{
	XMFLOAT3 f3Location = XMFLOAT3(0.0f, 0.0f, 0.0f);
	XMFLOAT3 f3Rotation = XMFLOAT3(0.0f, 0.0f, 0.0f);
	XMFLOAT3 f3Scale = XMFLOAT3(1.0f, 1.0f, 1.0f);

	m_vLocation = XMLoadFloat3(&f3Location);
	m_vRotation = XMLoadFloat3(&f3Rotation);
	m_vSclae = XMLoadFloat3(&f3Scale);
	
}

void C_OBJECT::init(int nMeshId)
{
	
}

void C_OBJECT::setPosition(float fX, float fY, float fZ)
{
	XMFLOAT3 f3Position(fX, fY, fZ);
	m_vLocation = XMLoadFloat3(&f3Position);
}

CXMMATRIX C_OBJECT::getWorldMatrix(void)
{
	return m_matWorld;
}

int C_OBJECT::getMeshId()
{
	return m_nMeshId;
}

void C_OBJECT::update()
{
	m_matWorld = XMMatrixScalingFromVector(m_vSclae) * XMMatrixRotationRollPitchYawFromVector(m_vRotation) * XMMatrixTranslationFromVector(m_vLocation);
	
}

void C_OBJECT::release()
{

}

