#include "camera.h"

C_CAMERA::C_CAMERA() :
	m_fPitch{},
	m_fRoll{},
	m_fYaw{},
	m_vLocation{},
	m_matView{}
{
	m_matView = XMMatrixIdentity();
	m_matRotation = XMMatrixIdentity();
}

void C_CAMERA::setLocation(CXMVECTOR vLocation)
{
	m_vLocation = vLocation;
}

void C_CAMERA::moveFoward(float fSpeed)
{
	XMVECTOR vZ{};
	vZ.m128_f32[0] = 0.0f;
	vZ.m128_f32[1] = 0.0f;
	vZ.m128_f32[2] = 1.0f;

	vZ = XMVector3TransformCoord(vZ, m_matRotation);
	m_vLocation += vZ * fSpeed;
}

void C_CAMERA::moveBackward(float fSpeed)
{
	moveFoward(-fSpeed);
}

void C_CAMERA::addRotationYaw(float fDegree)
{
//	m_fYaw += XMConvertToRadians(fDegree);
	m_fYaw += fDegree * (XM_PI / 180.0f);
	m_fYaw -= (float)(int)(m_fYaw / XM_2PI) * XM_2PI;
}

void C_CAMERA::update()
{
	m_matRotation = XMMatrixRotationRollPitchYaw(m_fPitch, m_fYaw, m_fRoll);

	XMMATRIX matCamera = m_matRotation;
	matCamera._41 = m_vLocation.m128_f32[0];
	matCamera._42 = m_vLocation.m128_f32[1];
	matCamera._43 = m_vLocation.m128_f32[2];
	
	XMVECTOR vDet{};
	m_matView = XMMatrixInverse(&vDet, matCamera);
	//m_matView = matCamera;
}

CXMMATRIX C_CAMERA::getMatView()
{
	return m_matView;
}
