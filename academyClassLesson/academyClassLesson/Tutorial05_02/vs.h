#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <xnamath.h>

class C_VS
{
private:
	struct ConstantBuffer
	{
		XMMATRIX mWorld;
		XMMATRIX mView;
		XMMATRIX mProjection;
	};

private:
	ID3D11VertexShader* g_pVertexShader ;
	ID3D11PixelShader* g_pPixelShader ;
	ID3D11InputLayout* g_pVertexLayout;
	ID3D11Buffer* g_pConstantBuffer ;

public:
	C_VS() = default;
	HRESULT loadVS();
	void setVS();
	void updateConstBuffer(XMMATRIX matW, XMMATRIX matV, XMMATRIX matP);
	void clear();

};
