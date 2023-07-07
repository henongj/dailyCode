#pragma once

#include<D3D11.h>
#include<D3DX11.h>
#include <xnamath.h>

class C_MESH
{
private:
	struct SimpleVertex
	{
		XMFLOAT3 Pos;
		XMFLOAT4 Color;
	};
private:
	ID3D11Buffer* g_pVertexBuffer ;
	ID3D11Buffer* g_pIndexBuffer;
	UINT			m_iStride;
	DXGI_FORMAT		m_Indexformat;
	UINT			m_iIndexBufferSize;

public:
	C_MESH() = default;
	HRESULT load(const char *strFileName);

	ID3D11Buffer* const * getVertexBuffer();
	ID3D11Buffer* getIndexBuffer();
	const UINT* getStride();
	DXGI_FORMAT getIndexFormat();
	void release();
	UINT getIndexBufferSize();
};