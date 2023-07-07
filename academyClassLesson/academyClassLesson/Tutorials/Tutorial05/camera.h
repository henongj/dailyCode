#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <xnamath.h>

class C_CAMERA
{
private:
	float m_fYaw;
	float m_fPitch;
	float m_fRoll;

	XMMATRIX m_matView;
	XMMATRIX m_matRotation;
	XMVECTOR m_vLocation;


public:
	C_CAMERA();
	void setLocation(CXMVECTOR vLocation);
	void moveFoward(float fSpeed);
	void moveBackward(float fSpeed);
	void addRotationYaw(float fDegree);
	void update();
	CXMMATRIX getMatView();
};