#include "vs.h"
#include"dxFunc.h"

HRESULT C_VS::loadVS()
{
    ID3DBlob* pVSBlob = NULL;
    
    if (FAILED(C_DXFUNC::CompileShaderFromFile(L"Tutorial05.fx", "VS", "vs_4_0", &pVSBlob)))
        return S_FALSE;

    if (FAILED(C_DXFUNC::getDevice()->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, &g_pVertexShader)))
    {
        pVSBlob->Release();
        return S_FALSE;
    }

    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    UINT numElements = ARRAYSIZE(layout);

    if (FAILED(C_DXFUNC::getDevice()->CreateInputLayout(layout, numElements, pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), &g_pVertexLayout)))
        return S_FALSE;
    pVSBlob->Release();

    if (FAILED(C_DXFUNC::createBuffer(sizeof(ConstantBuffer), D3D11_BIND_CONSTANT_BUFFER, 0, &g_pConstantBuffer)))
        return S_FALSE;

    return S_OK;
}

void C_VS::updateConstBuffer(CXMMATRIX matW , CXMMATRIX matV, CXMMATRIX matP)
{
    ConstantBuffer cb{};
    cb.mWorld = XMMatrixTranspose(matW);
    cb.mView = XMMatrixTranspose(matV);
    cb.mProjection = XMMatrixTranspose(matP);
    C_DXFUNC::getContext()->UpdateSubresource(g_pConstantBuffer, 0, NULL, &cb, 0, 0);
}

void C_VS::clear()
{
    if (g_pConstantBuffer) g_pConstantBuffer->Release();
    if (g_pVertexLayout) g_pVertexLayout->Release();
    if (g_pVertexShader) g_pVertexShader->Release();
}

void C_VS::setVS()
{
    C_DXFUNC::getContext()->IASetInputLayout(g_pVertexLayout);
    C_DXFUNC::getContext()->VSSetShader(g_pVertexShader, NULL, 0);
    C_DXFUNC::getContext()->VSSetConstantBuffers(0, 1, &g_pConstantBuffer);
}
