#include "dxFunc.h"
#include "directX.h"

ID3D11Device* C_DXFUNC::getDevice()
{
    return C_DIRECTX::g_pd3dDevice;
}

ID3D11DeviceContext* C_DXFUNC::getContext()
{
    return C_DIRECTX::g_pImmediateContext;
}

HRESULT C_DXFUNC::createBuffer(UINT size, D3D11_BIND_FLAG bindFlag, void* initData, ID3D11Buffer** ppBuffer)
{
    D3D11_BUFFER_DESC bd{ size , D3D11_USAGE_DEFAULT , bindFlag , 0 ,0,0 };
    D3D11_SUBRESOURCE_DATA InitSubResource{ initData , 0,0 };
    D3D11_SUBRESOURCE_DATA* pSubResource{};
    if (initData)
        pSubResource = &InitSubResource;

    return getDevice()->CreateBuffer(&bd, pSubResource, ppBuffer);
}

HRESULT C_DXFUNC::CompileShaderFromFile(const WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    ID3DBlob* pErrorBlob;
    hr = D3DX11CompileFromFile(szFileName, NULL, NULL, szEntryPoint, szShaderModel,
        dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
    if (FAILED(hr))
    {
        if (pErrorBlob != NULL)
            OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
        if (pErrorBlob) pErrorBlob->Release();
        return hr;
    }
    if (pErrorBlob) pErrorBlob->Release();

    return S_OK;
}
