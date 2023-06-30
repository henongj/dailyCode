#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

#include"meshMGR.h"

class C_DIRECTX
{
private:
	C_MESHMGR m_MeshMgr;

private:
	static ID3D11Device* g_pd3dDevice;
	static ID3D11DeviceContext* g_pImmediateContext;
	
	IDXGISwapChain* g_pSwapChain;
	D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11RenderTargetView* g_pRenderTargetView;
	ID3D11Texture2D* g_pDepthStencil;
	ID3D11DepthStencilView* g_pDepthStencilView;
	ID3D11VertexShader* g_pVertexShader ;
	ID3D11PixelShader* g_pPixelShader;
	ID3D11InputLayout* g_pVertexLayout;
	ID3D11Buffer* g_pConstantBuffer;
	XMMATRIX                g_World1;
	XMMATRIX                g_World2;
	XMMATRIX                g_View;
	XMMATRIX                g_Projection;
	HWND					g_hWnd;
private:
	HRESULT CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);

public:
	static ID3D11Device* getDevice(void);
	static ID3D11DeviceContext* getDeviceContext(void);
	static HRESULT createBuffer(UINT size, D3D11_BIND_FLAG bindFlag, void* initData, ID3D11Buffer** ppBuffer);
	
public:
	C_DIRECTX();
	HRESULT InitDevice(HWND hWnd);
	void cleanupDevice(void);
	void render(void);

	void* operator new(size_t size);
	void operator delete(void* pDelete);

public:
	
};