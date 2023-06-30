#pragma once

#include"directX.h"

class C_MESH
{
private:
	struct SimpleVertex
	{
		XMFLOAT3 Pos;
		XMFLOAT4 Color;
	};
private:
	ID3D11Buffer* g_pVertexBuffer;
	ID3D11Buffer* g_pIndexBuffer;
	UINT m_strde;
	DXGI_FORMAT m_Indexformat;

public:
	C_MESH() = default;
	HRESULT load(const char* fileName);
	
	ID3D11Buffer* const* getVertexBuffer();
	ID3D11Buffer* getIndexBuffer() { return g_pIndexBuffer; }
	const UINT* getStride() { return &m_strde; }
	DXGI_FORMAT getIndexFormat() { return m_Indexformat; }

	void release(void);
};
