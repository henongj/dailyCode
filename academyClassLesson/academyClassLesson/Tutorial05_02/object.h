#pragma once

#include<D3D11.h>
#include<D3DX11.h>
#include <xnamath.h>

class C_OBJECT
{
private:
	int m_nMeshId;

	XMMATRIX m_matWorld;

	XMVECTOR m_vLocation;
	XMVECTOR m_vRotation;
	XMVECTOR m_vScale;

public:
	C_OBJECT();
	void init(int nMeshId);
	void setPosition(float fX, float fY, float fZ);
	CXMMATRIX getMatrix();
	int getMeshId();
	void update();

	void* operator new(size_t size);
	void operator delete(void* p);
};