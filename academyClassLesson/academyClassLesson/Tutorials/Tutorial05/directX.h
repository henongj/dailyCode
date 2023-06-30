#pragma once

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

class C_DirectX
{
private:
	struct SimpleVertex
	{
		XMFLOAT3 m_Pos;
		XMFLOAT4 m_Color;
	};

	struct ConstantBuffer
	{
		XMMATRIX m_World;
		XMMATRIX m_View;
		XMMATRIX m_Projection;
	};
private:
	
	
private:
	D3D_DRIVER_TYPE				m_driverType;
	D3D_FEATURE_LEVEL			m_featureLevel;
	ID3D11Device*				m_pd3dDevice;
	ID3D11DeviceContext*		m_pImmediateContext;
	IDXGISwapChain*				m_pSwapChain;
	ID3D11RenderTargetView*		m_pRenderTargetView;
	ID3D11Texture2D*			m_pDepthStencil;
	ID3D11DepthStencilView*		m_pDepthStencilView;
	ID3D11VertexShader*			m_pVertexShader;
	ID3D11PixelShader*			m_pPixelShader;
	ID3D11InputLayout*			m_pVertexLayout;
	ID3D11Buffer*				m_pVertexBuffer;
	ID3D11Buffer*				m_pIndexBuffer;
	ID3D11Buffer*				m_pConstantBuffer;
	XMMATRIX					m_World1;
	XMMATRIX					m_World2;
	XMMATRIX					m_View;
	XMMATRIX					m_Projection;


public:
	C_DirectX();
	~C_DirectX() = default;

	HRESULT C_DirectX::initDevice(HWND hWnd);
	HRESULT C_DirectX::compileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);

	void cleanUpDevice(void);
	void renderFrame(void);

	HRESULT createBufferVertex(SimpleVertex* vertices, UINT size, ID3D11Buffer** ppVertexBuffer);
	HRESULT createBufferIndex(WORD* indices, UINT size, ID3D11Buffer** ppIndexBuffer);
	HRESULT createBufferConstant(UINT size, ID3D11Buffer** ppConstantBuffer);
};