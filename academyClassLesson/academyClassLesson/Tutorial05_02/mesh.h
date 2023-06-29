#pragma once

#include<D3D11.h>
#include<D3DX11.h>

class C_MESH
{
private:
	ID3D11Buffer* g_pVertexBuffer;
	ID3D11Buffer* g_pIndexBuffer;

public:
	C_MESH() = default;
	void load(void);
};
