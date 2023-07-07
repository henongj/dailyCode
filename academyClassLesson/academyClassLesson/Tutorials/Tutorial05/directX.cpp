#include "directX.h"

ID3D11Device* C_DIRECTX::g_pd3dDevice = nullptr;
ID3D11DeviceContext* C_DIRECTX::g_pImmediateContext = nullptr;

C_DIRECTX::C_DIRECTX() :
	g_driverType{},
	g_featureLevel{},
	g_pSwapChain{},
	g_pRenderTargetView{},
	g_pDepthStencil{},
	g_pDepthStencilView{},
	g_View{},
	g_Projection{},
    g_hWnd{}
{
	g_driverType = D3D_DRIVER_TYPE_NULL;
	g_featureLevel = D3D_FEATURE_LEVEL_11_0;

	g_View = XMMatrixIdentity();
	g_Projection = XMMatrixIdentity();
}

HRESULT C_DIRECTX::InitDevice(HWND hWnd)
{
    g_hWnd = hWnd;

    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect(g_hWnd, &rc);
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };
    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    UINT numFeatureLevels = ARRAYSIZE(featureLevels);

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = g_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
        g_driverType = driverTypes[driverTypeIndex];
        hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
            D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &g_featureLevel, &g_pImmediateContext);
        if (SUCCEEDED(hr))
            break;
    }
    if (FAILED(hr))
        return hr;

    // Create a render target view
    ID3D11Texture2D* pBackBuffer = NULL;
    hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if (FAILED(hr))
        return hr;

    hr = g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_pRenderTargetView);
    pBackBuffer->Release();
    if (FAILED(hr))
        return hr;

    // Create depth stencil texture
    D3D11_TEXTURE2D_DESC descDepth;
    ZeroMemory(&descDepth, sizeof(descDepth));
    descDepth.Width = width;
    descDepth.Height = height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;
    hr = g_pd3dDevice->CreateTexture2D(&descDepth, NULL, &g_pDepthStencil);
    if (FAILED(hr))
        return hr;

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory(&descDSV, sizeof(descDSV));
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = g_pd3dDevice->CreateDepthStencilView(g_pDepthStencil, &descDSV, &g_pDepthStencilView);
    if (FAILED(hr))
        return hr;

    g_pImmediateContext->OMSetRenderTargets(1, &g_pRenderTargetView, g_pDepthStencilView);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (FLOAT)width;
    vp.Height = (FLOAT)height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    g_pImmediateContext->RSSetViewports(1, &vp);

    m_cVs.loadVS();
    m_cPs.loadPS();

    m_cVs.setVS();
    m_cPs.setPS();

    m_cMeshMgr.load();
    // Initialize the projection matrix
    g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, width / (FLOAT)height, 0.01f, 1000.0f);

    return S_OK;
}

void C_DIRECTX::CleanupDevice()
{
    if (g_pImmediateContext) g_pImmediateContext->ClearState();
    if (g_pDepthStencil) g_pDepthStencil->Release();
    if (g_pDepthStencilView) g_pDepthStencilView->Release();
    if (g_pRenderTargetView) g_pRenderTargetView->Release();
    if (g_pSwapChain) g_pSwapChain->Release();
    if (g_pImmediateContext) g_pImmediateContext->Release();
    if (g_pd3dDevice) g_pd3dDevice->Release();

    m_cMeshMgr.clear();
    m_cVs.clear();
    m_cPs.clear();
}

void C_DIRECTX::Render()
{
    float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; //red, green, blue, alpha
    g_pImmediateContext->ClearRenderTargetView(g_pRenderTargetView, ClearColor);
    g_pImmediateContext->ClearDepthStencilView(g_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);


    for (auto iter = m_mapRenderObject.begin(); iter != m_mapRenderObject.end(); iter++)
    {
        int nRenderId = iter->first;
        C_MESH* pMesh = m_cMeshMgr.getMesh(nRenderId);

        UINT offset = 0;
        g_pImmediateContext->IASetVertexBuffers(0, 1, pMesh->getVertexBuffer(), pMesh->getStride(), &offset);
        g_pImmediateContext->IASetIndexBuffer(pMesh->getIndexBuffer(), pMesh->getIndexFormat(), 0);
        g_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        for (auto iterMat = iter->second.begin(); iterMat != iter->second.end(); iterMat++)
        {
            m_cVs.updateConstBuffer(**iterMat, g_View, g_Projection);
            g_pImmediateContext->DrawIndexed(pMesh->getIndexBufferSize(), 0, 0);
        }
    }

    g_pSwapChain->Present(0, 0);

    clearRenderObject();
}

void* C_DIRECTX::operator new(size_t size)
{
    return _aligned_malloc(size , 16);
}

void C_DIRECTX::operator delete(void* p)
{
    _aligned_free(p);
}

void C_DIRECTX::setRenderObject(int nRenderId, CXMMATRIX mat)
{
    auto iter = m_mapRenderObject.find(nRenderId);
    if (iter == m_mapRenderObject.end())
    {
        std::list<const XMMATRIX*> listMatrix{};
        listMatrix.push_back(&mat);
        m_mapRenderObject.insert({ nRenderId , listMatrix });
    }
    else
        iter->second.push_back(&mat);
}

void C_DIRECTX::setViewMatrix(CXMMATRIX matView)
{
    g_View = matView;
}

void C_DIRECTX::clearRenderObject()
{
    for (auto iter = m_mapRenderObject.begin(); iter != m_mapRenderObject.end(); iter++)
    {
        iter->second.clear();
    }
    m_mapRenderObject.clear();
}

