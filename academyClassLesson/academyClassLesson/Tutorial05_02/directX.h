#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "meshMgr.h"
#include "vs.h"
#include "ps.h"
#include"object.h"
#include<map>
#include<list>

class C_DXFUNC;

class C_DIRECTX
{
	friend C_DXFUNC;
private:
	D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	static ID3D11Device*			g_pd3dDevice;
	static ID3D11DeviceContext*	    g_pImmediateContext;
	IDXGISwapChain*			g_pSwapChain = NULL;
	ID3D11RenderTargetView* g_pRenderTargetView = NULL;
	ID3D11Texture2D*		g_pDepthStencil = NULL;
	ID3D11DepthStencilView* g_pDepthStencilView = NULL;
	XMMATRIX                g_World1;
	XMMATRIX                g_World2;
	XMMATRIX                g_View;
	XMMATRIX                g_Projection;
	HWND					g_hWnd;

	std::map<int, std::list<XMMATRIX*>> m_mapRenderObject{};

	C_MESHMGR				m_cMeshMgr;
	C_VS					m_cVs;
	C_PS					m_cPs;

	

public:
	C_DIRECTX();
	HRESULT InitDevice(HWND hWnd);
	void CleanupDevice();
	void Render();
	void* operator new(size_t size);
	void operator delete(void *p);

	void setRenderObject(int nRenderId, XMMATRIX* pMatrix);

};