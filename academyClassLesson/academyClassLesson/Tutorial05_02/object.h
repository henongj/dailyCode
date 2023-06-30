#pragma once


#include<D3D11.h>
#include<D3DX11.h>
#include<xnamath.h>

class C_OBJECT
{
private:
	int m_nMeshId;
	
	XMVECTOR m_vLocation;
	XMVECTOR m_vRotation;
	XMVECTOR m_vSclae;

	XMMATRIX m_matWorld;

public:
	C_OBJECT();
	~C_OBJECT() = default;

	void init(int nMeshId);
	void setPosition(float fX, float fY, float fZ);
	CXMMATRIX getWorldMatrix(void);
	int getMeshId();
	void update();
	void release();
};