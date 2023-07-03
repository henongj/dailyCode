#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

class C_DXFUNC
{
public:
	static ID3D11Device* getDevice();
	static ID3D11DeviceContext* getContext();
	static HRESULT createBuffer(UINT size, D3D11_BIND_FLAG bindFlag, void* initData, ID3D11Buffer** ppBuffer);
	static HRESULT CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
};
