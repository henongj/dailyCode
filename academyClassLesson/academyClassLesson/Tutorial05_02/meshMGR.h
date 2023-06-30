#pragma once


#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "mesh.h"

class C_MESHMGR
{
private:
	C_MESH** m_ppBuffer;
	int m_nBufferLength;

public:
	C_MESHMGR() = default;
	~C_MESHMGR() = default;

	void load(void);
	C_MESH* getMesh(int nMeshIndex);
	void release(void);
};
