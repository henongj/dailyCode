#include "ps.h"
#include"dxFunc.h"

HRESULT C_PS::loadPS()
{
    ID3DBlob* pPSBlob = NULL;

    if (FAILED(C_DXFUNC::CompileShaderFromFile(L"Tutorial05.fx", "PS", "ps_4_0", &pPSBlob)))
        return S_FALSE;

    if (FAILED(C_DXFUNC::getDevice()->CreatePixelShader(pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, &g_pPixelShader)))
        return S_FALSE;
    pPSBlob->Release();

    return S_OK;
}

void C_PS::setPS()
{
    C_DXFUNC::getContext()->PSSetShader(g_pPixelShader, NULL, 0);
}

void C_PS::clear()
{
    if (g_pPixelShader) g_pPixelShader->Release();
}
