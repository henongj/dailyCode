#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <xnamath.h>


class C_PS
{
private:
	ID3D11PixelShader* g_pPixelShader;

public:
	C_PS() = default;

	HRESULT loadPS();
	void setPS();
	void clear();
};