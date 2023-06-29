#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

class C_DIRECTX
{
private:
	struct SimpleVertex
	{
		XMFLOAT3 Pos;
		XMFLOAT4 Color;
	};

	struct ConstantBuffer
	{
		XMMATRIX mWorld;
		XMMATRIX mView;
		XMMATRIX mProjection;
	};

private:
	D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device* g_pd3dDevice = NULL;
	ID3D11DeviceContext* g_pImmediateContext = NULL;
	IDXGISwapChain* g_pSwapChain = NULL;
	ID3D11RenderTargetView* g_pRenderTargetView = NULL;
	ID3D11Texture2D* g_pDepthStencil = NULL;
	ID3D11DepthStencilView* g_pDepthStencilView = NULL;
	ID3D11VertexShader* g_pVertexShader = NULL;
	ID3D11PixelShader* g_pPixelShader = NULL;
	ID3D11InputLayout* g_pVertexLayout = NULL;
	ID3D11Buffer* g_pVertexBuffer = NULL;
	ID3D11Buffer* g_pIndexBuffer = NULL;
	ID3D11Buffer* g_pConstantBuffer = NULL;
	XMMATRIX                g_World1;
	XMMATRIX                g_World2;
	XMMATRIX                g_View;
	XMMATRIX                g_Projection;
	HWND					g_hWnd;

private:
	HRESULT CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);

public:
	C_DIRECTX();
	HRESULT InitDevice(HWND hWnd);
	void cleanupDevice(void);
	void render(void);
};